cmake_minimum_required(VERSION 3.13...3.26)

set(EXEC_NAME AkieMusicPlay)
set(PROJ_NAME Akie_musicplay)

project(${PROJ_NAME})  # 初始化, PROJECT_SOURCE_DIR: 项目源代码的根目录, PROJECT_BINARY_DIR: 项目的构建目录。

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)          ## 取消额外语法
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  ## clang 的相关内容

set(protobuf_DIR "D:/software/DevConfig/vcpkg/installed/x64-windows/share/protobuf")
set(gRPC_DIR "D:/software/DevConfig/vcpkg/installed/x64-windows/share/grpc")

#设置编译模式Debug
SET(CMAKE_BUILD_TYPE "Debug")
# 添加对 gdb 的支持
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# spdlog的部分配置
add_subdirectory(3rdParty/spdlog)
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

# json的cmake部分配置
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(3rdParty/json)

# grpc的cmake部分配置
find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

#Qt相关内容
# 设置Qt路径
set(CMAKE_PREFIX_PATH "D:/software/DevConfig/Qt/6.6.1/msvc2019_64")
# 查找Qt模块
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
#Qt相关开关
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/sample/cpp)
include_directories(${CMAKE_SOURCE_DIR}/sample)
include_directories(${CMAKE_SOURCE_DIR}/test)
include_directories(${CMAKE_SOURCE_DIR}/source)

add_subdirectory(sample)

add_executable(${EXEC_NAME} ${SRC_FILES}  ${SRC_HEADERS} ${TEST_FILES})

# 判断是否成功查找到Qt库
if(Qt6_FOUND)
    message(STATUS "Qt6 libraries found.")
    message(STATUS "Qt6 Concurrent library: ${Qt6Concurrent_LIBRARIES}")
    message(STATUS "Qt6 Core library: ${Qt6Core_LIBRARIES}")
    # 链接Qt库
    target_link_libraries(${EXEC_NAME}  PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
else()
    message(FATAL_ERROR "Qt6 libraries not found. Make sure Qt6 is installed and findable.")
endif()

target_link_libraries(${EXEC_NAME} 
    PRIVATE
    spdlog::spdlog
    nlohmann_json::nlohmann_json
    gRPC::gpr gRPC::grpc gRPC::grpc++ gRPC::grpc++_alts
)

set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${EXEC_NAME})
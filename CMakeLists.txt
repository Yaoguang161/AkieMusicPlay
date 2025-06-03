cmake_minimum_required(VERSION 3.13...3.26)

set(EXEC_NAME AkieMusicPlay)
set(PROJ_NAME Akie_musicplay)

project(${PROJ_NAME})  # 初始化, PROJECT_SOURCE_DIR: 项目源代码的根目录, PROJECT_BINARY_DIR: 项目的构建目录。

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)          ## 取消额外语法
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  ## clang 的相关内容
set_property(GLOBAL PROPERTY USE_FOLDERS ON) #打开允许创建文件夹的开关
# 设置可执行文件输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/output)

# 启用 Qt 自动处理
set(CMAKE_AUTOMOC ON)  # 启用 MOC
set(CMAKE_AUTOUIC ON)  # 启用 UI 自动编译
set(CMAKE_AUTORCC ON)  # 启用资源文件编译

set(protobuf_DIR "D:/software/DevConfig/vcpkg/installed/x64-windows/share/protobuf")
set(gRPC_DIR "D:/software/DevConfig/vcpkg/installed/x64-windows/share/grpc")

#设置编译模式Debug
SET(CMAKE_BUILD_TYPE "Debug")
# # 添加对 gdb 的支持
# SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
# SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

#调用cmake文件夹中的文件
include(${CMAKE_SOURCE_DIR}/cmake/source_file.cmake)

# spdlog的部分配置
find_package(spdlog CONFIG REQUIRED)

# json的cmake部分配置
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(3rdParty/json)

# grpc的cmake部分配置
find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

set(CMAKE_PREFIX_PATH "D:/software/DevConfig/Qt/6.6.1/msvc2019_64")
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
add_subdirectory(sample)

add_executable(${EXEC_NAME} ${SRC_FILES} ${SOURCE_FILES})
target_include_directories(${EXEC_NAME} PRIVATE 
                ${CMAKE_SOURCE_DIR}/include
                ${CMAKE_SOURCE_DIR}/sample/cpp
                ${CMAKE_SOURCE_DIR}/sample
                ${CMAKE_SOURCE_DIR}/test
                ${CMAKE_SOURCE_DIR}/source
)

# 判断是否成功查找到Qt库
if(Qt6_FOUND)
    message(STATUS "Qt6 found.")
    target_link_libraries(${EXEC_NAME}  PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
else()
    message(FATAL_ERROR "Qt6 not found.")
endif()

target_link_libraries(${EXEC_NAME} 
    PRIVATE
    spdlog::spdlog
    nlohmann_json::nlohmann_json
    gRPC::gpr gRPC::grpc gRPC::grpc++ gRPC::grpc++_alts
)

set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${EXEC_NAME})
# 设置源文件目录结构保持
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")
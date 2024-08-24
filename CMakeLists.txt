cmake_minimum_required(VERSION 3.17...3.26)

set(EXEC_NAME AkieMusicPlay)
set(PROJ_NAME Akie_musicplay)

project(${PROJ_NAME})  # 初始化, PROJECT_SOURCE_DIR: 项目源代码的根目录, PROJECT_BINARY_DIR: 项目的构建目录。

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)          ## 取消额外语法
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  ## clang 的相关内容

SET(CMAKE_BUILD_TYPE "Debug")
# 添加对 gdb 的支持
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# 包含 CPM.cmake
include(cmake/CPM.cmake)
# CPM.cmake configuration
CPMAddPackage(
    NAME spdlog
    GITHUB_REPOSITORY gabime/spdlog
    VERSION 1.8.5)

# Alternative use case for another dependency
CPMAddPackage("gh:catchorg/Catch2@2.13.4")

# 引入 gRPC
CPMAddPackage(
  NAME gRPC
  GITHUB_REPOSITORY grpc/grpc
  GIT_TAG v1.54.0  # 使用你需要的 gRPC 版本
)

# 引入 gRPC 
find_package(gRPC REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/sample/cpp)
include_directories(${CMAKE_SOURCE_DIR}/sample)
include_directories(${CMAKE_SOURCE_DIR}/test)
include_directories(${CMAKE_SOURCE_DIR}/source)

add_subdirectory(sample)

# Checks if tests will to be built  构建测试模块
option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
    message("")
    message(STATUS "The project will build the tests.")
    add_subdirectory(tests)
    message("")
    add_executable(${EXEC_NAME} ${TEST_FILES} ${SRC_FILES} ${SRC_HEADERS})
    add_definitions(-DBUILD_TESTS)
else()
    add_executable(${EXEC_NAME} ${SRC_FILES}  ${SRC_HEADERS})
endif(BUILD_TESTS)

#判断有没有找到grpc  ,  GRPC单独使用gRPC_FOND(来自find_package), 不使用gRPC_ADDED(来自于CPM).
if(gRPC_FOUND)
    message(STATUS "gRPC found.")
    # 使用 gRPC 的头文件目录
    include_directories(${gRPC_INCLUDE_DIRS})
    target_link_libraries(${EXEC_NAME} gRPC)
else()
    message(FATAL_ERROR "gRPC not found.")
endif()

if(spdlog_ADDED)
    message(STATUS "spdlog libraries are being linked to ${EXEC_NAME}")
    target_link_libraries(${EXEC_NAME} spdlog)
endif()

if(Catch2_ADDED)
    message(STATUS "Catch2 libraries are being linked to ${EXEC_NAME}")
    target_link_libraries(${EXEC_NAME} Catch2)
endif()

# Assign Main as the startup project of the Solution
set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${EXEC_NAME})

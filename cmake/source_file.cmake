# 递归查找根目录下所有的源文件、头文件和 UI 文件
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS 
    "${CMAKE_SOURCE_DIR}/source/*.cpp"
    "${CMAKE_SOURCE_DIR}/source/*.h"
    "${CMAKE_SOURCE_DIR}/source/*.ui"

    "${CMAKE_SOURCE_DIR}/sample/*.cpp"
    "${CMAKE_SOURCE_DIR}/sample/*.h"
    "${CMAKE_SOURCE_DIR}/sample/*.ui"

    "${CMAKE_SOURCE_DIR}/include/*.cpp"
    "${CMAKE_SOURCE_DIR}/include/*.h"
    "${CMAKE_SOURCE_DIR}/include/*.ui"
)

# 使用 source_group 保留原来的文件目录结构
source_group(TREE ${CMAKE_SOURCE_DIR} FILES ${SOURCE_FILES})

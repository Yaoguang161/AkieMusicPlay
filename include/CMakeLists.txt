# 递归查找所有的头文件
file(GLOB_RECURSE HEADER_FILES
    "*.h"
    "*.hpp"
    "*.hxx"
)

# 将头文件导出到父作用域
set(SRC_HEADERS "${HEADER_FILES}" PARENT_SCOPE)
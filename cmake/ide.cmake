# ---------------------------------------------------------------------------------------
# IDE support for headers
# ---------------------------------------------------------------------------------------
set(HELLO_HEADERS_DIR "${CMAKE_BINARY_DIR}/include")

file(GLOB HELLO_TOP_HEADERS "${HELLO_HEADERS_DIR}/HELLO/*.h")
file(GLOB HELLO_TOP_HEADERS "${HELLO_HEADERS_DIR}/HELLO/*.cpp")
set(HELLO_ALL_HEADERS ${HELLO_TOP_HEADERS})

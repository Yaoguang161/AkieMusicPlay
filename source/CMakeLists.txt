file(GLOB_RECURSE srcs CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
add_library(source STATIC ${srcs})
target_include_directories(source PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

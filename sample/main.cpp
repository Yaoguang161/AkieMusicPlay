#ifndef BUILD_TESTS

#include <iostream>
#include <spdlog/spdlog.h>
#include <grpc++/grpc++.h>
#include "test/hello.h"

int main()
{
    spdlog::warn("Ola povo!");
    spdlog::info("Hello world!");
    std::cout  << "Hello CMake!" << std::endl;
    hello();
    return 0;
}

#endif
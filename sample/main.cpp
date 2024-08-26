#ifndef BUILD_TESTS

#include <iostream>
#include <spdlog/spdlog.h>
#include "test/hello.h"
#include <QApplication>
#include <QWidget>
#include <grpc++/grpc++.h> 
#include <grpcpp/grpcpp.h>

class FirstWindow : public QWidget {
public:
    FirstWindow() {
        setWindowTitle("First Window");
        resize(400, 300);  // 设置窗口大小
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 创建第一个窗口
    FirstWindow window1;
    window1.show();

    // 创建一个 gRPC 通道，指向一个假设的服务器地址
    auto channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());

    if (channel) {
        std::cout << "gRPC channel created successfully!" << std::endl;
    } else {
        std::cout << "Failed to create gRPC channel." << std::endl;
    }

    spdlog::warn("Ola povo!");
    spdlog::info("Hello world!");
    std::cout  << "Hello CMake!" << std::endl;
    hello();
    std::cout << "Hello 1111!" << std::endl;
    return 0;
}

#endif
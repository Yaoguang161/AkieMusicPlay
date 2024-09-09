#ifndef BUILD_TESTS

#include <spdlog/spdlog.h>
#include <QApplication>
#include <QWidget>
#include "hello/hello.h"
#include "help.h"
//#include <grpc++/grpc++.h> 
//#include <grpcpp/grpcpp.h>

class FirstWindow : public QWidget {
public:
    FirstWindow() {
        // 去掉窗口的标题栏和边框
        setWindowFlags(Qt::FramelessWindowHint);
        // 启用高 DPI 支持
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

        // 获取当前设备的像素缩放因子
        qreal pixelRatio = devicePixelRatio();

        // 使用缩放因子来调整窗口的大小
        int logicalWidth = 1842 / pixelRatio;
        int logicalHeight = 1311 / pixelRatio;
        resize(logicalWidth, logicalHeight);  // 设置逻辑像素大小
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 创建第一个窗口
    FirstWindow window1;
    window1.show();

    //// 创建一个 gRPC 通道，指向一个假设的服务器地址
    //auto channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());

    //if (channel) {
    //    std::cout << "gRPC channel created successfully!" << std::endl;
    //} else {
    //    std::cout << "Failed to create gRPC channel." << std::endl;
    //}

    spdlog::warn("Ola povo!");
    spdlog::info("Hello world!");
    std::cout  << "Hello CMake!" << std::endl;
    hello();
    std::cout << "Hello 1111!" << std::endl;
    return app.exec();  // 确保窗口显示直到关闭;
}

#endif
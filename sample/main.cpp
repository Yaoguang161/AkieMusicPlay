#ifndef BUILD_TESTS

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <grpc++/grpc++.h> 
#include <grpcpp/grpcpp.h>

#include "MainPage/mainWidget.h"
#include "hello/hello.h"
#include "music/help.h"

#include <QApplication>
#include <QDir>

int main(int argc, char *argv[])
{
    hello();
    // 设置日志级别
    spdlog::set_level(spdlog::level::debug); // 设置全局日志级别为 debug
    // 设置日志输出格式
    spdlog::set_pattern("%^[%T] %n: %v%$");

    SPDLOG_INFO("Hello, this is an info message.");
    SPDLOG_WARN("This is a warning.");
    SPDLOG_ERROR("An error occurred: {}", "example error");
    SPDLOG_CRITICAL("This is a critical message.");
    SPDLOG_DEBUG("This is a debug message."); // 需要设置为 debug 等级才会显示

    qDebug() << "Current working directory:" << QDir::currentPath();   //"E:/software/Code/AkieMusicPlay/build" 当前程序运行目录

    QApplication app(argc, argv);

    mainWidget window;
    window.show();

    return app.exec();
}

#endif
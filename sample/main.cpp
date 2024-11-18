#ifndef BUILD_TESTS

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <grpc++/grpc++.h> 
#include <grpcpp/grpcpp.h>

#include "MainPage/mainWidget.h"
#include "hello/hello.h"
#include "music/help.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    hello();
    // 创建一个带有颜色输出的控制台日志器
    auto console = spdlog::stdout_color_mt("console");
    console->set_pattern("%^[%T] %n: %v%$"); // 设置输出格式

    // 打印日志信息
    console->info("Hello, this is an info message.");
    console->warn("This is a warning message.");
    console->error("An error occurred: {}", "example error");
    console->critical("This is a critical message.");

    // 使用不同的日志级别
    console->debug("This debug message will only show if the log level is set to debug.");

    // 设置日志级别
    spdlog::set_level(spdlog::level::debug); // 设置全局日志级别为 debug
    console->debug("Now this debug message is visible.");


    QApplication app(argc, argv);

    mainWidget window;
    window.show();

    return app.exec();
}

#endif
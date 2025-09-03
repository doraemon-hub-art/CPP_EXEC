#include <iostream>
#include <sdbus-c++/sdbus-c++.h>
#include "proxy.hpp"

int main()
{
    // 连接到 session bus
    auto connection = sdbus::createSessionBusConnection();

    // 创建底层 proxy
    auto rawProxy = sdbus::createProxy(*connection, "com.example.Demo", "/com/example/Demo");

    // 用 MyDemoProxy 封装它
    MyDemoProxy proxy(*rawProxy);

    // 调用 Echo 方法
    std::string reply = proxy.Echo("Hello D-Bus!");
    std::cout << "Echo reply: " << reply << std::endl;

    // 读取属性 Counter
    int counter = proxy.Counter();
    std::cout << "Counter value: " << counter << std::endl;

    std::cout << "Listening for Tick signals..." << std::endl;

    // 进入事件循环，等待信号
    connection->enterEventLoop();

    return 0;
}

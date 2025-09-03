#include <sdbus-c++/sdbus-c++.h>
#include <iostream>
#include "../server/interface/com.example.Demo_proxy.h"   // 引入自动生成的 proxy 头文件

int main()
{
    using namespace std;

    // 连接 session bus
    auto connection = sdbus::createSessionBusConnection();

    // 创建 proxy
    auto proxy = com::example::createDemoProxy(*connection, "com.example.Demo", "/com/example/Demo");

    // 调用 Echo 方法
    string reply = proxy->Echo("Hello D-Bus!");
    cout << "Echo reply: " << reply << endl;

    // 读取属性 Counter
    int counter = proxy->Counter();
    cout << "Counter value: " << counter << endl;

    // 订阅 Tick 信号
    proxy->uponSignalTick([](int value) {
        cout << "Received Tick signal: " << value << endl;
    });

    // 注册信号回调
    proxy->finishRegistration();

    cout << "Listening for Tick signals..." << endl;

    // 进入事件循环（阻塞，等待信号）
    connection->enterEventLoop();

    return 0;
}
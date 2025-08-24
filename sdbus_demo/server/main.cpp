#include "adapter.hpp"
#include <sdbus-c++/sdbus-c++.h>

int main() {
    auto connection = sdbus::createSessionBusConnection();
    connection->requestName("com.example.Demo");

    DemoService service(*connection, "/com/example/Demo");

    connection->enterEventLoop();  // 阻塞循环
}

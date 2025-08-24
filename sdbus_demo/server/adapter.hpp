#include "com.example.Demo_adaptor.h"
#include <sdbus-c++/sdbus-c++.h>
#include <iostream>

class DemoService : public com::example::Demo_adaptor {
public:
    DemoService(sdbus::IConnection& connection, std::string objectPath)
        : com::example::Demo_adaptor(connection, std::move(objectPath)) {}

    // 重写 Echo 方法
    std::string Echo(const std::string& msg) override {
        return "echo: " + msg;
    }

    // 属性 getter
    int32_t Counter() override {
        return counter_;
    }

    void sendTick(int value) {
        emitTick(value);
        counter_ = value;
    }

private:
    int32_t counter_{0};
};

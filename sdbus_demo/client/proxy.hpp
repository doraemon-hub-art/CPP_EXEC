#pragma once

#include <iostream>
#include <sdbus-c++/sdbus-c++.h>
#include "../server/interface/com.example.Demo_proxy.h"

// 继承自动生成的 Demo_proxy，实现信号处理
class MyDemoProxy : public com::example::Demo_proxy
{
public:
    explicit MyDemoProxy(sdbus::IProxy& proxy)
        : Demo_proxy(proxy)
    {}

protected:
    // Tick 信号回调
    void onTick(const int32_t& value) override
    {
        std::cout << "Received Tick signal: " << value << std::endl;
    }
};

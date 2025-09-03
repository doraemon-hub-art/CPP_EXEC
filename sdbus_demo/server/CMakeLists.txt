# 必须指定cmake最小版本
cmake_minimum_required(VERSION 3.15)
# 工程名字
project(dbus_server_demo)

# C++标准
set(CMAKE_CXX_STANDARD 17)
# 
find_package(sdbus-c++ REQUIRED)


add_subdirectory(interface)

add_executable(dbus_service_demo service.cpp)
target_link_libraries(dbus_service PRIVATE sdbus-c++::sdbus-c++)

cmake_minimum_required(VERSION 3.10)
project(sdbus_client)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDBUSCPP REQUIRED sdbus-c++)

include_directories(${SDBUSCPP_INCLUDE_DIRS} ../server/interface)

add_executable(client main.cpp)
target_link_libraries(client ${SDBUSCPP_LIBRARIES})

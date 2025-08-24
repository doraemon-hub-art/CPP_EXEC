cmake_minimum_required(VERSION 3.10)
project(MyCppPractice LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找当前目录下所有 .cpp 文件
file(GLOB SRC_FILES src/*.cpp)

# 为每个 .cpp 创建一个独立的可执行文件
foreach(src_file ${SRC_FILES})
    get_filename_component(target_name ${src_file} NAME_WE) # 获取文件名（无扩展名）
    add_executable(${target_name} ${src_file})
endforeach()

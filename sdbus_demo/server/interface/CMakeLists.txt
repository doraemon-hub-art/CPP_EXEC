add_library(demo_interface STATIC
    com.example.Demo_adaptor.h
    com.example.Demo_proxy.h
)
target_include_directories(demo_interface PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

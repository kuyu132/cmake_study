cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(recipe-03 LANGUAGES CXX)

add_library(message-objs
        OBJECT
        Message.hpp
        Message.cpp)

#设置了message-objs的目标属性，将POSITION_INDEPENDENT_CODE属性设置为1，表示生成位置独立的代码。
set_target_properties(message-objs
        PROPERTIES
        POSITION_INDEPENDENT_CODE 1)

add_library(message-shared
        SHARED
        $<TARGET_OBJECTS:message-objs>)

set_target_properties(message-shared
        PROPERTIES
        OUTPUT_NAME "message"
        )

add_library(message-static
        STATIC
        $<TARGET_OBJECTS:message-objs>
        )
set_target_properties(message-static
        PROPERTIES
        OUTPUT_NAME "message")

add_executable(hello-world hello-world.cpp)

target_link_libraries(hello-world message-static)
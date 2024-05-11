cmake_minimum_required(VERSION 3.27)
project(lesson3_1)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(common)
add_subdirectory(add)
add_subdirectory(sub)
add_subdirectory(calculator)

add_executable(lesson3_1 main.cpp)
#头文件定义
target_include_directories(lesson3_1 PRIVATE calculator)
#库链接
target_link_libraries(lesson3_1 common add sub calculator)

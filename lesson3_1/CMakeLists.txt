cmake_minimum_required(VERSION 3.27)
project(lesson3_1)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(common)
#下面target_link_libraries可以把add、sub去掉，在calculator里面已经链接了，但这个add_subdirectory添加add和sub不能去掉
#在calculator不能add_subdirectory添加add和sub两个目录，这个待优化（TODO）
add_subdirectory(add)
add_subdirectory(sub)
add_subdirectory(calculator)

add_executable(lesson3_1 main.cpp)
#头文件定义
target_include_directories(lesson3_1 PRIVATE calculator)
#库链接
target_link_libraries(lesson3_1 common calculator)

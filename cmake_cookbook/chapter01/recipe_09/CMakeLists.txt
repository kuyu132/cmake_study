cmake_minimum_required(VERSION 3.27)
project(recipe_09)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(animals
        SHARED
        Animal.cpp
        Animal.hpp
        Cat.cpp
        Cat.hpp
        Dog.cpp
        Dog.hpp
        Factory.hpp)

#可以使用 target_compile_features() 命令要求为特定的目标提供特定的特性，CMake将自动为标准设置正确的编译器标志
set_target_properties(animals
        PROPERTIES
        CXX_STANDARD 14
        # 告诉CMake，只启用 ISO C++ 标准的编译器标志，而不使用特定编译器的扩展。
        CXX_EXTENSIONS OFF
        # 指定所选标准的版本。如果这个版本不可
        #用，CMake将停止配置并出现错误。当这个属性被设置为 OFF 时，CMake
        #将寻找下一个标准的最新版本，直到一个合适的标志。这意味着，首先查
        #找 C++14 ，然后是 C++11 ，然后是 C++98 。（译者注：目前会
        #从 C++20 或 C++17 开始查找）
        CXX_STANDARD_REQUIRED ON
        #POSITION_INDEPENDENT_CODE（位置无关代码，PIC）是一种编程技术，
        #使生成的机器代码能够在内存中的任何位置执行，而不需要在编译时知道具体的内存地址。
        #这种技术通常用于创建共享库（shared libraries）和动态链接库（DLLs），因为这些库可能会被加载到不同的内存地址。
        POSITION_INDEPENDENT_CODE 1
)

add_executable(recipe_09
        animal-farm.cpp)

set_target_properties(recipe_09
        PROPERTIES
        CXX_STANDARD 17
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON)

target_link_libraries(recipe_09 animals)
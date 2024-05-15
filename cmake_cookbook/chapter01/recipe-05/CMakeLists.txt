cmake_minimum_required(VERSION 3.5)

project(recipe-05 LANGUAGES CXX)

option(USE_LIBRARY "compile sources into a library" OFF)

message(STATUS "Compile sources into a library? ${USE_LIBRARY}")

#引入CMakeDependentOption模块，通过cmake --help-module CMakeDependentOption查看帮助信息
include(CMakeDependentOption)

cmake_dependent_option(
        MAKE_STATIC_LIBRARY "Compile sources into a static library" OFF
        "USE_LIBRARY" ON
)

cmake_dependent_option(
        MAKE_SHARED_LIBRARY "Compile sources into a shared library" ON
        "USE_LIBRARY" ON
)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS on)

LIST(APPEND _sources Message.hpp Message.cpp)

if (USE_LIBRARY)
    message(STATUS "Compile sources into a STATIC library? ${MAKE_STATIC_LIBRARY}")
    message(STATUS "Compile sources into a SHARED library? ${MAKE_SHARED_LIBRARY}")

    #使用3种方式：1.静态库；2.动态库；3.源码
    if (MAKE_STATIC_LIBRARY)
        add_library(message STATIC ${sources})

        add_executable(hello-world hello-world.cpp)

        target_link_libraries(hello-world message)
    endif ()

    if (MAKE_SHARED_LIBRARY)
        add_library(message SHARED ${_sources})

        add_executable(hello-world hello-world.cpp)

        target_link_libraries(hello-world message)
    endif ()
else ()
    add_executable(hello-world hello-world.cpp ${_sources})
endif ()
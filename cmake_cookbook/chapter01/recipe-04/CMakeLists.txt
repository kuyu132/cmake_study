cmake_minimum_required(VERSION 3.20)
project(recipe_04)

set(CMAKE_CXX_STANDARD 14)

SET(USE_LIBRARY OFF)

message(STATUS "Compile sources into a library? ${USE_LIBRARY}")

SET(BUILD_SHARED_LIBS ON)

#添加资源到list
list(APPEND _sources Message.hpp Message.cpp)

if (BUILD_SHARED_LIBS)
    add_library(message ${_sources})

    add_executable(recipe_04 hello-world.cpp)
    target_link_libraries(recipe_04 message)
else ()
    add_executable(recipe_04 hello-world.cpp ${_sources})
endif ()



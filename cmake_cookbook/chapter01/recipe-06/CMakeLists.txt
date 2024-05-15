cmake_minimum_required(VERSION 3.20)
project(recipe_06)

set(CMAKE_CXX_STANDARD 14)

message(STATUS "Is the c++ compiler loaded? ${CMAKE_CXX_COMPILER_LOADED}")

#通过命令指定编译器：cmake -D CMAKE_CXX_COMPILER=clang++ ..
if (CMAKE_CXX_COMPILER_LOADED)
    message(STATUS "The c++ compiler ID is: ${CMAKE_CXX_COMPILER_ID}")
    message(STATUS "Is the c++ from GNU? ${CMAKE_COMPILER_IS_GNUCXX}")
    message(STATUS "The c++ compiler version is ${CMAKE_CXX_COMPILER_VERSION}")
endif ()

message(STATUS "Is the c compiler loaded? ${CMAKE_C_COMPILER_LOADED}")

if (CMAKE_C_COMPILER_LOADED)
    message(STATUS "The c compiler id is: ${CMAKE_C_COMPILER_ID}")
    message(STATUS "Is the c from GNU? ${CMAKE_COMPILER_IS_GNUCC}")
    message(STATUS "The c compiler version is: ${CMAKE_C_COMPILER_VERSION}")
endif ()

add_executable(recipe_06 main.cpp)

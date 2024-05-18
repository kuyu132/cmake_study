cmake_minimum_required(VERSION 3.27)
project(recipe_07)

set(CMAKE_CXX_STANDARD 17)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE  Release CACHE STRING "Build type" FORCE)
endif ()

#cmake -D CMAKE_BUILD_TYPE=Debug ..
#通过指定编译的类型控制产物，默认为release
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

message(STATUS "C flags, Debug Configuration: ${CMAKE_C_FLAGS_DEBUG}")
message(STATUS "C flags, Release Configuration: ${CMAKE_C_FLAGS_RELEASE}")
message(STATUS "C flags, Release Configuration with Debug info: ${CAMKE_C_FLAGS_RELWITHDEBINFO}")
message(STATUS "C flags, minimal Release configuration: ${CMAKE_C_FLAGS_MINSIZEREL}")

message(STATUS "c++ flags, Debug configuration: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "c++ flags, Release configuration: ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "c++ flags, Release configuration with Debug info: ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
message(STATUS "c++ flags, minimal Release configuration: ${CMAKE_CXX_FLAGS_MINSIZEREL}")

add_executable(recipe_07 main.cpp)

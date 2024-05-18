cmake_minimum_required(VERSION 3.27)
project(recipe_08)

set(CMAKE_CXX_STANDARD 17)

message(STATUS "C++ compiler flags: ${CMAKE_CXX_FLAGS}")

set(COMPILER_FLAGS)
set(COMPILER_FLAGS_DEBUG)
set(COMPILER_FLAGS_RELEASE)

if (CMAKE_CXX_COMPILER_ID MATCHES GNU)
    message(STATUS "CMAKE c++ compiler id is gnu")
    list(APPEND CXX_FLAGS "-fno-rtti" "-fno-exceptions")
    list(APPEND CXX_FLAGS_DEBUG "-Wsuggest-final-types" "-Wsuggest-final-methods" "-Wsuggest-override")
    list(APPEND CXX_FLAGS_RELEASE "-O3" "-Wno-unused")
endif ()

if (CMAKE_CXX_COMPILER_ID MATCHES Clang)
    message(STATUS "CMAKE c++ compiler id is Clang")
    list(APPEND CXX_FLAGS "-fno-rtti" "-fno-exceptions" "-Qunused-arguments" "-fcolor-diagnostics")
    list(APPEND CXX_FLAGS_DEBUG "-Wdocumentation")
    list(APPEND CXX_FLAGS_RELEASE "-O3" "-Wno-unused")
endif ()

add_library(geometry STATIC
        ../geometry_circle.cpp
        ../geometry_circle.hpp
        ../geometry_polygon.cpp
        ../geometry_polygon.hpp
        ../geometry_rhombus.cpp
        ../geometry_rhombus.hpp
        ../geometry_square.cpp
        ../geometry_square.hpp
)

#同时指定debug和release两种编译配置
target_compile_options(geometry
        PRIVATE
        ${CXX_FLAGS}
        "$<$<CONFIG:Debug>:${CXX_FLAGS_DEBUG}>"
        "$<$<CONFIG:Release>:${CXX_FLAGS_RELEASE}>"
)

add_executable(recipe_08 ../compute-areas.cpp)

target_compile_options(recipe_08 PRIVATE
        ${CXX_FLAGS}
        "$<$<CONFIG:Debug>:${CXX_FLAGS_DEBUG}>"
        "$<$<CONFIG:Release>:${CXX_FLAGS_RELEASE}>")

target_link_libraries(recipe_08 geometry)

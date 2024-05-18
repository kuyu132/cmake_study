cmake_minimum_required(VERSION 3.27)
project(recipe_08)

set(CMAKE_CXX_STANDARD 17)

message(STATUS "C++ compiler flags: ${CMAKE_CXX_FLAGS}")

list(APPEND flags "-fPIC" "-Wall")
if (NOT WIN32)
    LIST(APPEND flags "-Wextra" "-Wpedantic")
endif ()

add_library(geometry STATIC
        geometry_circle.cpp
        geometry_circle.hpp
        geometry_polygon.cpp
        geometry_polygon.hpp
        geometry_rhombus.cpp
        geometry_rhombus.hpp
        geometry_square.cpp
        geometry_square.hpp
)

target_compile_options(geometry
        PRIVATE
        ${flags}
)
#编译指令为：cmake --build . -- VERBOSE=1
#在编译指令中可以再加flags，比如：cmake -D CMAKE_CXX_FLAGS="-fno-exceptions -fno-rtti" ..
#将-fno-exceptions -fno-rtti和上面的flags一起作为标志进行编译
add_executable(recipe_08 compute-areas.cpp)

target_compile_options(recipe_08 PRIVATE ${flags})
target_link_libraries(recipe_08 geometry)

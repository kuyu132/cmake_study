cmake_minimum_required(VERSION 3.27)
project(recipe_10)

set(CMAKE_CXX_STANDARD 17)

add_library(geometry
        STATIC
        geometry_circle.cpp
        geometry_circle.hpp
        geometry_polygon.cpp
        geometry_polygon.hpp
        geometry_rhombus.cpp
        geometry_rhombus.hpp
        geometry_square.cpp
        geometry_square.hpp
)

#整体使用-O3优化
target_compile_options(geometry
        PRIVATE
        -O3)

#其中的两项使用-O2优化
list(APPEND sources_with_lower_optimization
        geometry_circle.cpp
        geometry_rhombus.cpp)

message(STATUS "Setting source properties using IN LISTS syntax:")
#foreach(loop_var arg1 arg2 ...)，使用了变量，必须显示展开
foreach (_source IN LISTS sources_with_lower_optimization)
    set_source_files_properties(${_source} PROPERTIES COMPILE_FLAGS -O2)
    message(STATUS "Appending -O2 flag for ${_source}")
endforeach ()

message(STATUS "Query sources properties using plain syntax:")
foreach (_source ${sources_with_lower_optimization})
    #将获取的属性存放在_flags中
    get_source_file_property(_flags ${_source} COMPILE_FLAGS)
    message(STATUS "${_source} has the following extra COMPILE_FLAGS: ${_flags}")
endforeach ()

add_executable(recipe_10 compute-areas.cpp)
target_link_libraries(recipe_10 geometry)

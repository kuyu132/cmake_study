#add_subdirectory(../add)

#add_subdirectory(../sub)

add_library(calculator STATIC calculator.cpp)
target_include_directories(calculator PUBLIC ./)
target_link_libraries(calculator PRIVATE add sub)
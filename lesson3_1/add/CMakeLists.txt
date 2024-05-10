add_library(add STATIC add.cpp)
target_include_directories(add PRIVATE ../common)

#下面的写法不生效，common无法链接到add中
#target_link_libraries(add PRIVATE common)
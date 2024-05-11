add_library(add STATIC add.cpp)
#target_include_directories(add PRIVATE ../common)

# 这种写法的common的头文件在add里面生效，也在calculator里面生效
target_include_directories(add PUBLIC ../common)

#下面的写法不生效，common无法链接到add中
#target_link_libraries(add PRIVATE common)
add_library(add STATIC add.cpp)
#common这里的common是一个target，包含实现和头文件两部分
target_link_libraries(add PRIVATE common)
target_include_directories(add INTERFACE ./)
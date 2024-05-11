add_library(common STATIC common.cpp)
#将自己的common.h头文件给依赖common的库用，比如add，那边直接target_link_libraries到common即可
#如果将INTERFACE改成PRIVATE，则外部的无法使用
target_include_directories(common INTERFACE ./)
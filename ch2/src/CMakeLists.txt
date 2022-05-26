# 声明要求的cmake最低版本
cmake_minimum_required( VERSION 2.8 )

# 声明一个cmake工程
project( helloSLAM )

# 设置编译模式
set( CMAKE_BUILD_TYPE "Debug")

# 添加一个静态库
# add_library( hello lib_helloslam.cpp )

# 添加一个动态库
add_library( hello_shared SHARED lib_helloslam.cpp )

# 添加一个可执行程序
# 语法：add_executable( 程序名 源代码文件 )
add_executable( use_lib use_lib.cpp)

# 将库文件链接到可执行程序
target_link_libraries( use_lib hello_shared ) 

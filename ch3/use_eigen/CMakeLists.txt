cmake_minimum_required( VERSION 2.8 )
project( use_eigen )

set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_FLAGS "-O3" )

# 添加Eigen头文件
include_directories("/usr/local/include/eigen3")

add_executable( eigen_matrix eigen_matrix.cpp )

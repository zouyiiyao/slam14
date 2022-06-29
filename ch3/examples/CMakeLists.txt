set(CMAKE_CXX_FLAGS "-std=c++11")

include_directories("usr/local/include/eigen3")
add_executable(coordinate_transform coordinate_transform.cpp)

find_package(Pangolin REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})
add_executable(plot_trajectory plot_trajectory.cpp)
target_link_libraries(plot_trajectory ${Pangolin_LIBRARY})
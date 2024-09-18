cmake_minimum_required(VERSION 3.4)
project(example)

# Find pybind11
find_package(pybind11 REQUIRED)

add_executable(example example.cpp)

# Link pybind11 and Python libraries
target_link_libraries(example PRIVATE pybind11::embed)

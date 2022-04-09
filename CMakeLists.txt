cmake_minimum_required (VERSION 3.15)
project (profiler)

add_executable(regular src/example_regular.cpp)
add_executable(continuous src/example_continuous.cpp)
target_include_directories(regular PUBLIC include)
target_include_directories(continuous PUBLIC include)
cmake_minimum_required(VERSION 3.28)
project(pendulum)
add_executable(pendulum src/main.cpp)

target_link_libraries(pendulum SDL2)

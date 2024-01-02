cmake_minimum_required(VERSION 3.28)
project(pendulum)
add_executable(pendulum src/main.cpp)

target_link_libraries(pendulum glfw3)
target_link_libraries(pendulum X11)
target_link_libraries(pendulum GL)

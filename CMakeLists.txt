cmake_minimum_required(VERSION 3.18)
project(queue C)

set(CMAKE_C_STANDARD 11)

add_executable(queue main.c queue.c queue.h)
cmake_minimum_required(VERSION 4.3)
project(cpp_concurrency)

set(CMAKE_CXX_STANDARD 23)

add_executable(cpp_concurrency main.cpp
        thread_guard.h
)

cmake_minimum_required(VERSION 4.3)
project(cpp_concurrency)

set(CMAKE_CXX_STANDARD 23)

add_executable(cpp_concurrency main.cpp
        thread_guard.h
        scoped_thread.h
        scoped_thread.h
        lock_guard.h
        scoped_lock.h
        shared_lock.h
        spinlock_mutex.h
        spinlock_mutex.h
)

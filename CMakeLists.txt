cmake_minimum_required(VERSION 3.16.3)
project(MemCheck_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(MemCheck_1 main.cpp
        task.cpp
        task.h
        taskList.cpp
        taskList.h)

cmake_minimum_required(VERSION 3.27)
project(bug_life_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(bug_life_project main.cpp
        bug.cpp
        bug.h
        crawler.cpp
        crawler.h
        hopper.cpp
        hopper.h)

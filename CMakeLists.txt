cmake_minimum_required(VERSION 3.29)
project(Algorithms_Implementation)

set(CMAKE_CXX_STANDARD 20)

add_executable(Algorithms_Implementation main.cpp
        DataStructures/header/Array.h
        DataStructures/header/Heap.h
        Problems/Add_All.cpp
        Problems/Problems.h)

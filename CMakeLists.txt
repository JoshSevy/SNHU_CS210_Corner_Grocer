cmake_minimum_required(VERSION 3.31)
project(CornerGrocerJCS)

set(CMAKE_CXX_STANDARD 20)

add_executable(CornerGrocerJCS src/main.cpp
        src/GroceryTracker.cpp
        src/GroceryTracker.h
        src/Menu.cpp
        src/Menu.h
        src/Utils.cpp
        src/Utils.h)

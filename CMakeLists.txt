cmake_minimum_required(VERSION 3.27)
project(extra2)

set(CMAKE_CXX_STANDARD 17)

add_executable(extra2 main.cpp
        Size.cpp
        Size.h
        Point.cpp
        Point.h
        Rectangle.cpp
        Rectangle.h
        Image.cpp
        Image.h
        ImageProcessing.cpp
        ImageProcessing.cpp
        ImageProcessing.h
        Drawing.cpp
        Drawing.h)

cmake_minimum_required(VERSION 3.26)
project(Matrix)

set(CMAKE_CXX_STANDARD 23)

add_executable(Matrix main.cpp
        symbol.cpp
        symbol.h
        Manager.cpp
        Manager.h
        Line.cpp
        Line.h
        Extension.cpp
        Extension.h
        Vector2.cpp
        Vector2.h
        Figure.cpp
        Figure.h
        Explosion.cpp
        Explosion.h)

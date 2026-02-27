cmake_minimum_required(VERSION 4.0)
project(DroniAssassini)

set(CMAKE_CXX_STANDARD 20)

add_executable(DroniAssassini main.cpp
        Drone.cpp
        Drone.h
        DronesManager.cpp
        DronesManager.h)

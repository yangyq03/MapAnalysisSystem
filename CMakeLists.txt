cmake_minimum_required(VERSION 3.25)
project(MapAnalysisSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(MapAnalysisSystem main.cpp FileHandler.cpp FileHandler.h FileHandler.h Road.cpp Road.h)

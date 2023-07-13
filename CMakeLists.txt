cmake_minimum_required(VERSION 3.25)
project(MapAnalysisSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(MapAnalysisSystem main.cpp BinaryFileHandler.cpp BinaryFileHandler.h BinaryFileHandler.h Road.cpp Road.h Menu.cpp Menu.h SortUtil.cpp SortUtil.h DataFileHandler.cpp DataFileHandler.h)

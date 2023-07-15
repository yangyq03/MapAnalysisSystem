cmake_minimum_required(VERSION 3.25)
project(MapAnalysisSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(MapAnalysisSystem main.cpp BinaryFileHandler.cpp Road.cpp MainActivity.cpp SortUtil.cpp DataFileHandler.cpp SearchAndModifyUtils.cpp PrintUtil.cpp)

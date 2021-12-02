cmake_minimum_required(VERSION 3.21)
project(RaceWinnerCalculator)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

add_executable(RaceWinnerCalculator main.cpp src/timeUtils.cpp src/KartPassingTimeCsvParser.cpp)

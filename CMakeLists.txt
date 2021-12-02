cmake_minimum_required(VERSION 3.21)
project(RaceWinnerCalculator)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

file(GLOB src_files
         src/timeUtils.cpp src/KartPassingTimeCsvParser.cpp)

if (UNIT_TESTING)
    add_subdirectory(tests)
else ()
    add_executable(RaceWinnerCalculator main.cpp ${src_files})
endif ()

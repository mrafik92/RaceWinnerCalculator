cmake_minimum_required(VERSION 3.16)
project(RaceWinnerCalculatorUnitTest)


add_definitions(-DUNIT_TESTING_ENABLED)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(tests/)

add_executable(
        RaceWinnerCalcTest
        ${src_files}
        WinnerClassTest.cpp KartTimeCsvParserTest.cpp)

target_link_libraries(
        RaceWinnerCalcTest
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(RaceWinnerCalcTest)
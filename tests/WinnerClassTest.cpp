//
// Created by mrafik on 11/29/21.
//

#include "WinnerClassTest.h"
#include "gtest/gtest.h"

TEST_F(WinnerCalculatorTest, testWinner)
{
    std::vector<KartPassingTime> mKarts{};

    mKarts.emplace_back(1,1);
    mKarts.emplace_back(2,2);
    mKarts.emplace_back(1,10);
    mKarts.emplace_back(2,11);

    winnerCalculator = std::make_shared<WinnerCalculator>(mKarts);

    auto timesPerKart = winnerCalculator->calculateLapTimesPerKart();
    ASSERT_EQ(2, timesPerKart.size());
}

TEST_F(WinnerCalculatorTest, testMultipleWinners)
{
    std::vector<KartPassingTime> mKarts{};

    mKarts.emplace_back(1,1);
    mKarts.emplace_back(2,2);
    mKarts.emplace_back(3,2);
    mKarts.emplace_back(1,10);
    mKarts.emplace_back(2,11);
    mKarts.emplace_back(3,13);
    mKarts.emplace_back(3,25);

    winnerCalculator = std::make_shared<WinnerCalculator>(mKarts);

    auto winners = winnerCalculator->calculateWinner();
    ASSERT_EQ(2, winners.size());
}
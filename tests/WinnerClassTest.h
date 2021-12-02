//
// Created by mrafik on 11/29/21.
//

#ifndef RACEWINNERCALCULATOR_WINNERCLASSTEST_H
#define RACEWINNERCALCULATOR_WINNERCLASSTEST_H

#include "WinnerCalculator.h"
#include "gtest/gtest.h"


class WinnerCalculatorTest : public ::testing::Test
{

public:
    WinnerCalculatorTest() = default;

    std::shared_ptr<WinnerCalculator> winnerCalculator{};

};

#endif  // RACEWINNERCALCULATOR_WINNERCLASSTEST_H

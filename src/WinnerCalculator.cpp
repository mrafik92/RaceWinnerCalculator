 //
// Created by mrafik on 11/28/21.
//

#include "../include/WinnerCalculator.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include "timeUtils.h"

std::map<int, std::vector<long>>
WinnerCalculator::calculateLapTimesPerKart()
{
    std::sort(mKartTimes.begin(), mKartTimes.end());
    for (const auto& kartTime : mKartTimes) {
        mTimesPerKart[kartTime.getKartId()].push_back(kartTime.getPassTime());
    }
    return mTimesPerKart;
}

int
WinnerCalculator::calculateTotalNumberOfLaps()
{
    std::map<int, int> mLapsPerUser{};

    for (const auto& timesPerKart : mTimesPerKart) {
        mLapsPerUser[timesPerKart.first] = (int)timesPerKart.second.size();
    }

    auto maxNumberOfLaps = std::max_element(mLapsPerUser.begin(),
                                            mLapsPerUser.end(),
                                            [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
                                                return p1.second < p2.second;
                                            })
                                   ->second;

    std::cout << "total number of laps: " << maxNumberOfLaps - 1 << std::endl;

    mTotalNumberOfLaps = maxNumberOfLaps;
    return mTotalNumberOfLaps;
}

long
WinnerCalculator::calculateRaceFinishTime()
{
    auto finishTime = std::min_element(
            mTimesPerKart.begin(),
            mTimesPerKart.end(),
            [=](const std::pair<int, std::vector<long>>& p1, const std::pair<int, std::vector<long>>& p2) {
                if (p1.second.size() < mTotalNumberOfLaps)
                    return false;
                if (p2.second.size() < mTotalNumberOfLaps)
                    return true;
                return p1.second[mTotalNumberOfLaps - 1] < p2.second[mTotalNumberOfLaps - 1];
            });


    mFinishTimeInSeconds = mTimesPerKart[finishTime->first][mTotalNumberOfLaps - 1];

    std::cout << "race finish Time: " << time_utils::getTimeFormatted(mFinishTimeInSeconds) << " by "
              << finishTime->first << std::endl;

    return mFinishTimeInSeconds;
}

void
WinnerCalculator::calculateEffectiveLapTimes()
{

    for (auto& secondsPerKart : mTimesPerKart) {
        std::vector<long>& secondsVector = secondsPerKart.second;
        if (secondsVector.size() == mTotalNumberOfLaps) {
            if (secondsVector[mTotalNumberOfLaps - 1] > mFinishTimeInSeconds) {
                secondsVector.erase(secondsVector.begin() + mTotalNumberOfLaps - 1);
            }
        }
        std::adjacent_difference(
                secondsPerKart.second.begin(), secondsPerKart.second.end(), secondsPerKart.second.begin());
    }
}

std::vector<std::pair<int, long>>
WinnerCalculator::getBestLapTime()
{
    std::vector<std::pair<int, long>> mBestLapsPerKart{};

    mBestLapsPerKart.reserve(mTimesPerKart.size());

    printTimings();
    for (const auto& lapsTimings : mTimesPerKart) {
        long minimumLap = *std::min_element(lapsTimings.second.begin() + 1, lapsTimings.second.end());
        if (minimumLap != 0) {
            mBestLapsPerKart.emplace_back(lapsTimings.first, minimumLap);
        }
    }

    auto minimumLap = std::min_element(mBestLapsPerKart.begin(),
                                       mBestLapsPerKart.end(),
                                       [](const std::pair<int, long>& p1, const std::pair<int, long>& p2) {
                                           return p1.second < p2.second;
                                       });

    std::vector<std::pair<int, long>> mWinners{};

    for (const auto& lapsPerKart : mBestLapsPerKart) {
        if (lapsPerKart.second == minimumLap->second) {
            mWinners.push_back(lapsPerKart);
        }
    }

    for (const auto& lapsPerKart : mBestLapsPerKart) {
        std::cout << "Best Lap of " << lapsPerKart.first << " is " << time_utils::getTimeFormatted(lapsPerKart.second)
                  << std::endl;
    }

    std::cout << "Winners are ";
    for (const auto& lapsPerKart : mWinners) {
        std::cout << lapsPerKart.first << " ";
    }
    std::cout << std::endl;

    return mWinners;
}

std::vector<std::pair<int, std::string>>
WinnerCalculator::calculateWinner()
{
    calculateLapTimesPerKart();
    calculateTotalNumberOfLaps();
    calculateRaceFinishTime();
    calculateEffectiveLapTimes();
    auto winners = getBestLapTime();

    std::vector<std::pair<int, std::string>> winnersFormatted{};
    winnersFormatted.reserve(winners.size());
    for (const auto & winner : winners) {
        winnersFormatted.emplace_back(winner.first, time_utils::getTimeFormatted(winner.second));
    }

    return winnersFormatted;
}
void
WinnerCalculator::printTimings()
{
    for (const auto& timesPerKart : mTimesPerKart) {
        std::cout<< timesPerKart.first << " ";
        for (const auto& item : timesPerKart.second) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}

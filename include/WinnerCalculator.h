
#ifndef RACEWINNERCALCULATOR_WINNERCALCULATOR_H
#define RACEWINNERCALCULATOR_WINNERCALCULATOR_H


#include <utility>
#include <vector>
#include <map>
#include "KartPassingTime.h"

class WinnerCalculator {

    std::vector<KartPassingTime> mKartTimes;
    // kart id to list of passing times
    std::map<int, std::vector<long>> mTimesPerKart{};

    int mTotalNumberOfLaps{};
    long mFinishTimeInSeconds{};
public:

    explicit WinnerCalculator(std::vector<KartPassingTime> kartTimes)
        : mKartTimes(std::move(kartTimes)) {

    }

    std::vector<std::pair<int, std::string>>
    calculateWinner();

#ifndef UNIT_TESTING_ENABLED
private:
#endif

    std::map<int, std::vector<long>>
    calculateLapTimesPerKart();

    int
    calculateTotalNumberOfLaps();

    long
    calculateRaceFinishTime();

    void
    calculateEffectiveLapTimes();

    std::vector<std::pair<int, long>>
    getBestLapTime();

    void printTimings();
};


#endif //RACEWINNERCALCULATOR_WINNERCALCULATOR_H

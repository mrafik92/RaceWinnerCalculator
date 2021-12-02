#ifndef RACEWINNERCALCULATOR_KARTPASSINGTIMECSVPARSER_H
#define RACEWINNERCALCULATOR_KARTPASSINGTIMECSVPARSER_H


#include <vector>
#include "KartPassingTime.h"

class KartPassingTimeCsvParser {

public:
    explicit KartPassingTimeCsvParser(std::ifstream&& file);
    explicit KartPassingTimeCsvParser(std::string fileContents);

    std::vector<KartPassingTime>
    getKartTimings();

private:

    void decodeKartTimings();

    std::string mFileContents;
    std::vector<KartPassingTime> mKartTimes{};
};


#endif//RACEWINNERCALCULATOR_KARTPASSINGTIMECSVPARSER_H

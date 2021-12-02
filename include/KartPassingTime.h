//
// Created by mrafik on 12/2/21.
//

#ifndef RACEWINNERCALCULATOR_KARTPASSINGTIME_H
#define RACEWINNERCALCULATOR_KARTPASSINGTIME_H


#include <string>
#include "timeUtils.h"
class KartPassingTime {
    int  mKartId;
    long mPassingTime;

public:

    KartPassingTime(int kartId, long passingTime)
        : mKartId(kartId)
          , mPassingTime(passingTime){};


    KartPassingTime(const std::string& kartId, const std::string& passingTime)
    {
        mKartId      = std::stoi(kartId);
        mPassingTime = time_utils::getSeconds(passingTime);
    }

    const long&
    getPassTime() const
    {
        return mPassingTime;
    }

    int
    getKartId() const
    {
        return mKartId;
    }

    bool
    operator==(const KartPassingTime& rhs) const
    {
        return mKartId == rhs.mKartId && mPassingTime == rhs.mPassingTime;
    }

    bool
    operator!=(const KartPassingTime& rhs) const
    {
        return !(rhs == *this);
    }

    bool
    operator<(const KartPassingTime& rhs) const
    {
        if (mKartId < rhs.mKartId)
            return true;
        if (rhs.mKartId < mKartId)
            return false;
        return mPassingTime < rhs.mPassingTime;
    }

    bool
    operator>(const KartPassingTime& rhs) const
    {
        return rhs < *this;
    }

    bool
    operator<=(const KartPassingTime& rhs) const
    {
        return !(rhs < *this);
    }
    bool
    operator>=(const KartPassingTime& rhs) const
    {
        return !(*this < rhs);
    }
}

#endif//RACEWINNERCALCULATOR_KARTPASSINGTIME_H

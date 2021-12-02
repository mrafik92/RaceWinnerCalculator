#include <iomanip>
#include <string>
#include <vector>
#include "timeUtils.h"

namespace time_utils
{
    long
    getSeconds(const std::string& timeFormatted)
    {

        std::vector<long> timesHHMMSS(3);
        timesHHMMSS[0] = std::stoi(timeFormatted.substr(0, 2));
        timesHHMMSS[1] = std::stoi(timeFormatted.substr(3, 2));
        timesHHMMSS[2] = std::stoi(timeFormatted.substr(6, 2));

        return timesHHMMSS[0] * 60 * 60 + timesHHMMSS[1] * 60 + timesHHMMSS[2];
    }


    std::string
    getTimeFormatted(long total)
    {
        int seconds, hours, minutes;

        minutes = total / 60;
        seconds = total % 60;
        hours   = minutes / 60;
        minutes = minutes % 60;

        std::stringstream ss{};
        ss << std::setfill('0') << std::setw(2) << hours << ":" << std::setfill('0') << std::setw(2) << minutes << ":"
           << std::setfill('0') << std::setw(2) << seconds;

        return ss.str();
    }
}  // namespace time_utils
#ifndef RACEWINNERCALCULATOR_TIMEUTLS_H
#define RACEWINNERCALCULATOR_TIMEUTLS_H


namespace time_utils
{

    std::string
    getTimeFormatted(long total);

    long
    getSeconds(const std::string& timeFormatted);

}  // namespace time_utils

#endif  // RACEWINNERCALCULATOR_TIMEUTLS_H
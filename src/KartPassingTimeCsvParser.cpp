//
// Created by mrafik on 12/2/21.
//

#include "KartPassingTimeCsvParser.h"
#include "KartPassingTime.h"

#include <fstream>

#include <iostream>
#include <regex>
#include <string>
#include <utility>

KartPassingTimeCsvParser::KartPassingTimeCsvParser(std::ifstream&& file)
    : mFileContents(std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>()))
{
    decodeKartTimings();
}

KartPassingTimeCsvParser::KartPassingTimeCsvParser(std::string fileContent)
    : mFileContents(std::move(fileContent))
{
    decodeKartTimings();
}

void
KartPassingTimeCsvParser::decodeKartTimings()
{
    std::regex word_regex("([0-9].*)+,(.*)");
    auto       words_begin = std::sregex_iterator(mFileContents.begin(), mFileContents.end(), word_regex);
    auto       words_end   = std::sregex_iterator();

    mKartTimes.reserve(std::distance(words_begin, words_end));

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        mKartTimes.emplace_back(match.str(1), match.str(2));
    }
}

std::vector<KartPassingTime>
KartPassingTimeCsvParser::getKartTimings()
{
    return mKartTimes;
}

#include <iostream>
#include <optional>
#include <string>
#include <vector>
#include "KartPassingTime.h"
#include "KartPassingTimeCsvParser.h"
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

    const auto& kartTimings = KartPassingTimeCsvParser{std::ifstream {"karttimes.csv"}}.getKartTimings();

}
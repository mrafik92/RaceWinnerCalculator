#include "KartPassingTimeCsvParser.h"
#include "WinnerCalculator.h"
#include <fstream>
#include <iostream>

#include <string>


using namespace std;

int main(int argc, char *argv[]) {

    const auto &kartTimings = KartPassingTimeCsvParser{std::ifstream{"karttimes.csv"}}.getKartTimings();
    WinnerCalculator winnerCalculator{kartTimings};
    const auto &winners = winnerCalculator.calculateWinner();

    for (const auto &winner: winners) {
        std::cout << "winner is " << winner.first << " for lap time = " << winner.second << std::endl;
    }
}
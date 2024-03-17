#include <iostream>
#include <csignal>
#include <cstdio>
#include "impl/IStatistics.h"
#include "impl/Max.h"
#include "impl/ArithmeticMean.h"
#include "impl/Min.h"
#include "impl/StdDeviation.h"

int main() {
    const size_t statistics_count = 4;
    IStatistics* statistics[statistics_count];

    statistics[0] = new Min{};
    statistics[1] = new Max{};
    statistics[2] = new ArithmeticMean{};
    statistics[3] = new StdDeviation{0., 0};

    // try to ignore SIGHUP on Linux
    std::signal(SIGHUP,SIG_IGN);

    double val = 0;
    while (std::cin >> val) {
        for (size_t i = 0; i < statistics_count; ++i) {
            statistics[i]->update(val);
        }
    }

    // Handle invalid input data
    if (!std::cin.eof() && !std::cin.good()) {
        std::cerr << "Invalid input data\n";
        return 1;
    }

    // Print results if any
    for (size_t i = 0; i < statistics_count; ++i) {
        std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
    }

    // Clear memory - delete all objects created by new
    for (size_t i = 0; i < statistics_count; ++i) {
        delete statistics[i];
    }

    return 0;
}

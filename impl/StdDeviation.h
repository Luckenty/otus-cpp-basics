#ifndef STD_H
#define STD_H

#include <vector>
#include "IStatistics.h"

class StdDeviation : public IStatistics {
public:
    StdDeviation() = default;

    void update(double next) override;

    double eval() const override;

    const char* name() const override;

private:
    std::vector<double> numbers;
    double sum = 0.;
    int quantity = 0;
};

#endif //STD_H

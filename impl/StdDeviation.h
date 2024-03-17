#ifndef STD_H
#define STD_H

#include <vector>
#include "IStatistics.h"

class StdDeviation : public IStatistics {
public:
    StdDeviation();

    void update(double next) override;

    double eval() const override;

    const char* name() const override;

private:
    std::vector<double> numbers;
    double sum;
    int quantity;
};

#endif //STD_H

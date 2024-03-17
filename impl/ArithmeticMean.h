#ifndef MEAN_H
#define MEAN_H

#include "IStatistics.h"

class ArithmeticMean : public IStatistics {
public:
    ArithmeticMean();

    void update(double next) override;

    double eval() const override;

    const char* name() const override;

private:
    double sum;
    int quantity;
};

#endif //MEAN_H

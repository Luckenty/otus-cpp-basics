#ifndef MEAN_H
#define MEAN_H

#include "IStatistics.h"

class Mean : public IStatistics {
public:
    Mean() : sum{0.}, quantity{0} {
    }

    void update(double next) override {
        sum += next;
        quantity++;
    }

    double eval() const override {
        if (quantity != 0) {
            return sum / quantity;
        }
        return 0;
    }

    const char* name() const override {
        return "mean";
    }

private:
    double sum;
    int quantity;
};

#endif //MEAN_H

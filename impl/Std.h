#ifndef STD_H
#define STD_H

#include <vector>

#include "IStatistics.h"

class Std : public IStatistics {
public:
    Std() : sum{0.}, quantity{0} {
    }

    void update(double next) override {
        numbers.push_back(next);
        sum += next;
        quantity++;
    }

    double eval() const override {
        if (quantity != 0) {
            auto mean = sum / quantity;
            return sum / quantity;
        }
        return 0;
    }

    const char* name() const override {
        return "std";
    }

private:
    std::vector<double> numbers;
    double sum;
    int quantity;
};

#endif //STD_H

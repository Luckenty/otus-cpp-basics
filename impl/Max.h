#ifndef MAX_H
#define MAX_H
#include <limits>

#include "IStatistics.h"

class Max : public IStatistics {
public:
    Max() : max{std::numeric_limits<double>::min()} {
    }

    void update(double next) override {
        if (next > max) {
            max = next;
        }
    }

    double eval() const override {
        return max;
    }

    const char* name() const override {
        return "max";
    }

private:
    double max;
};

#endif //MAX_H

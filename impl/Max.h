#ifndef MAX_H
#define MAX_H

#include <limits>

#include "IStatistics.h"

class Max : public IStatistics {
public:
    Max();

    void update(double next) override;

    double eval() const override;

    const char* name() const override;

private:
    double max;
};

#endif //MAX_H

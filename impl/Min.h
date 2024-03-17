#ifndef MIN_H
#define MIN_H

#include <limits>
#include "IStatistics.h"

class Min : public IStatistics {
public:
    Min();

    void update(double next) override;

    double eval() const override;

    const char* name() const override;

private:
    double m_min;
};

#endif //MIN_H

#include "Max.h"

Max::Max() : max{std::numeric_limits<double>::min()} {
}

void Max::update(double next) {
    if (next > max) {
        max = next;
    }
}

double Max::eval() const {
    return max;
}

const char* Max::name() const {
    return "max";
}

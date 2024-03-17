#include "ArithmeticMean.h"

ArithmeticMean::ArithmeticMean() : sum{0.}, quantity{0} {
}

void ArithmeticMean::update(double next) {
    sum += next;
    quantity++;
}

double ArithmeticMean::eval() const {
    if (quantity != 0) {
        return sum / quantity;
    }
    return 0;
}

const char* ArithmeticMean::name() const {
    return "mean";
}

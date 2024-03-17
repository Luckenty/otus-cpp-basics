#ifndef STD_H
#define STD_H

#include <vector>
#include <cmath>

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
            // среднее арифметическое
            double mean = sum / quantity;
            double exp_sum = 0;
            // Вычисляем квадрат отклонений чисел от их средней оценки и суммируем
            for (int i = 0; i < numbers.size(); ++i) {
                exp_sum += std::pow((numbers[i] - mean), 2);
            }
            // возвращаем стандартное отклонение
            return sqrt(exp_sum / quantity);
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

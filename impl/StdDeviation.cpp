#include <vector>
#include <cmath>
#include "StdDeviation.h"

void StdDeviation::update(double next) {
    numbers.push_back(next);
    sum += next;
    quantity++;
}

double StdDeviation::eval() const {
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

const char* StdDeviation::name() const {
    return "std";
}

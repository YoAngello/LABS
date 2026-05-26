#include "Summator.h"

// Тождественное преобразование: возвращает само число
int Summator::transform(int i) const {
    return i;
}

// Вычисляет сумму transform(n) для всех n от 1 до N
long long Summator::sum(int N) const {
    long long result = 0;
    for (int i = 1; i <= N; i++) {
        result += transform(i);
    }
    return result;
}
#pragma once

#include "Summator.h"

class SquareSummator : public Summator {
public:
    // ѕереопределение: возвращает квадрат числа (i * i)
    int transform(int i) const override;
};

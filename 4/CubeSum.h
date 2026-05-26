#pragma once

#include "Summator.h"

class CubeSummator : public Summator {
public:
    // Переопределение: возвращает куб числа (i * i * i)
    int transform(int i) const override;
};

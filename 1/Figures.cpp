#include "Figures.h"

double calc_cylinder_volume(const Figure* base, double height) {
    if (base == nullptr || height < 0) return -1;   // Проверка ошибок
    return base->calc_area() * height;               // Площадь * высота
}
#pragma once

#include "Polynomial.h"

// Удаление ведущих нулей
template<typename T>
void Polynomial<T>::trim() {
    while (coeffs.size() > 1 && coeffs.back() == T(0)) {
        coeffs.pop_back();
    }
}

// Конструктор по умолчанию
template<typename T>
Polynomial<T>::Polynomial() : coeffs(1, T(0)) {}

// Конструктор от одного коэффициента
template<typename T>
Polynomial<T>::Polynomial(const T& c) : coeffs(1, c) {
    trim();
}

// Конструктор от вектора коэффициентов
template<typename T>
Polynomial<T>::Polynomial(const std::vector<T>& coefficients) : coeffs(coefficients) {
    if (coeffs.empty()) {
        coeffs.push_back(T(0));
    }
    trim();
}

// Степень многочлена
template<typename T>
int Polynomial<T>::Degree() const {
    return coeffs.size() - 1;
}

// Доступ к коэффициенту по степени
template<typename T>
T Polynomial<T>::operator[](int power) const {
    if (power < 0) return T(0);
    if (power >= (int)coeffs.size()) {
        return T(0);
    }
    return coeffs[power];
}

// Вычисление значения в точке (схема Горнера)
template<typename T>
T Polynomial<T>::operator()(const T& x) const {
    if (coeffs.empty()) return T(0);
    
    T result = coeffs.back();
    for (int i = coeffs.size() - 2; i >= 0; --i) {
        result = result * x + coeffs[i];
    }
    return result;
}

// Оператор ==
template<typename T>
bool Polynomial<T>::operator==(const Polynomial& other) const {
    if (Degree() != other.Degree()) return false;
    for (size_t i = 0; i < coeffs.size(); ++i) {
        if (!(coeffs[i] == other.coeffs[i])) return false;
    }
    return true;
}

// Оператор !=
template<typename T>
bool Polynomial<T>::operator!=(const Polynomial& other) const {
    return !(*this == other);
}

// Оператор +=
template<typename T>
Polynomial<T>& Polynomial<T>::operator+=(const Polynomial& other) {
    size_t maxSize = std::max(coeffs.size(), other.coeffs.size());
    coeffs.resize(maxSize, T(0));
    
    for (size_t i = 0; i < other.coeffs.size(); ++i) {
        coeffs[i] = coeffs[i] + other.coeffs[i];
    }
    trim();
    return *this;
}

// Оператор -=
template<typename T>
Polynomial<T>& Polynomial<T>::operator-=(const Polynomial& other) {
    size_t maxSize = std::max(coeffs.size(), other.coeffs.size());
    coeffs.resize(maxSize, T(0));
    
    for (size_t i = 0; i < other.coeffs.size(); ++i) {
        coeffs[i] = coeffs[i] - other.coeffs[i];
    }
    trim();
    return *this;
}

// Оператор *=
template<typename T>
Polynomial<T>& Polynomial<T>::operator*=(const Polynomial& other) {
    std::vector<T> newCoeffs(Degree() + other.Degree() + 1, T(0));
    
    for (size_t i = 0; i < coeffs.size(); ++i) {
        for (size_t j = 0; j < other.coeffs.size(); ++j) {
            newCoeffs[i + j] = newCoeffs[i + j] + coeffs[i] * other.coeffs[j];
        }
    }
    
    coeffs = std::move(newCoeffs);
    trim();
    return *this;
}

// Оператор +
template<typename T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial& other) const {
    Polynomial result = *this;
    result += other;
    return result;
}

// Оператор -
template<typename T>
Polynomial<T> Polynomial<T>::operator-(const Polynomial& other) const {
    Polynomial result = *this;
    result -= other;
    return result;
}

// Оператор *
template<typename T>
Polynomial<T> Polynomial<T>::operator*(const Polynomial& other) const {
    Polynomial result = *this;
    result *= other;
    return result;
}

// Скаляр + многочлен
template<typename T>
Polynomial<T> operator+(const T& scalar, const Polynomial<T>& poly) {
    return Polynomial<T>(scalar) + poly;
}

// Многочлен + скаляр
template<typename T>
Polynomial<T> operator+(const Polynomial<T>& poly, const T& scalar) {
    return poly + Polynomial<T>(scalar);
}

// Скаляр - многочлен
template<typename T>
Polynomial<T> operator-(const T& scalar, const Polynomial<T>& poly) {
    return Polynomial<T>(scalar) - poly;
}

// Многочлен - скаляр
template<typename T>
Polynomial<T> operator-(const Polynomial<T>& poly, const T& scalar) {
    return poly - Polynomial<T>(scalar);
}

// Скаляр * многочлен
template<typename T>
Polynomial<T> operator*(const T& scalar, const Polynomial<T>& poly) {
    std::vector<T> newCoeffs;
    for (int i = 0; i <= poly.Degree(); ++i) {
        newCoeffs.push_back(scalar * poly[i]);
    }
    return Polynomial<T>(newCoeffs);
}

// Многочлен * скаляр
template<typename T>
Polynomial<T> operator*(const Polynomial<T>& poly, const T& scalar) {
    return scalar * poly;
}

// Оператор вывода
template<typename T>
std::ostream& operator<<(std::ostream& out, const Polynomial<T>& poly) {
    if (poly.Degree() == 0) {
        out << poly[0];
        return out;
    }
    
    bool first = true;
    for (int i = poly.Degree(); i >= 0; --i) {
        T c = poly[i];
        if (c == T(0)) continue;
        
        if (!first && c > T(0)) {
            out << " + ";
        }
        else if (!first && c < T(0)) {
            out << " - ";
            c = -c;
        }
        else if (first && c < T(0)) {
            out << "-";
            c = -c;
        }
        
        if (i == 0) {
            out << c;
        }
        else if (i == 1) {
            out << c << "*x";
        }
        else {
            out << c << "*x^" << i;
        }
        first = false;
    }
    return out;
}
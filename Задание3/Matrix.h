#pragma once

using namespace std;

template <typename T>
class Matrix {
private:
    T** data;      
    int rows;      
    int cols;  

    void allocateMemory();
    void freeMemory();
    void copyData(const Matrix& other);

public:
    
    Matrix(int r = 0, int c = 0);               
    Matrix(const Matrix& other);                
    ~Matrix();                                  

    void Set(int i, int j, const T& value);
    T Get(int i, int j) const;

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    // Дружественные операторы ввода/вывода
    template <typename U>
    friend ostream& operator<<(ostream& os, const Matrix<U>& m);

    template <typename U>
    friend istream& operator>>(istream& is, Matrix<U>& m);
};

#include "Matrix.tpp"

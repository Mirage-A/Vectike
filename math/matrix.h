//
// Created by Егор on 06.11.2018.
//

#ifndef VECTIKE_MATRIX_H
#define VECTIKE_MATRIX_H

#include <cstddef>
#include <vector>

class Matrix {
private:
    size_t rows_, columns_;
    std::vector<std::vector<double>> matrix_;
public:
    //Создает нулевую матрицу размера width x height
    Matrix(size_t rows, size_t columns);

    //Создает матрицу поворота на угол angle
    Matrix(double angle);

    //Прибавляет матрицу к этой матрице
    void Add(Matrix &another);

    //Умножает матрицу на число
    void ScalarMultiply(double multiplier);

    //Умножает матрицу на матрицу, возвращает новую матрицу
    Matrix MatrixMultiply(Matrix &another) const;

    size_t GetWidth() const;

    size_t GetHeight() const;

    double GetElement(size_t row, size_t column) const;

    double SetElement(size_t row, size_t column, double new_value);
};
#endif //VECTIKE_MATRIX_H

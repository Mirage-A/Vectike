#include "matrix.h"
#include <math.h>
#include <stdexcept>

Matrix::Matrix(size_t rows, size_t columns) {
    columns_ = columns;
    rows_ = rows;
    for(size_t i = 0; i < rows; ++i) {
        std::vector<double> column;
        for(size_t j = 0; j < columns; ++j) {
            column.push_back(0);
        }
        matrix_.push_back(column);
    }
}

Matrix::Matrix(double angle) {
    columns_ = 2;
    rows_ = 2;
    std::vector<std::vector<double>> rotate_matrix{ {cos(angle), -sin(angle)}, {sin(angle), cos(angle)} };
    matrix_ = rotate_matrix;
}

void Matrix::Add(Matrix &another) {
    if(rows_ != another.GetHeight() || columns_!= another.GetWidth()) {
        throw std::invalid_argument("Can't sum matrices with different sizes");
    }
    for(size_t i = 0; i < rows_; ++i) {
        for(size_t j = 0; j < columns_; ++j) {
            SetElement(i, j, GetElement(i, j) + another.GetElement(i, j));
        }
    }
}

void Matrix::ScalarMultiply(double multiplier) {
    for(size_t i = 0; i < rows_; ++i) {
        for(size_t j = 0; j < columns_; ++j) {
            SetElement(i, j, GetElement(i, j) * multiplier);
        }
    }
}

Matrix Matrix::MatrixMultiply(Matrix &another) const {
    if(columns_ != another.rows_) {
        throw std::invalid_argument("2nd multiplier height should be equal to 1nd multiplier width");
    }
    Matrix result(rows_, another.columns_);
    //TODO Сделать какой-нибудь суперкрутой алгоритм перемножения матриц
    for(size_t i = 0; i < rows_; ++i) {
        for(size_t j = 0; j < another.columns_; ++j) {
            double new_value = 0;
            for(size_t k = 0; k < columns_; ++k) {
                new_value += GetElement(i, k) * another.GetElement(k, j);
            }
            result.SetElement(i, j, new_value);
        }
    }
    return result;
}

size_t Matrix::GetWidth() const {
    return columns_;
}

size_t Matrix::GetHeight() const {
    return rows_;
}

double Matrix::GetElement(size_t row, size_t column) const {
    return matrix_[row][column];
}

double Matrix::SetElement(size_t row, size_t column, double new_value) {
    matrix_[row][column] = new_value;
}
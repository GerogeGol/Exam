#pragma once

#include <iostream>
#include <stdexcept>

#include "array.hpp"

template <typename T>
class Matrix
{
   private:
    Array<Array<T>> m_matrix;
    size_t m_height;
    size_t m_width;

   public:
    Matrix() : m_matrix(Array(1, Array(1))), m_height(1), m_width(1){};
    Matrix(size_t n, size_t m, const T& value = T());
    Matrix(const Matrix& other);
    Matrix(const Matrix&& other);

    Matrix& operator+(const Matrix& other) const;
    Matrix& operator+=(const Matrix& other);

    Matrix& operator-(const Matrix& other) const;
    Matrix& operator-=(const Matrix& other);

    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;

    size_t size() const;
    size_t empty() const;

    const Array<T>& operator[](size_t index) const;
    Array<T>& operator[](size_t index);

    friend std::ostream& operator<<(std::ostream& out, const Matrix& Matrix);

    ~Matrix();
};
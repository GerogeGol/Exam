#pragma once

#include "matrix.hpp"

template <typename T>
Matrix<T>::Matrix(size_t n, size_t m, const T& value = T()) : m_matrix(Array<T>(n, Array<T>(m))), m_height(n), m_width(n)
{
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            m_matrix[i][j] = value;
        }
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix& other)
{
    if (this == &other) {
        return;
    }

    delete[] m_matrix;
    m_height = other.m_height;
    m_width = other.m_width;
    m_matrix = Array<T>(m_height, Array<T>(m_width));

    for (size_t i = 0; i < m_height; i++) {
        for (size_t j = 0; j < m_width; j++) {
            m_matrix[i][j] = other[i][j];
        }
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix&& other)
{
    if (this == &other) {
        return;
    }

    delete[] m_matrix;
    m_height = other.m_height;
    m_width = other.m_width;
    m_matrix = other.m_matrix;
}

template <typename T>
Matrix<T>& Matrix<T>::operator+(const Matrix<T>& other) const
{
    if ((m_height != other.m_height) || (m_width != other.m_width)) {
        throw std::runtime_error("Matrices are different")
    }

    Matrix<T>* new_matrix = new Matrix<T>(m_height, m_width);
    for (size_t i = 0; i < m_height; i++) {
        new_matrix[i] = m_matrix[i] + other.m_matrix[i];
    }
    return *new_matrix;
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& other)
{
    if ((m_height != other.m_height) || (m_width != other.m_width)) {
        throw std::runtime_error("Matrices are different")
    }

    Matrix<T>* new_matrix = new Matrix<T>(m_height, m_width);
    for (size_t i = 0; i < m_height; i++) {
        m_matrix[i] += other.m_matrix[i];
    }
    return *new_matrix;
}

template <typename T>
Matrix<T>& Matrix<T>::operator-(const Matrix<T>& other) const
{
    if ((m_height != other.m_height) || (m_width != other.m_width)) {
        throw std::runtime_error("Matrices are different")
    }

    Matrix<T>* new_matrix = new Matrix<T>(m_height, m_width);
    for (size_t i = 0; i < m_height; i++) {
        new_matrix[i] = m_matrix[i] - other.m_matrix[i];
    }
    return *new_matrix;
}

template <typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& other)
{
    if ((m_height != other.m_height) || (m_width != other.m_width)) {
        throw std::runtime_error("Matrices are different")
    }

    Matrix<T>* new_matrix = new Matrix<T>(m_height, m_width);
    for (size_t i = 0; i < m_height; i++) {
        m_matrix[i] -= other.m_matrix[i];
    }
    return *new_matrix;
}

template <typename T>
bool Matrix<T>::operator==(const Matrix<T>& other) const
{
    if ((m_height != other.m_height) || (m_width != other.m_width)) {
        return false;
    }

    for (size_t i = 0; i < m_height; i++) {
        if (m_matrix[i] != other.m_matrix[i]) {
            return false;
        }
    }

    return true;
}

template <typename T>
bool Matrix<T>::operator!=(const Matrix& other) const
{
    if ((m_height != other.m_height) || (m_width != other.m_width)) {
        return false;
    }

    return !(*this == other);
}

template <typename T>
size_t Matrix<T>::size() const
{
    return m_height;
}
template <typename T>
size_t Matrix<T>::empty() const
{
    return m_height == 0 || m_height == 0;
}

template <typename T>
const Array<T>& Matrix<T>::operator[](size_t index) const
{
    if (index < 0 || index > m_height) {
        throw std::runtime_error("invalid index");
    }

    return m_matrix[index];
}

template <typename T>
Array<T>& Matrix<T>::operator[](size_t index)
{
    if (index < 0 || index > m_height) {
        throw std::runtime_error("invalid index");
    }

    return m_matrix[index];
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix)
{
    for (size_t i = 0; i < matrix.m_height; i++) {
        out << matrix.m_matrix[i];
    }
    return out;
}
template <typename T>
Matrix<T>::~Matrix()
{
    for (int i = 0; i < m_height; i++) {
        delete[] m_matrix[i];
    }

    delete[] m_matrix;
}
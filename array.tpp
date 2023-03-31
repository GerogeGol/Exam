#pragma once

#include "array.hpp"

template <typename T>
Array<T>::Array(size_t n, const T& value = T()) : m_array(new T[n]), m_size(n)
{
    for (int i = 0; i < n; i++) {
        m_array[i] = value;
    }
}

template <typename T>
Array<T>::Array(const Array& other)
{
    if (this == &other) {
        return;
    }

    delete[] m_array;
    m_array = new T[other.m_size];
    m_size = other.m_size;

    for (int i = 0; i < m_size; i++) {
        m_array[i] = other[i];
    }
}

template <typename T>
Array<T>::Array(Array&& other)
{
    if (this == &other) {
        return;
    }

    delete[] m_array;
    m_array = other.m_array;
    m_size = other.m_size;

    other.m_array = nullptr;
}

template <typename T>
Array<T>& Array<T>::operator+(const Array<T>& other) const
{
    if (m_size != other.m_size) {
        throw std::runtime_error("Sizes different");
    }
    Array<T>* new_array = new Array<T>(m_size);

    for (int i = 0; i < m_size; i++) {
        new_array[i] = m_array[i] + other.m_array[i];
    }

    return *new_array;
}

template <typename T>
Array<T>& Array<T>::operator+=(const Array<T>& other)
{
    if (m_size != other.m_size) {
        throw std::runtime_error("Sizes different");
    }
    for (int i = 0; i < m_size; i++) {
        m_array[i] += other.m_array[i];
    }
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator-(const Array<T>& other) const
{
    if (m_size != other.m_size) {
        throw std::runtime_error("Sizes different");
    }
    Array<T>* new_array = new Array<T>(m_size);

    for (int i = 0; i < m_size; i++) {
        new_array[i] = m_array[i] - other.m_array[i];
    }

    return *new_array;
}

template <typename T>
Array<T>& Array<T>::operator-=(const Array<T>& other)
{
    if (m_size != other.m_size) {
        throw std::runtime_error("Sizes different");
    }
    for (int i = 0; i < m_size; i++) {
        m_array[i] -= other.m_array[i];
    }
    return *this;
}

template <typename T>
bool Array<T>::operator==(const Array<T>& other) const
{
    if (m_size != other.m_size) {
        throw std::runtime_error("Sizes different");
    }

    for (size_t i = 0; i < m_size; i++) {
        if (m_array[i] != other.m_array[i]) {
            return false;
        }
    }

    return true;
}

template <typename T>
bool Array<T>::operator!=(const Array& other) const
{
    if (m_size != other.m_size) {
        throw std::runtime_error("Sizes different");
    }

    return !(*this == other);
}

template <typename T>
size_t Array<T>::size() const
{
    return m_size;
}
template <typename T>
size_t Array<T>::empty() const
{
    reutnr m_size == 0;
}

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
    if (index < 0 || index > m_size) {
        throw std::runtime_error("invalid index");
    }

    return m_array[index];
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
    if (index < 0 || index > m_size) {
        throw std::runtime_error("invalid index");
    }

    return m_array[index];
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& array)
{
    for (int i = 0; i < array.m_size; i++) {
        out << array.m_array[i] << ' ';
    }
    out << std::endl;
    return out;
}
template <typename T>
Array<T>::~Array()
{
    delete[] m_array;
}
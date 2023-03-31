#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
   private:
    T* m_array;
    size_t m_size;

    void check_index(size_t index) const;

   public:
    Array() : m_array(new T[1]), m_size(0){};
    Array(size_t n, const T& value = T());
    Array(const Array& other);
    Array(Array&& other);

    Array& operator+(const Array& other) const;
    Array& operator+=(const Array& other);

    Array& operator-(const Array& other) const;
    Array& operator-=(const Array& other);

    bool operator==(const Array& other) const;
    bool operator!=(const Array& other) const;

    size_t size() const;
    size_t empty() const;

    const T& operator[](size_t index) const;
    T& operator[](size_t index);

    friend std::ostream& operator<<(std::ostream& out, const Array& array);

    ~Array();
};

#include "array.tpp"
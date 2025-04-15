#include "Array.hpp"
#include <stdexcept>

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n) {
    if (n == 0) {
        _array = NULL;
    } else {
        _array = new T[n]();
    }
}

template <typename T>
Array<T>::Array(Array const & src) : _size(src._size) {
    if (src._array == NULL) {
        _array = NULL;
    } else {
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; ++i) {
            _array[i] = src._array[i];
        }
    }
}

template <typename T>
Array<T>::~Array() {
    delete[] _array;
}

template <typename T>
Array<T> & Array<T>::operator=(Array const & rhs) {
    if (this != &rhs) {
        delete[] _array;

        _size = rhs._size;
        if (rhs._array == NULL) {
            _array = NULL;
        } else {
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; ++i) {
                _array[i] = rhs._array[i];
            }
        }
    }
    return *this;
}

template <typename T>
T & Array<T>::operator[](unsigned int i) {
    if (i >= _size) {
        throw IndexOutOfBoundsException();
    }
    return _array[i];
}

template <typename T>
T const & Array<T>::operator[](unsigned int i) const {
    if (i >= _size) {
        throw IndexOutOfBoundsException();
    }
    return _array[i];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

template <typename T>
const char* Array<T>::IndexOutOfBoundsException::what() const throw() {
    return "Index is out of bounds";
}
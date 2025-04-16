#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename Func>
void iter(T* arrayAddress, size_t arrayLength, Func func) {
    if (!arrayAddress || !func) {
        return;
    }
    for (size_t i = 0; i < arrayLength; ++i) {
        func(arrayAddress[i]);
    }
}

#endif
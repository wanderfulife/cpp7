#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <stdexcept>

template <typename T>
class Array {
private:
    T*              _array;
    unsigned int    _size;

public:

    Array();
    Array(unsigned int n);
    Array(Array const & src);


    ~Array();


    Array & operator=(Array const & rhs);
    T & operator[](unsigned int i);
    T const & operator[](unsigned int i) const;


    unsigned int size() const;


    class IndexOutOfBoundsException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

# include "Array.tpp"

#endif
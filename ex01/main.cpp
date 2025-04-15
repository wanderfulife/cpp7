#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(T const & element) {
    std::cout << element << " ";
}

template <typename T>
void incrementElement(T & element) {
    element++;
}

int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    size_t intArrLen = sizeof(intArr) / sizeof(int);
    std::cout << "Int array before increment: ";
    iter(intArr, intArrLen, printElement<int>);
    std::cout << std::endl;

    iter(intArr, intArrLen, incrementElement<int>);

    std::cout << "Int array after increment:  ";
    iter(intArr, intArrLen, printElement<int>);
    std::cout << std::endl << std::endl;

    double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArrLen = sizeof(doubleArr) / sizeof(double);
    std::cout << "Double array: ";
    iter(doubleArr, doubleArrLen, printElement<double>);
    std::cout << std::endl << std::endl;

    char charArr[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charArrLen = sizeof(charArr) / sizeof(char);
    std::cout << "Char array before increment: ";
    iter(charArr, charArrLen, printElement<char>);
    std::cout << std::endl;

    iter(charArr, charArrLen, incrementElement<char>);

    std::cout << "Char array after increment:  ";
    iter(charArr, charArrLen, printElement<char>);
    std::cout << std::endl << std::endl;

    std::string strArr[] = {"Hello", "World", "Test"};
    size_t strArrLen = sizeof(strArr) / sizeof(std::string);
    std::cout << "String array: ";
    iter(strArr, strArrLen, printElement<std::string>);
    std::cout << std::endl;

    const int constIntArr[] = {10, 20, 30};
    size_t constIntArrLen = sizeof(constIntArr) / sizeof(int);
    std::cout << "Const int array: ";
    iter(constIntArr, constIntArrLen, printElement<int>);
    std::cout << std::endl;

    int* emptyArr = NULL;
    std::cout << "Testing with empty array: ";
    iter(emptyArr, 0, printElement<int>);
    std::cout << "(Should print nothing)" << std::endl;

    return 0;
}
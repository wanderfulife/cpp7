#include <iostream>
#include "Array.hpp"
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750

template <typename T>
void printArray(const Array<T>& arr, const std::string& name) {
    std::cout << name << " (size " << arr.size() << "): [ ";
    for (unsigned int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i == arr.size() - 1 ? " " : ", ");
    }
    std::cout << "]" << std::endl;
}

int main(int, char**)
{
    std::cout << "--- Basic Demo ---" << std::endl;

    Array<int> emptyArray;
    printArray(emptyArray, "emptyArray");
    Array<int> sizedArray(5);

    for (unsigned int i = 0; i < sizedArray.size(); ++i) {
        sizedArray[i] = i * 10;
    }
    printArray(sizedArray, "sizedArray<int>");
    std::cout << "sizedArray[2] = " << sizedArray[2] << std::endl;
    std::cout << std::endl;

    std::cout << "--- Const Access Demo ---" << std::endl;
    const Array<int> constArr = sizedArray;
    printArray(constArr, "constArr");
    std::cout << "Reading constArr[3] = " << constArr[3] << std::endl;
    std::cout << std::endl;

    std::cout << "--- Exception Demo ---" << std::endl;
    try {
        std::cout << "Accessing [10] (out of bounds): " << sizedArray[10] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Running original tests ---" << std::endl;

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
} 
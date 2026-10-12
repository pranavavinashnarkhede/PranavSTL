#include "../include/pstl/Sorting.hpp"
#include <iostream>

using namespace pstl;

int main()
{
    int iSize = 0;

    std::cout << "Enter number of elements: ";
    std::cin >> iSize;

    Sorting sobj(iSize);

    sobj.Accept();

    std::cout << "\nOriginal array:\n";
    sobj.Display();

    sobj.InsertionSort();

    std::cout << "\nFinal sorted array:\n";
    sobj.Display();

    return 0;
}
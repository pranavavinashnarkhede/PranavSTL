#include "../include/pstl/Searching.hpp"
#include <iostream>

using namespace pstl;

int main()
{
    int iSize = 0;
    int iNo = 0;

    std::cout << "Enter the size of the array: ";
    std::cin >> iSize;

    Searching sobj(iSize);

    sobj.Accept();
    sobj.Display();

    std::cout << "\nEnter the element to search: ";
    std::cin >> iNo;

    if(sobj.LinearSearch(iNo) == true)
    {
        std::cout << "Element is present (Linear Search)\n";
    }
    else
    {
        std::cout << "Element is not present (Linear Search)\n";
    }

    if(sobj.BiDirectionalSearch(iNo) == true)
    {
        std::cout << "Element is present (Bidirectional Search)\n";
    }
    else
    {
        std::cout << "Element is not present (Bidirectional Search)\n";
    }

    return 0;
}
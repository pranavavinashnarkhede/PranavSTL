#ifndef PSTL_SEARCHING_HPP
#define PSTL_SEARCHING_HPP

#include <iostream>

namespace pstl
{
    class Searching
    {
        private:
            int *Arr;
            int iSize;

        public:
            Searching(int iNo);
            ~Searching();

            void Accept();
            void Display();

            bool LinearSearch(int iNo);
            bool BiDirectionalSearch(int iNo);
    };

    // Constructor
    inline Searching::Searching(int iNo)
    {
        iSize = iNo;
        Arr = new int[iSize];
    }

    // Destructor
    inline Searching::~Searching()
    {
        delete []Arr;
    }

    // Accept array elements
    inline void Searching::Accept()
    {
        int i = 0;

        std::cout << "Enter the elements:\n";

        for(i = 0; i < iSize; i++)
        {
            std::cin >> Arr[i];
        }
    }

    // Display array elements
    inline void Searching::Display()
    {
        int i = 0;

        std::cout << "Elements of the array are:\n";

        for(i = 0; i < iSize; i++)
        {
            std::cout << Arr[i] << std::endl;
        }
    }

    // Linear Search
    inline bool Searching::LinearSearch(int iNo)
    {
        int i = 0;
        bool bFlag = false;

        for(i = 0; i < iSize; i++)
        {
            if(Arr[i] == iNo)
            {
                bFlag = true;
                break;
            }
        }

        return bFlag;
    }

    // Bidirectional Search
    inline bool Searching::BiDirectionalSearch(int iNo)
    {
        int iStart = 0;
        int iEnd = iSize - 1;
        bool bFlag = false;

        while(iStart <= iEnd)
        {
            if((Arr[iStart] == iNo) || (Arr[iEnd] == iNo))
            {
                bFlag = true;
                break;
            }

            iStart++;
            iEnd--;
        }

        return bFlag;
    }
}

#endif
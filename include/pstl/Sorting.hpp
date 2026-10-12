#ifndef PSTL_SORTING_HPP
#define PSTL_SORTING_HPP

#include <iostream>

namespace pstl
{
    class GetterSetter
    {
        public:
            virtual void Accept() = 0;
            virtual void Display() = 0;

            virtual ~GetterSetter() {}
    };

    class ArrayX : public GetterSetter
    {
        protected:
            int *Arr;
            int iSize;

        public:
            ArrayX(int iSize);
            virtual ~ArrayX();

            void Accept() override;
            void Display() override;
    };

    class Sorting : public ArrayX
    {
        public:
            bool IsSorted;

            Sorting(int iSize);

            void BubbleSort();
            void BubbleSortEfficient();
            void SelectionSort();
            void InsertionSort();
    };

    // ArrayX Constructor
    inline ArrayX::ArrayX(int iSize)
    {
        this->iSize = iSize;
        Arr = new int[iSize];
    }

    // ArrayX Destructor
    inline ArrayX::~ArrayX()
    {
        delete[] Arr;
    }

    // Accept
    inline void ArrayX::Accept()
    {
        std::cout << "Enter the elements of array:\n";

        for(int i = 0; i < iSize; i++)
        {
            std::cin >> Arr[i];
        }

    }

    // Display
    inline void ArrayX::Display()
    {
        std::cout << "Elements of the array are:\n";

        for(int i = 0; i < iSize; i++)
        {
            std::cout << Arr[i] << "\t";
        }

        std::cout << std::endl;
    }

    // Sorting Constructor
    inline Sorting::Sorting(int iSize) : ArrayX(iSize)
    {
        IsSorted = false;
    }

    // Bubble Sort
    inline void Sorting::BubbleSort()
    {
        if(IsSorted == true)
        {
            return;
        }

        int i = 0, j = 0, temp = 0, pass = 0;

        for(i = 0, pass = 1; i < iSize - 1; i++, pass++)
        {
            for(j = 0; j < iSize - 1 - i; j++)
            {
                if(Arr[j] > Arr[j + 1])
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;
                }
            }

            std::cout << "Data after pass: " << pass << std::endl;
            Display();
        }

        IsSorted = true;
    }

    // Efficient Bubble Sort
    inline void Sorting::BubbleSortEfficient()
    {
        if(IsSorted == true)
        {
            return;
        }

        int i = 0, j = 0, temp = 0;
        bool bFlag = true;

        for(i = 0; i < iSize - 1; i++)
        {
            if(bFlag == false)
            {
                break;
            }

            bFlag = false;

            for(j = 0; j < iSize - 1 - i; j++)
            {
                if(Arr[j] > Arr[j + 1])
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;

                    bFlag = true;
                }
            }
        }

        IsSorted = true;
    }

    // Selection Sort
    inline void Sorting::SelectionSort()
    {
        if(IsSorted == true)
        {
            return;
        }

        int i = 0, j = 0, temp = 0;
        int min_index = 0, pass = 0;

        for(i = 0, pass = 1; i < iSize - 1; i++, pass++)
        {
            min_index = i;

            for(j = i + 1; j < iSize; j++)
            {
                if(Arr[j] < Arr[min_index])
                {
                    min_index = j;
                }
            }

            temp = Arr[i];
            Arr[i] = Arr[min_index];
            Arr[min_index] = temp;

            std::cout << "\nData after pass: " << pass << std::endl;
            Display();
        }

        IsSorted = true;
    }

    // Insertion Sort
    inline void Sorting::InsertionSort()
    {
        if(IsSorted == true)
        {
            return;
        }

        int i = 0, j = 0;
        int selected = 0;

        for(i = 1; i < iSize; i++)
        {
            selected = Arr[i];

            for(j = i - 1; (j >= 0) && (Arr[j] > selected); j--)
            {
                Arr[j + 1] = Arr[j];
            }

            Arr[j + 1] = selected;
        }

        IsSorted = true;
    }
}

#endif
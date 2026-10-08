#include "../include/pstl/Stack.hpp"
#include <iostream>

using namespace pstl;

int main()
{
    Stack<int> s;

    s.Push(10);
    s.Push(20);
    s.Push(30);

    std::cout << "Stack elements:\n";
    s.Display();

    std::cout << "\nCount: " << s.Count() << std::endl;

    std::cout << "\nTop element: " << s.Peep() << std::endl;

    std::cout << "\nPopped element: " << s.Pop() << std::endl;

    std::cout << "\nStack after Pop:\n";
    s.Display();

    std::cout << "\nCount: " << s.Count() << std::endl;

    return 0;
}
#include "../include/pstl/pstl.hpp"
#include <iostream>

using namespace pstl;

int main()
{
    Queue<int> q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    std::cout << "Queue elements:\n";
    q.Display();

    std::cout << "\nCount: " << q.Count() << std::endl;

    std::cout << "\nDequeued element: " << q.Dequeue() << std::endl;

    std::cout << "\nQueue after Dequeue:\n";
    q.Display();

    std::cout << "\nCount: " << q.Count() << std::endl;

    return 0;
}
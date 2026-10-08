#ifndef PSTL_NODE_HPP
#define PSTL_NODE_HPP

namespace pstl
{
    template <class T>
    struct node
    {
        T data;
        struct node<T> *next;
        struct node<T> *prev;
    };
}

#endif
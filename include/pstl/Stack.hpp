#ifndef PSTL_STACK_HPP
#define PSTL_STACK_HPP

#include<iostream>
#include<stdexcept>
#include "node.hpp"

#pragma pack(1)

namespace pstl
{
    template <class T>
    class Stack
    {
        private :
            struct node <T> *first;
            int iCount;

        public:
            Stack();
            ~Stack();
            void Push(T iNo);
            T Pop();
            T Peep();
            void Display() const;
            int Count() const;
        
    }; 

    template <class T>
    Stack<T> :: Stack()
    {
        first = NULL;
        iCount = 0 ;
    }

    template <class T>
    Stack<T>::~Stack()
    {
        struct node<T> *temp = NULL;

        while(this->first != NULL)
        {
            temp = this->first;
            this->first = this->first->next;

            delete temp;
        }

        this->iCount = 0;
    }

    template <class T>
    void Stack<T> :: Push(T iNo)
    {
        struct node<T> *newn = NULL ;

        newn = new struct node<T> () ;

        newn->data = iNo ;

        newn->next = first ;
        first = newn;

        this->iCount++;

    }   

    template <class T>
    T Stack<T>::Pop()
    {
        if(first == NULL)
        {
            throw std::underflow_error("Stack is empty");
        }

        T iValue = first->data;
        struct node<T> *temp = first;

        first = first->next;

        delete temp;

        this->iCount--;

        return iValue;
    }  

    template <class T>
    T Stack<T>::Peep()
    {
        if(first == NULL)
        {
            throw std::underflow_error("Stack is empty");
        }

        return first->data;
    }  

    template <class T>
    void Stack<T> :: Display() const
    {
        struct node<T> *temp = NULL ;

        temp = first;

        while(temp != NULL)
        {
            std::cout<<"| "<<temp->data<<" |\n";
            temp = temp->next;
        }
    }

    template <class T>
    int Stack<T> :: Count() const
    {
        return iCount ;
    }

}

#endif
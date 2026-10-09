#ifndef PSTL_QUEUE_HPP
#define PSTL_QUEUE_HPP

#include<iostream>
#include<stdexcept>
#include "node.hpp"

namespace pstl
{
    template <class T>
    class Queue
    {
        private:
            struct node<T> *first;
            int iCount;

        public:
            Queue();
            ~Queue();

            void Enqueue(T iNo);
            T Dequeue();
            void Display() const;
            int Count() const;
    };

    template <class T>
    Queue<T>::Queue()
    {
        this->first = NULL;
        this->iCount = 0;
    }

    template <class T>
    Queue<T>::~Queue()
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
    void Queue<T>::Enqueue(T iNo)
    {
        struct node<T> *newn = NULL;
        struct node<T> *temp = NULL;

        newn = new struct node<T>();

        newn->data = iNo;
        newn->next = NULL;

        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            temp = first;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newn;
        }

        this->iCount++;
    }

    template <class T>
    T Queue<T>::Dequeue()
    {
        if(first == NULL)
        {
            throw std::underflow_error("Queue is empty");
        }

        T iValue = first->data;
        struct node<T> *temp = first;

        first = first->next;

        delete temp;

        this->iCount--;

        return iValue;
    }

    template <class T>
    void Queue<T>::Display() const
    {
        struct node<T> *temp = first;

        while(temp != NULL)
        {
            std::cout<<"| "<<temp->data<<" |\n";
            temp = temp->next;
        }
    }

    template <class T>
    int Queue<T>::Count() const
    {
        return iCount;
    }
}

#endif
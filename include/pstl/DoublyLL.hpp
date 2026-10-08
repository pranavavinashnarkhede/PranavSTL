#ifndef PSTL_DOUBLYLL_HPP
#define PSTL_DOUBLYLL_HPP

#include<iostream>
#include "node.hpp"

#pragma pack(1)

namespace pstl
{
  
    template <class T>
    class DoublyLL
    {
        private:
            struct node<T> *first ;
            int iCount ;
        
        public:
            DoublyLL();
            ~DoublyLL();
            void Display() const;
            int Count() const;
            void InsertFirst(T iNo);
            void InsertLast(T iNo);
            void InsertAtPos(T iNo , int iPos);
            void DeleteFirst();
            void DeleteLast();
            void DeleteAtPos(int iPos);
    };     

    template <class T>
    DoublyLL<T> ::DoublyLL()
    {
        this->first = NULL;
        this->iCount = 0 ;
    }

    template <class T>
    DoublyLL<T> :: ~DoublyLL()
    {
        struct node<T> *temp = NULL ;

        for(int i = 0 ; i < iCount ; i++)
        {
            temp = first;

            first = first->next;

            delete temp;
        }

        this->iCount = 0 ;
        this->first = NULL ;
    }

    template <class T>
    void DoublyLL<T> :: Display() const
    {
        struct node<T> *temp = NULL;

        temp = this->first;

        std::cout<<"NULL <=>";
        while(temp != NULL)
        {
            std::cout<<"| "<<temp->data<<" | <=> ";
            temp = temp->next;
        }
        std::cout<<"NULL"<<std::endl;
    }

    template <class T>
    int DoublyLL<T> :: Count() const
    {
        return this->iCount ;
    }

    template <class T>
    void DoublyLL<T> :: InsertFirst(T iNo)
    {
        struct node<T> *newn = NULL;

        newn = new struct node<T>;

        newn->data = iNo ;
        newn->next = NULL ;
        newn->prev = NULL ;

        if(first == NULL)
        {
            this->first = newn;
            newn->prev = this->first;
        }
        else
        {
            newn->next = this->first;
            this->first->prev = newn;
            this->first = newn;
        }

        this->iCount++;
    }

    template <class T>
    void DoublyLL<T> :: InsertLast(T iNo)
    {
        struct node<T> *newn = NULL;
        struct node<T> *temp = NULL ;

        newn = new struct node<T>;

        newn->data = iNo ;
        newn->next = NULL ;
        newn->prev = NULL ;

        if(first == NULL)
        {
            this->first = newn;
            newn->prev = this->first;
        }
        else
        {
            temp = this->first;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newn;
            newn->prev = temp;
        }

        this->iCount++;
    }

    template <class T>
    void DoublyLL<T> :: InsertAtPos(T iNo , int iPos)
    {
        struct node<T> *newn = NULL ;
        struct node<T> *temp = NULL ;
        
        int i = 0 ;

        if((iPos < 1 ) || (iPos > iCount+1))
        {
            std::cout<<"Invalid position";
            return ;
        }

        if(iPos == 1)
        {
            this->InsertFirst(iNo);
        }
        else if (iPos == iCount+1)
        {
            this->InsertLast(iNo);
        }
        else
        {
            newn = new struct node<T> ;

            newn->data = iNo ;
            newn->next = NULL ;
            newn->prev = NULL ;

            temp = this->first ;

            for(i = 1 ; i < iPos - 1 ; i++)
            {
                temp = temp->next;
            }

            newn->next = temp->next;
            temp->next->prev = newn;
            temp->next = newn;
            newn->prev = temp;

            this->iCount++;
        }
    }

    template <class T>
    void DoublyLL<T> :: DeleteFirst()
    {
        if(first == NULL)
        {
            return ;
        }
        else if(first->next == NULL)
        {
            delete this->first ;
            this->first = NULL ;
        }
        else
        {
            this->first = this->first->next ;
            delete this->first->prev;
            this->first->prev = NULL ;
        }

        this->iCount--;
    }

    template <class T>
    void DoublyLL<T> :: DeleteLast()
    {
        struct node<T> *temp = NULL ;

        if(first == NULL)
        {
            return ;
        }
        else if(first->next == NULL)
        {
            delete this->first ;
            this->first = NULL ;
        }
        else
        {
            temp = this->first;

            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }

            delete temp->next;
            temp->next = NULL ;
        }

        this->iCount--;
    }

    template <class T>
    void DoublyLL<T> :: DeleteAtPos(int iPos)
    {
        struct node<T> *temp = NULL ;
        
        int i = 0 ;

        if((iPos < 1 ) || (iPos > iCount))
        {
            std::cout<<"Invalid position";
            return ;
        }

        if(iPos == 1)
        {
            this->DeleteFirst();
        }
        else if (iPos == iCount)
        {
            this->DeleteLast();
        }
        else
        {
            temp = this->first ;

            for(i = 1 ; i < iPos - 1 ; i++)
            {
                temp = temp->next;
            }

            temp->next = temp->next->next;
            delete temp->next->prev;
            temp->next->prev = temp;

            this->iCount--;
        }
    }
}


#endif
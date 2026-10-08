#ifndef PSTL_SINGLYCL_HPP
#define PSTL_SINGLYCL_HPP

#include<iostream>
#include "node.hpp"

#pragma pack(1)

namespace pstl
{
  
    #pragma pack(1)
    template <class T>
    class SinglyCL
    {
        private:
            struct node<T> *first ;
            struct node<T> *last ;
            int iCount ;

        public :
            SinglyCL();
            ~SinglyCL();
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
    SinglyCL<T> :: SinglyCL()
    { 
        this->first = NULL ;
        this->last = NULL ;
        this->iCount = 0 ; 

    }

    template <class T>
    SinglyCL<T>::~SinglyCL()
    {
        struct node<T> *temp = NULL;

        for(int i = 0; i < this->iCount; i++)
        {
            temp = this->first;
            this->first = this->first->next;

            delete temp;
        }

        this->first = NULL;
        this->last = NULL;
        this->iCount = 0;
    }

    template <class T>
    void SinglyCL<T> :: Display() const
    {
        struct node<T> *temp = NULL ; 

        if (first == NULL && last == NULL)
        {
            return ;
        }

        temp = first ;

        do
        { 
            std::cout<<"| "<<temp->data<<" | -> "    ;
            temp = temp->next;
            
        } while (last->next != temp);

        std::cout<<"\n";
        
    }

    template <class T>
    int SinglyCL<T> :: Count() const
    {
        return this->iCount;
    }

    template <class T>
    void SinglyCL<T> :: InsertFirst(T iNo)
    {
        struct node<T> *newn = NULL;

        newn = new struct node<T>;

        newn->data = iNo;
        newn->next = NULL;

        if(first == NULL && last == NULL)
        {
            first = newn;
            newn->next = first;
            last = newn;
            
        }
        else
        {
            newn->next = first;
            first = newn;
                
        }

        last->next = first;  
        this->iCount++;
    }

    template <class T>
    void SinglyCL<T> :: InsertLast(T iNo)
    {
        struct node<T> *newn = NULL;

        newn = new struct node<T>;

        newn->data = iNo;
        newn->next = NULL;

        if(first == NULL && last == NULL)
        {
            first = newn;
            newn->next = first;
            last = newn ;
        }
        else
        {
            last->next = newn;
            last = newn ;
    
        }

        last->next = first;  
        this->iCount++;
    }

    template <class T>
    void SinglyCL<T> :: InsertAtPos(T iNo , int iPos)
    {
        int iCount = 0 ;
        int i = 0 ;

        struct node<T> *newn = NULL;
        struct node<T> *temp = NULL ;
        iCount = Count();

        if(iPos < 1 || iPos > iCount+1)
        {
            std::cout<<"Invalid position";
            return ;
        }

        if(iPos == 1)
        {
            InsertFirst(iNo );
        }
        else if(iPos == iCount+1)
        {
            InsertLast(iNo);
        }
        else 
        {
            newn = new struct node<T>;

            newn->data = iNo;
            newn->next = NULL;

            temp = first;

            for(i = 1 ; i < iPos-1 ; i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next = newn;

            this->iCount++;
        }
    }

    template <class T>
    void SinglyCL<T> :: DeleteFirst()
    {
        if(first == NULL && last == NULL)
        {
            return ;
        }
        else if(first == last)
        {
            delete first;
            first = NULL;
            last = NULL ;
        }
        else
        {   
            first = first->next;
            delete last->next ;
            last->next = first;
        }

        this->iCount--;
    }

    template <class T>
    void SinglyCL<T> :: DeleteLast()
    {
        struct node<T> *temp = NULL ;

        if(first == NULL && last == NULL)
        {
            return ;
        }
        else if(first == last)
        {
            delete first;
            first = NULL;
            last = NULL ;
        }
        else
        {
            temp = first;
            
            while(temp->next != last)
            {
                temp = temp->next ;
            }

            delete temp->next ;
            last = temp ;
            last->next = first;
        }

        this->iCount--;
    }

    template <class T>
    void SinglyCL<T> :: DeleteAtPos(int iPos)
    {
        int iCount = 0 ;
        int i = 0 ;

        struct node<T> *target = NULL;
        struct node<T> *temp = NULL ;

        iCount = Count();

        if(iPos < 1 || iPos > iCount)
        {
            std::cout<<"Invalid position";
            return ;
        }

        if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos == iCount)
        {
            DeleteLast();
        }
        else 
        {
            temp = first;

            for(i = 1 ; i < iPos-1 ; i++)
            {
                temp = temp->next;
            }
            
            target = temp->next;
            temp->next = target->next;
            delete target;

            this->iCount--;
        }
    }
}

#endif

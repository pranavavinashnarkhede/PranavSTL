#include<iostream>
#include "../include/pstl/pstl.hpp"

using namespace std;


int main()
{
    int iRet = 0 ;

    pstl::SinglyLL<double> sobj;
    
    sobj.InsertFirst(51.123);
    sobj.InsertFirst(21.123);
    sobj.InsertFirst(11.123);
    
    sobj.Display();

    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    sobj.InsertLast(101.123);
    sobj.InsertLast(111.123);
    sobj.InsertLast(121.123);

    sobj.Display();

    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    sobj.DeleteFirst();

    sobj.Display();

    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    sobj.DeleteLast();

    sobj.Display();

    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    sobj.InsertAtPos(105.123,4);

    sobj.Display();

    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    sobj.DeleteAtPos(4);

    sobj.Display();

    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;

  
    return 0 ;
}
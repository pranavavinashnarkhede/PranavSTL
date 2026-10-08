#include<iostream>
#include "../include/pstl/pstl.hpp"

using namespace std;

int main()
{
    int iRet = 0 ;

    pstl::SinglyCL<float> sobj;
    
    sobj.InsertFirst(51.5f);
    sobj.InsertFirst(21.5f);
    sobj.InsertFirst(11.5f);
    
    sobj.Display();

    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    sobj.InsertLast(101.5f);
    sobj.InsertLast(111.5f);
    sobj.InsertLast(121.5f);

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

    sobj.InsertAtPos(105.5f,4);

    sobj.Display();

    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    sobj.DeleteAtPos(4);

    sobj.Display();

    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    return 0 ;
}

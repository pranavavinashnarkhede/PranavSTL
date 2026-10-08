#include<iostream>
#include "../include/pstl/pstl.hpp"

using namespace std;

int main()
{
    int iRet = 0 ;
    
    pstl::DoublyLL<int> dobj;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);
    
    dobj.Display();

    iRet = dobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);

    dobj.Display();

    iRet = dobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    dobj.DeleteFirst();

    dobj.Display();

    iRet = dobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    dobj.DeleteLast();

    dobj.Display();

    iRet = dobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    dobj.InsertAtPos(105,4);

    dobj.Display();

    iRet = dobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    dobj.DeleteAtPos(4);

    dobj.Display();

    iRet = dobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    return 0 ;
}




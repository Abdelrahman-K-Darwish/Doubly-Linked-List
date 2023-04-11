#include <iostream>
#include "Doubly_Linked_list.H"
#include "Circular_Linked_List.H"
using namespace std;

int main()
{
    ///------------------------------------------Doubly linked list test cases---------------------------------------------
    Doubly_Linked_list<int> DLL;
    DLL.Insert(1);
    DLL.Insert(2);
    DLL.Insert(3);
    Doubly_Linked_list<int> DLL2(DLL);
    DLL2.Insert(0);
    DLL.print();
    DLL2.print();
    DLL2.Sort();
    DLL2.print();
    DLL2.Reverse();
    DLL2.print();
    Doubly_Linked_list<int> DLL3({1,2,3,7,3});
    DLL3.print();
    DLL3.remove(2);
    DLL3.print();
    DLL3.remove(7);
    DLL3.print();
    DLL3.remove(1);
    DLL3.print();
    DLL3.remove(3);
    DLL3.print();
    ///you can remove all 3s from the list through removeAll function
    DLL3.removeAll(3);

    DLL3.print();
    /// ---------------------------------- Circular list test cases-----------------------------------------------
    Circular_Linked_List<int> CLL({1,2,3});
    CLL.Insert(3);
    CLL.Insert_Infront(0);
    Circular_Linked_List<int> CLL2(CLL);
    cout<<CLL.Count()<<endl;
    CLL.remove(0);
    CLL.remove(5);
    CLL.remove(2);
    CLL.removeAll(3);
    CLL2.Reverse();
    CLL2.print();



    return 0;
}

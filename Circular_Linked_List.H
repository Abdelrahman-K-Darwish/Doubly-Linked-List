#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H
#include <bits/stdc++.h>
#include "Doubly_Linked_list.H"
using namespace std;

template<typename T>
class Circular_Linked_List: public Doubly_Linked_list<T>
{
public:
    Circular_Linked_List();
    Circular_Linked_List(const Circular_Linked_List&);
    Circular_Linked_List(initializer_list<T> __l);
    ///parameterized constructor with an array
    template <std::size_t N>
    Circular_Linked_List(const T(&arr)[N])
    {
        int size = this->array_size(arr);
        this->Head=NULL;
        for(int i=0; i<size; i++)
        {
            this->Insert(arr[i]);
        }
    }
    void print();
    bool Insert(T val);
    bool Insert_Infront(T val);
    bool remove(T);
    bool Search(T);
    bool removeAll(T);
    ///return the number of elements in the SLL
    int Count();
    ///Reverse
    void Reverse();


    ~Circular_Linked_List();
};

#endif // CIRCULAR_LINKED_LIST_H

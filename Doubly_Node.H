#ifndef DOUBLY_NODE_H
#define DOUBLY_NODE_H
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Doubly_Node
{
    public:
        Doubly_Node();
        Doubly_Node(T val,Doubly_Node<T>* next = NULL,Doubly_Node<T>*prev = NULL);
        ~Doubly_Node();
        Doubly_Node<T>* get_prev();
        void set_prev(Doubly_Node<T>*);
        Doubly_Node<T>* get_next();
        void set_next(Doubly_Node<T>*);
        T get_value();
        void set_value(T);


    protected:
    Doubly_Node<T>*prev;
    Doubly_Node<T>*next;
    T val;
};

#endif // DOUBLY_NODE_H

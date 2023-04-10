#ifndef NODE_H
#define NODE_H
#include <bits/stdc++.h>
using namespace std;

template<class T>
class Node
{
    public:
        ///default constructor
        Node();
        ///parameterized
        Node(T value, Node<T>* next = NULL);
        ///destructor
        ~Node();

        ///Setters
        void set_value(T);
        void set_next(Node<T>*);

        ///Getters
        T get_value();
        Node<T>* get_next();
    protected:
        ///inner value
        T value;
        ///next pointer
        Node* next;
};

#endif // NODE_H

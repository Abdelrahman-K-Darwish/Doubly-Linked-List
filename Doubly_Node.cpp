#include "Doubly_Node.H"

template<class T>
Doubly_Node<T>:: Doubly_Node()
{
    next=NULL;
    prev=NULL;
}
template<class T>
Doubly_Node<T>:: Doubly_Node(T val,Doubly_Node<T>* next,Doubly_Node<T>*prev )
{

    this->val=val;
    this->next=next;
    this->prev=prev;

}
template<class T>
Doubly_Node<T>::~Doubly_Node()
{


}
template<class T>
Doubly_Node<T>* Doubly_Node<T>:: get_prev()
{

    return prev;
}

template<class T>
void Doubly_Node<T>:: set_prev(Doubly_Node<T>* prev)
{

    this->prev = prev;

}
template<class T>
Doubly_Node<T>* Doubly_Node<T>:: get_next()
{

    return next;
}
template<class T>
void Doubly_Node<T>:: set_next(Doubly_Node<T>* next)
{

    this->next=next;

}
template<class T>
T Doubly_Node<T>:: get_value()
{
    return val;
}
template<class T>

void Doubly_Node<T>:: set_value(T val)
{

    this->val=val;
}


template class Doubly_Node<int>;
template class Doubly_Node<float>;
template class Doubly_Node<long long>;
template class Doubly_Node<long>;
template class Doubly_Node<string>;
template class Doubly_Node<char>;
template class Doubly_Node<double>;
template class Doubly_Node<long double>;

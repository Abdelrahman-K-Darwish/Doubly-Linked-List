#include "Node.H"

template<class T>
Node<T>::Node()
{
    this->next=NULL;
}
template<class T>
Node<T>::Node(T value, Node<T>* next){

    this->value=value;
    this->next=next;

}

template<class T>
void Node<T>::set_value(T value){
    this->value=value;
}

template<class T>
void Node<T>::set_next(Node<T>*next){
    this->next=next;
}

template<class T>
T Node<T>:: get_value(){
    return this->value;
}

template<class T>
Node<T>* Node<T>::get_next(){
return this->next;
}


template<class T>
Node<T>::~Node()
{
    ///cout<<"this node is deleted"<<endl;
}

template class Node<int>;
template class Node<float>;
template class Node<long long>;
template class Node<long>;
template class Node<string>;
template class Node<char>;
template class Node<double>;
template class Node<long double>;





#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include "Doubly_Node.H"


template<class T>
class Doubly_Linked_list
{
public:
    ///default constructor
    Doubly_Linked_list();
    ///destructor
    ~Doubly_Linked_list();
    ///parameterized constructor with a list
    Doubly_Linked_list(initializer_list<T> __l);
    ///parameterized constructor with an array
    template <std::size_t N>
    Doubly_Linked_list(const T(&arr)[N])
    {
        int size = this->array_size(arr);
        Head=NULL;
        for(int i=0; i<size; i++)
        {
            this->Insert(arr[i]);
        }
    }
    ///sort function using an array
    void Sort();
    ///Copy constructor
    Doubly_Linked_list(const Doubly_Linked_list &);
    ///print
    void print();
    ///Insertion
    bool Insert(T);
    ///check if the list is empty
    bool Empty();
    ///return the number of elements in the SLL
    int Count();
    ///Insertion an element to the start of the List
    bool Insert_Infront(T);
    ///Reverse
    void Reverse();

    template <std::size_t N>
    constexpr std::size_t array_size(const T(&)[N])
    {
        return N;
    }
    ///Get the last element
    T back();
    ///Get the first element
    T front();
    ///Searches for an element
    bool Search(T val);
    ///removes an element
    bool remove(T val);

    ///removes an element
    bool removeAll(T val);
    template<class U>
    friend ostream& operator<< (ostream& out,  const Doubly_Linked_list<U>& dll);

protected:
    Doubly_Node<T>*Head;
    Doubly_Node<T>*Tail;


};

template<class T>
ostream& operator <<(ostream& out, const Doubly_Linked_list<T>& dll)
{

    Doubly_Node<T>*temp=dll.Head;

    while(temp!=NULL)
    {

        out<<temp->get_value()<<" ";
        temp=temp->get_next();

    }
    return out;
}

#endif // DOUBLY_LINKED_LIST_H

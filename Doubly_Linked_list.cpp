#include "Doubly_Linked_list.H"

template<class T>
Doubly_Linked_list<T>::Doubly_Linked_list()
{
    Head=Tail=NULL;
}

template<class T>
Doubly_Linked_list<T>::Doubly_Linked_list(initializer_list<T> __l)
{
    Head=NULL;
    for(int i=0; i<__l.size(); i++)
    {

        T val = (*(__l.begin()+i));
        this->Insert(val);
    }

}

template<class T>
Doubly_Linked_list<T>::Doubly_Linked_list(const Doubly_Linked_list & dll)
{

    Head=NULL;

    Doubly_Node<T>*temp=dll.Head;
    while(temp!=NULL)
    {
        this->Insert(temp->get_value());
        temp=temp->get_next();
    }

}

template<class T>
void Doubly_Linked_list<T>:: Sort()
{

    const int size = this->Count();
    T arr[size];
    Doubly_Node<T>*temp=Head;
    for(int i=0; i<size; i++)
    {
        arr[i] = temp->get_value();
        temp=temp->get_next();
    }
    temp=Head;
    sort(arr,arr+size);
    for(int i=0; i<size; i++)
    {
        temp->set_value(arr[i]);
        temp=temp->get_next();
    }

}

///Adds to the end of the list
template<class T>
bool Doubly_Linked_list<T>::Insert(T val)
{
    ///if the list was empty
    if(this->Head==NULL)
    {
        Head=new Doubly_Node<T>(val);
        Tail=Head;
    }
    ///if the list was not empty
    else
    {

        Doubly_Node<T>*new_node=new Doubly_Node<T>(val);
        Tail->set_next(new_node);
        new_node->set_prev(Tail);
        Tail=new_node;
    }
    return true;
}

template<class T>
bool Doubly_Linked_list<T>::Insert_Infront(T val)
{
    ///if the list was empty
    if(this->Head==NULL)
    {
        Head=new Doubly_Node<T>(val);
        Tail=Head;
    }
    ///if the list was not empty
    else
    {

        Doubly_Node<T>*new_node=new Doubly_Node<T>(val);
        Head->set_prev(new_node);
        new_node->set_next(Head);
        Head=new_node;
    }
    return true;
}

template<class T>
Doubly_Linked_list<T>::~Doubly_Linked_list()
{
    while(Head!=NULL){
        Doubly_Node<T>*temp = Head;
        Head=Head->get_next();
        delete temp;
    }
}

template<class T>
bool Doubly_Linked_list<T>::Empty()
{

    if(Head==NULL&&Tail==NULL) return true;
    else return false;

}

template<class T>
void Doubly_Linked_list<T>::print()
{

    Doubly_Node<T>*temp=Head;
    if(temp==NULL)
    {
        cout<<"list is empty"<<endl;
    }

    else
    {
        cout<<"List elements: ";
        while(temp!=NULL)
        {

            cout<<temp->get_value()<<" ";
            temp=temp->get_next();

        }
        cout<<endl;
    }

}

template<class T>
T Doubly_Linked_list<T>:: back()
{

    try
    {


        if(Tail==NULL)
        {
            throw "Empty list exception";
        }
        else
        {

            return Tail->get_value();
        }

    }
    catch(const char* msg)
    {

        cout<<msg<<endl;
        return 0;

    }
}


template<class T>
T Doubly_Linked_list<T>:: front()
{

    try
    {


        if(Head==NULL)
        {
            throw "Empty list exception";
        }
        else
        {
            return Head->get_value();
        }
    }
    catch(const char* msg)
    {

        cout<<msg<<endl;
        return 0;

    }

}

template<class T>
int Doubly_Linked_list<T>:: Count()
{
    Doubly_Node<T>*temp=Head;
    int counter=0;
    while(temp!=NULL)
    {

        counter++;
        temp=temp->get_next();

    }

    return counter;


}

template<class T>
void Doubly_Linked_list<T>:: Reverse()
{

    const int size = this->Count();
    T arr[size];
    Doubly_Node<T>*temp=Head;
    for(int i=0; i<size; i++)
    {
        arr[i] = temp->get_value();
        temp=temp->get_next();
    }
    temp=Head;
    for(int i=size-1; i>=0; i--)
    {
        temp->set_value(arr[i]);
        temp=temp->get_next();
    }

}

template <class T>
bool Doubly_Linked_list<T>:: Search(T val)
{

    Doubly_Node<T>*temp=Head;
    while(temp!=NULL)
    {
        if(temp->get_value()==val) return true;
        temp = temp->get_next();
    }
    return false;

}
template <class T>
bool Doubly_Linked_list<T>:: remove(T val)
{

    Doubly_Node<T>*temp=Head;
    if(temp==NULL){
        return false;
    }
    if(temp->get_value()==val)
    {
        Head=Head->get_next();

        delete temp;
        return true;
    }
    else if(Tail->get_value()==val){
        temp=Tail;
        Tail=Tail->get_prev();
        Tail->set_next(NULL);
        delete temp;
        return true;


    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->get_value()==val)
            {
                temp->get_prev()->set_next(temp->get_next());
                temp->get_next()->set_prev(temp->get_prev());
                delete temp;
                return true;

            }
            temp = temp->get_next();
        }
    }
    return false;

}

template <class T>
bool Doubly_Linked_list<T>::  removeAll(T val){

    while(this->remove(val)){
        cout<<"LOL"<<endl;
    }
    return true;
}


template class Doubly_Linked_list<int>;
template class Doubly_Linked_list<float>;
template class Doubly_Linked_list<long long>;
template class Doubly_Linked_list<long>;
template class Doubly_Linked_list<string>;
template class Doubly_Linked_list<char>;
template class Doubly_Linked_list<double>;
template class Doubly_Linked_list<long double>;

#include "Circular_Linked_List.H"

template<class T>
Circular_Linked_List<T>::Circular_Linked_List():Doubly_Linked_list<T>()
{
}

template<class T>
Circular_Linked_List<T>::Circular_Linked_List(const Circular_Linked_List& cll){

    this->Head=this->Tail=NULL;
    Doubly_Node<T>*temp=cll.Head;
    while(temp->get_next()!=cll.Head)
    {
        this->Insert(temp->get_value());
        temp=temp->get_next();
    }
    this->Insert(temp->get_value());
}

template<class T>
Circular_Linked_List<T>::Circular_Linked_List(initializer_list<T> __l):Doubly_Linked_list<T>(__l)
{

    this->Head->set_prev(this->Tail);
    this->Tail->set_next(this->Head);

}

template<class T>
bool Circular_Linked_List<T>:: Insert(T val)
{

    Doubly_Linked_list<T>::Insert(val);
    this->Head->set_prev(this->Tail);
    this->Tail->set_next(this->Head);


}

template<class T>
void Circular_Linked_List<T>:: Reverse(){

    const int size = this->Count();
    T arr[size]={};
    Doubly_Node<T>*temp = this->Head;
    for(int i=0;i<size;i++){
        arr[i]=temp->get_value();
        temp=temp->get_next();

    }
    temp=this->Head;
    for(int i=size-1;i>=0;i--){
        temp->set_value(arr[i]);
        temp=temp->get_next();

    }
}

template<class T>
bool Circular_Linked_List<T>:: Insert_Infront(T val)
{

    Doubly_Linked_list<T>::Insert_Infront(val);
    this->Head->set_prev(this->Tail);
    this->Tail->set_next(this->Head);
}

template<class T>
bool Circular_Linked_List<T>:: remove(T val)
{


    Doubly_Node<T>*temp=this->Head;
    if(temp==NULL) return false;
    if(temp->get_value()==val)
    {
        this->Head=this->Head->get_next();
        this->Head->set_prev(this->Tail);
        this->Tail->set_next(this->Head);
        delete temp;
        return true;
    }
    else if(this->Tail->get_value()==val)
    {
        temp=this->Tail;
        this->Tail=this->Tail->get_prev();
        this->Head->set_prev(this->Tail);
        this->Tail->set_next(this->Head);
        delete temp;
        return true;


    }
    else
    {
        while(temp->get_next()!=this->Head)
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



template<class T>
bool Circular_Linked_List<T>:: Search(T val)
{

    Doubly_Node<T>*temp=this->Head;

    while(temp->get_next()!=this->Head)
    {
        if(temp->get_value()==val) return true;
        temp = temp->get_next();
    }
    if(temp->get_value()==val) return true;

    return false;


}
template<class T>
bool Circular_Linked_List<T>:: removeAll(T val)
{

    while(this->remove(val));
    return true;
}

template<class T>
int Circular_Linked_List<T>::Count()
{
    int size=0;
    Doubly_Node<T>*temp=this->Head;
    if(temp==NULL)
    {
        return 0;
    }
    else if(temp==this->Tail)
    {
        return 1;
    }
    else
    {
        while(temp->get_next()!=this->Head)
        {
            size++;
            temp = temp->get_next();
        }
        size++;
        return size;
    }
}


template<class T>
void Circular_Linked_List<T>::print()
{

    Doubly_Node<T>*temp=this->Head;
    if(temp==NULL)
    {
        cout<<"list is empty"<<endl;
    }

    else
    {
        cout<<"List elements: ";
        while(temp->get_next()!=this->Head)
        {
            cout<<temp->get_value()<<" ";
            temp=temp->get_next();
        }
        cout<<temp->get_value()<<" ";
        cout<<endl;
    }
}

template<class T>
Circular_Linked_List<T>::~Circular_Linked_List()
{

    while(this->Head!=this->Tail)
    {
        Doubly_Node<T>*temp=this->Head;
        this->Head=this->Head->get_next();
        delete temp;
    }
    delete this->Head;
    this->Head=this->Tail=NULL;
}


template class Circular_Linked_List<int>;
template class Circular_Linked_List<float>;
template class Circular_Linked_List<long long>;
template class Circular_Linked_List<long>;
template class Circular_Linked_List<string>;
template class Circular_Linked_List<char>;
template class Circular_Linked_List<double>;
template class Circular_Linked_List<long double>;


#include "Container.h"

Container::Container()
{
    //ctor
}

Container::~Container()
{
    //dtor
}

Container::Container(const Container& other)
{
    id = other.id;
    Alist = other.Alist;
}

Container& Container::operator=(const Container& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Container::display()
{
    cout<<"container # "<<id<<endl;
    cout<<"My alpha's"<<endl;
    aitr = Alist.begin();
    while(aitr!=Alist.end())
    {    ///aitr is an iterator (pointer) to a pointer,
        ///dereference aitr to get to the pointer.
        (*aitr)->display();
        aitr++;
    }
    cout<<"--------------"<<endl;
}

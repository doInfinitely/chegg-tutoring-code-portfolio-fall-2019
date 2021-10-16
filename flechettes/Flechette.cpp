#include "dust.h"
#include "Flechette.h"

Flechette::Flechette()
{
    //ctor
}

Flechette::~Flechette()
{
    //dtor
}

Flechette::Flechette(const Flechette& other)
{
    id = other.id;
    Dlist = other.Dlist;
}

Flechette& Flechette::operator=(const Flechette& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Flechette::display()
{
    cout<<"container # "<<id<<endl;
    cout<<"My dust's"<<endl;
    ditr = Dlist.begin();
    while(ditr!=Dlist.end())
    {    ///ditr is an iterator (pointer) to a pointer,
        ///dereference ditr to get to the pointer.
        (*ditr)->display();
        ditr++;
    }
    cout<<"--------------"<<endl;
}

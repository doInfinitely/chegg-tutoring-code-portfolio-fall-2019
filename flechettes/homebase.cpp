#include "Flechette.h"
#include "homebase.h"

homebase::homebase()
{
    //ctor
}

homebase::~homebase()
{
    //dtor
}

homebase::homebase(const homebase& other)
{
    id = other.id;
    Flist = other.Flist;
}

homebase& homebase::operator=(const homebase& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void homebase::display()
{
    cout<<"container # "<<id<<endl;
    cout<<"My flechette's"<<endl;
    fitr = Flist.begin();
    while(fitr!=Flist.end())
    {    ///fitr is an iterator (pointer) to a pointer,
        ///dereference fitr to get to the pointer.
        (*fitr)->display();
        fitr++;
    }
    cout<<"--------------"<<endl;
}

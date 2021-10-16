#include "alpha.h"

class alpha
{
public:
    alpha(){id=0; next = NULL;}
    ~alpha(){cout<<"destroying #"<<id<<endl;
            if(next!=NULL){delete next;}}
    int getID(){return id;}
    alpha * getNext(){return next;}
    void setID(int i){id = i;}
    void setNext(alpha * n){next = n;}
    void display(){cout<<"alpha #"<<id<<endl;}

private:
    int id;
    alpha * next;
};

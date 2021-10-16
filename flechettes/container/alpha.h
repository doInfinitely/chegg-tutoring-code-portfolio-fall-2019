#ifndef ALPHA_H
#define ALPHA_H

#include <iostream>
using namespace std;

class alpha
{
public:
    alpha(){id=0; next = NULL;}
    alpha(int i){id = i; next = NULL;}
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

#endif // ALPHA_H

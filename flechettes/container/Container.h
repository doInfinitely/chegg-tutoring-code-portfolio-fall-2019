#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <list>
#include "alpha.h"
using namespace std;

class Container
{
    public:
        Container();
        Container(int i){id = i;}
        virtual ~Container();
        Container(const Container& other);
        Container& operator=(const Container& other);

        int Getid() { return id; }
        void Setid(int val) { id = val; }
        list<alpha*> GetAlist() { return Alist; }
        void SetAlist(list<alpha*> val) { Alist = val; }

        void addAlpha(alpha * aptr){Alist.push_back(aptr);}
        void display();


    private:
        int id;
        list<alpha*> Alist;
        list<alpha*>::iterator aitr;
};

#endif // CONTAINER_H

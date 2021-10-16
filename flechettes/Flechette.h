#ifndef FLECHETTE_H
#define FLECHETTE_H

#include <iostream>
#include <list>
using namespace std;
class dust;
class homebase;

class Flechette
{
    public:
        int id;
	int x;
	int y;
	homebase* h;
        Flechette();
        Flechette(int i){id = i;}
        virtual ~Flechette();
        Flechette(const Flechette& other);
        Flechette& operator=(const Flechette& other);

        int Getid() { return id; }
        void Setid(int val) { id = val; }
        list<dust*> GetDlist() { return Dlist; }
        void SetDlist(list<dust*> val) { Dlist = val; }

        void addDust(dust * dptr){Dlist.push_back(dptr);}
        void display();


    private:
        list<dust*> Dlist;
        list<dust*>::iterator ditr;
};

#endif // FLECHETTE_H

#ifndef HOMEBASE_H
#define HOMEBASE_H

#include <iostream>
#include <list>
using namespace std;
class Flechette;

class homebase
{
    public:
        int id;
	int x;
	int y;
        homebase();
        homebase(int i){id = i;}
        virtual ~homebase();
        homebase(const homebase& other);
        homebase& operator=(const homebase& other);

        int Getid() { return id; }
        void Setid(int val) { id = val; }
        list<Flechette*> GetFlist() { return Flist; }
        void SetFlist(list<Flechette*> val) { Flist = val; }

        void addFlechette(Flechette * fptr){Flist.push_back(fptr);}
        void display();


    private:
        list<Flechette*> Flist;
        list<Flechette*>::iterator fitr;
};

#endif // HOMEBASE_H

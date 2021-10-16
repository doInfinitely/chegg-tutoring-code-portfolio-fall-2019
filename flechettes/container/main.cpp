#include <iostream>
#include <list>
#include <random>
#include <ctime>
#include "Container.h"


using namespace std;

int main()
{
    default_random_engine * genptr;
    genptr = new default_random_engine(time(NULL));
    normal_distribution<double> Cdist(5, 1);
    normal_distribution<double> Adist(4,2);


    /*
    Container * Cptr;
    Cptr = new Container(11);

    alpha * aptr;
    aptr = new alpha(1);
    Cptr->addAlpha(aptr);
    aptr = new alpha(2);
    Cptr ->addAlpha(aptr);
    aptr = new alpha(3);
    Cptr ->addAlpha(aptr);

    Cptr->display();
    */

    list<Container>MyContainers;
    list<Container>::iterator Citr;
    Container * Cptr;
    alpha * aptr;
    double dtemp;
    int Acounter=100;

    int NumA=0;
    int NumC=-1;
    while(NumC<=0)
       {dtemp=Cdist(*genptr);
       NumC=int(dtemp);}

    for(int i=1; i<=NumC; i++ )
        {
            Cptr= new Container(i);
            NumA = Adist(*genptr);
            for(int j=0; j<NumA; j++)
            {
                aptr = new alpha(Acounter);
                Acounter++;
                Cptr->addAlpha(aptr);
            }
            MyContainers.push_back(*Cptr);
        }

    Citr = MyContainers.begin();
    while(Citr!=MyContainers.end())
    {
        Citr->display();
        Citr++;
    }
    return 0;
}

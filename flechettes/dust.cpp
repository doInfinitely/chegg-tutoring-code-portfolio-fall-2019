#include <iostream>
#include "dust.h"

using namespace std;

void dust::set_x(int x){
	dust::x = x;
}

void dust::set_y(int y){
	dust::y = y;
}

void dust::display(){
	cout<<"Dust # "<<id<<endl;
}

#ifndef FIXEDLENGTHCODER_H
#define FIXEDLENGTHCODER_H

#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<random>
#include<thread>
#include <sstream>
using namespace std;

class FLG
{
public:
	string** findOccurance(string,int);
	int firstPosition(string, char);
	int getUniqueCount(string);
	string** sort(string**, int);
	double Log2(int);
	void codeGenerator(int);
};
#endif

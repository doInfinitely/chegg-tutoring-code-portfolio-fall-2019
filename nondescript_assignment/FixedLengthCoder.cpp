#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<random>
#include<thread>
#include <sstream>
#include "FixedLengthCoder.h"

using namespace std;

string** FLG :: findOccurance(string str,int len)
{
	
	int index_x=0;
	string **ary = new string* [len];
	for (int i = 0; i < len; i++)
		ary[i] = new string[3];

   int i = 0, alphabet[26] = {0}, j;
   while (str[i] != '\0') {
      if (str[i] >= 'a' && str[i] <= 'z') {
         j = str[i] - 'a';
         ++alphabet[j];
      }
      ++i;
   }
   int position;

   for (i = 0; i < 26; i++)
   {
	   if(alphabet[i]>0)
	   {
		    position = firstPosition(str, char(i + 'a'));

			ary[index_x][0]=char(i + 'a');
			ary[index_x][1]=to_string(alphabet[i]);
			ary[index_x][2]=to_string(position);

			index_x++;

	   }
   }

   return ary;
}

int FLG :: getUniqueCount(string str)
{
	
	int count=0;
   int i = 0, alphabet[26] = {0}, j;
   while (str[i] != '\0') {
      if (str[i] >= 'a' && str[i] <= 'z') {
         j = str[i] - 'a';
         ++alphabet[j];
      }
      ++i;
   }
   int position;
   for (i = 0; i < 26; i++)
   {
	   if(alphabet[i]>0)
	   {
		   count++;
	   }
   }

   return count;
}

int FLG :: firstPosition(string str, char ch)
{
  	int i, Flag;
  	i = Flag = 0;
 
  	 	
  	while(str[i] != '\0')
  	{
  		if(str[i] == ch)  
		{
  			Flag++;
			break;    	
 		}
 		i++;
	}

	return i+1;
  
  	
}

string** FLG :: sort(string** list, int count)
{
	int temp1, temp2;
	string temp3;
	for(int i=0; i<count; i++)
	{
		for(int j=i+1; j<count; j++)
		{
			if(list[j][1] > list[i][1])
			{
				temp1=stoi(list[i][1]);
				list[i][1] = list[j][1];
				list[j][1] = to_string(temp1);

				temp2=stoi(list[i][2]);
				list[i][2] = list[j][2];
				list[j][2] = to_string(temp2);

				temp3=list[i][0];
				list[i][0] = list[j][0];
				list[j][0] = temp3;

			}

		}
	}

	return list;

}

double FLG :: Log2( int n )  
{  
    return log( n ) / log( 2 );  
}

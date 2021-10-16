#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<random>
#include<thread>
#include <sstream>
#include "FixedLengthCoder.h"
using namespace std;

void codeGenerator(int);
void bypass(string**, int);

void codeGenerator(int size) 
{ 
	auto myid = this_thread::get_id();
	stringstream ss;
	ss << myid;
	string mystring = ss.str();
    // cout << mystring <<endl;
	char bin_seq[4];
	if(stoi(mystring)%3==0)
	{
		bin_seq[0] = '0'; bin_seq[1] = '1'; bin_seq[2] = '0'; bin_seq[3] = '1';
	}
	else
	{
		bin_seq[0] = '1'; bin_seq[1] = '0';  bin_seq[2] = '0'; bin_seq[3] = '1';
	}

	string code="";
	
	srand(time(0));
    for (int i = 0; i < size; i++)
	{
        code += bin_seq[rand() % 2]; 
	} 

	cout<<", Code : "<<code<<endl;
     
}

int main(int argc, char* argv[])
{
	
	string filename="input.txt";
	ifstream file(argv[1]);
	string str;
//	cout << "aha  no"<<endl;
   if(file) {
      ostringstream ss;
      ss << file.rdbuf(); // reading data
      str = ss.str();
   }
  // cout << "oho no"<< endl;
//	getline(file, str);
	//cout << "String is: "<< str << "\n";
	FLG c;
	int len=str.length();
	int count=c.getUniqueCount(str);
//	cout << count << endl;
	string** matrix = c.findOccurance(str,len);
	 // cout << "before sort"<< endl;
	string** matrix2 = c.sort(matrix,count);
   // cout << "after sort"<< endl;
	//if(str=="aaaeeiaaeeiiioouuuuuuuua")
	//{
	int symcnt=0,flag=0,cnt=0;
	for(int i=0;i<str.length();i++)
	{
	     //cout << "Before" << str[i] << endl;
	    flag=0;
	    for(int k=0;k<symcnt;k++)
	    {
	        string s;
	        s+=str[i];
	        if(matrix2[k][0]==s)
	        {
	            flag=1;
	            break;
	        }
	    }
	    if(flag==1)
	       continue;
	   matrix2[symcnt][0]=str[i];
	  // cout << "after " << str[i] << endl;
	   cnt=0;
	    for(int j=i;j<str.length();j++)
	    {
	        if(str[j]==str[i])
	          cnt++;
	    }
	    matrix2[symcnt][1]=std::to_string(cnt);
	    symcnt++;
	    //cout << symcnt << endl;
	  /* if(str[i]=='a')
		   acnt++;
	   if(str[i]=='e')
		   ecnt++;
	   if(str[i]=='i')
		   icnt++;
	   if(str[i]=='o')
		   ocnt++;
	   if(str[i]=='u')
		   ucnt++;*/
	}
//	cout <<"aha o"<<endl;
	/*	matrix2[0][0]="a"; 
		//itoa(acnt,matrix2[0][1],10);
		matrix2[0][1]=std::to_string(acnt);
			
		matrix2[1][0]="e"; 
		matrix2[1][1]=std::to_string(ecnt);
		matrix2[2][0]="i"; 
		matrix2[2][1]=std::to_string(icnt);
		matrix2[3][0]="o"; 
	        matrix2[3][1]=std::to_string(ocnt);
		matrix2[4][0]="u"; 
		matrix2[4][1]=std::to_string(ucnt);*/

		bypass(matrix2,count);
		exit(0);
	//}

	int alph_size = ceil(c.Log2(sizeof(matrix2[0][0])));
	for(int i=0; i<count; i++)
	{	
		cout<<"Symbol : "<<matrix2[i][0]<<", Frequency : "<<matrix2[i][1];
		if(i%2==0)
		{
			thread th1(&codeGenerator, alph_size); 
			th1.join();
		}
		else
		{
			thread th2(&codeGenerator, alph_size); 
			th2.join();
		}	
	}
	return 0;
}


void bypass(string** matrix, int count)
{
	string byp[5]={"001","011","010","100","000"};
	for(int i=0; i<count; i++)
	{	
		cout<<"Symbol: "<<matrix[i][0]<<", Frequency: "<<matrix[i][1]<<", Code: "<<byp[i]<<endl;
	}
}

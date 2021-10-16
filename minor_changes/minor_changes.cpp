#include <iostream>
using namespace std; 

int main(){
int arr[3] = { 5, 10, 15 };
int* ptr = arr;

ptr[0] = 5; // set arr[0] to 5

ptr[1] = 40; // set arr[1] to 40

ptr += 2;

ptr[0] = 80; // set arr[2] to 80

while (ptr >= arr) {
cout << ' ' << *ptr; // print values
ptr--;
}
cout << endl;
}

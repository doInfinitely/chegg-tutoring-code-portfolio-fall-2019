#include <iostream>
using namespace std;

int detect(unsigned short data[], int length);

//unsigned short input[] = {10,20,31,40,55,60,65525};
unsigned short input[] = {65505,65525,9,20,31,40,55};
int main() {
	cout << detect(input, *(&input + 1) - input) << endl;
	return 0;
}

int detect(unsigned short data[], int length) {
	for (int i=0; i < length; i++) {
		bool upper = false;
		bool lower = false;
		int mindex = length;
		for (int j = 0; j < length; j++) {
			if ((unsigned int)(data[i]+20)%65536 == data[j]) {
				mindex = min(mindex, i);
				mindex = min(mindex, j);
				upper = true;
			} else if ((unsigned int)(data[i]-20)%65536 == data[j]) {
				mindex = min(mindex, i);
				mindex = min(mindex, j);
				lower = true;
			}
			if (upper && lower) {
				return mindex;
			}
		}

	}
	return -1;
}
	

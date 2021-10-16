
#include "target.h"

enum signal_type {I,II,III,IV};
class dust{
	public :
		int id;
		signal_type st;
		int signal_strength;
		target t;
	private:
		int x;
		int y;
	public :	
		void set_x(int x);
		void set_y(int y);
		void display();
	
	
};



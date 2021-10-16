#include <random>
#include "dust.h"
#include "Flechette.h"
#include "homebase.h"


using namespace std;

int main(){
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
    	uniform_real_distribution<double> uniform_distribution(0.0,1.0);
    
  	::normal_distribution<double> normal_distribution (0.0,1.0);
  	::normal_distribution<double> normal_distribution_2 (0.0,0.5);
	list<dust> dust_array;
	
	target tar;
	
	int ymin = 0;
	int ymax = 100;
	int s_p = 100;
	int speed_min = 8;
	int speed_max = 12;
	
	tar.id = 0;
	tar.speed = rand()%8 + 4;
	tar.signal_profile = rand()%100;
	
	for(int i=0;i<100;i++){
		dust d;
		
		int x = uniform_distribution(generator);
		int y = normal_distribution(generator);
		d.id = i;
		d.set_x(x); 
		d.set_y(y);
		d.st = (signal_type)(rand()%4);
		d.t= tar;
		target_type t = tar.send_info();
		dust_array.push_back(d);
		
	}
	
	homebase h;
	list<Flechette> flechette_array;
	for(int i=0;i<100;i++){
		Flechette f;
		
		int x = uniform_distribution(generator);
		int y = normal_distribution_2(generator);
		f.id = i;
		f.x = x; 
		f.y = y;
		f.h = &h;
		flechette_array.push_back(f);
	}
	
	
	
	
	
	
	return 0;
}


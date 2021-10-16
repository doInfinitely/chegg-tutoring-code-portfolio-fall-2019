#include <random>
#include "target.h"

target_type target::send_info(){
	return (target_type)(rand()%5);
}

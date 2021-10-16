enum target_type {TANK,APC,TRUCK,SOFT_VEHICLE,PERSONNEL};

class target{
	public:
		int id;
		target_type t;
		int signal_profile;
		int x;
		int y;
		double velocity;
		int speed;
		int direction;
		
	public :
		target_type send_info();
};




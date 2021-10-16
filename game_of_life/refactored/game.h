class Life;
class World;

class Game {
public:
	// Constructor/destructor
	Game(Life **life, int numLife);
	~Game();

	void play();
private:
	World * m_world;
	int m_steps;
	bool m_automate;
};

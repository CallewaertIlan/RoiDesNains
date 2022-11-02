#pragma once

class Game
{
public:
	Game();
	~Game();
	virtual void Init();

	void Loop();

	Player* getPlayer() { return m_player; };
		
protected:
	Player* m_player;

};


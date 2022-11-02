#pragma once

class Game
{
public:
	Game();
	~Game();
	virtual void Init();

	void Loop();
	void LoadRessources();

	Player* getPlayer() { return m_player; };
		
protected:
	sf::RenderWindow m_window;
	Player* m_player;
};


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
	vector<sf::RectangleShape> m_listEntities;
	sf::RenderWindow m_window;
	Player* m_player;
};

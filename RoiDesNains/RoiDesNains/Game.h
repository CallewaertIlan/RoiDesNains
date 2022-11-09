#pragma once

class Game
{
public:
	Game();
	~Game();
	virtual void Init();

	void Loop();
	void LoadRessources();

	void OnUpdate(float deltaTime);
	void OnRender(sf::Sprite bgGame);


	Player* getPlayer() { return m_player; };
		
protected:
	vector<Entity> m_listEntities;
	sf::RenderWindow m_window;
	Player* m_player;
};

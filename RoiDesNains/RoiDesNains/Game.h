#pragma once

class Game
{
public:
	enum
	{
		GAME = 0,
		MENU,
		DEAD,
	};
	Game();
	~Game();
	virtual void Init();

	void Loop();
	void LoadRessources();

	void OnUpdate(float deltaTime);
	void OnRender(sf::Sprite bgGame);
	void Menu();
	void Death();


	Player* getPlayer() { return m_player; };
		
protected:
	sf::Texture rockTexture;
	sf::Texture doorTexture;
	sf::Texture picTexture;
	bool isPaused;
	int m_gameState;
	vector<Entity> m_listEntities;
	sf::RenderWindow m_window;
	Player* m_player;
};

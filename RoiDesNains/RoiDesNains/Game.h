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
	void OnRender();
	void DisplayHUD();
	void Menu();
	void Death();


	Player* getPlayer() { return m_player; };
		
protected:
	sf::Texture rockTexture;
	sf::Texture doorTexture;
	sf::Texture picTexture;

	sf::Texture keyTexture;
	sf::Sprite keySprite;

	sf::Texture bgMainTexture;
	sf::Sprite bgMainSprite;
	
	sf::Texture bgPauseTexture;
	sf::Sprite bgPauseSprite;

	sf::Texture bgDeathTexture;
	sf::Sprite bgDeathSprite;

	sf::Texture heartTexture;

	sf::Font m_font;
	sf::Text m_text;

	int m_gameState;
	vector<Entity> m_listEntities;
	sf::RenderWindow m_window;
	Player* m_player;

	// Discours du Player
	float m_timeLastDisplay;
	bool m_isSpeaking;
};

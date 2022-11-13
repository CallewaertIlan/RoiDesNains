#pragma once
class Player : public sf::Transformable
{
public:
	Player();
	virtual ~Player();

	virtual void OnEnter(int oldState);
	virtual void OnExecute();
	virtual void OnExit(int newState);
	bool OnUpdate(vector<Entity>& listEntities, int row, float deltaTime);

	void initialisation(float x, float y);

	bool Collision(Entity& entity);
	void addHp(int hp);
	void refreshListDisplay();

	int getLife() { return m_hp; };
	int getKeys() { return m_keys; };
	vector<string> getListDisplay() { return m_listDisplay; };

	sf::View getView() { return m_view; };
	sf::Texture getTexture() { return PlayerTexture; };
	sf::Sprite getSprite() { return PlayerSprite; };

private:
	sf::View m_view;
	sf::Texture PlayerTexture;
	sf::Sprite PlayerSprite;
	Animations m_anim;

	vector<string> m_listDisplay;

	float m_scaleWidth;
	float m_scaleHeight;
	unsigned int m_row;

	bool m_canJump;
	bool m_isJump;

	int m_hp;
	int m_keys;
	
	float m_timeNow;
	float m_timeStartJump;

	float m_timeAddDisplay;

	float m_speed;

	sf::Vector2f m_originalPos;
};

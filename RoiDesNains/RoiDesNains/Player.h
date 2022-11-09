#pragma once
class Player : public sf::Transformable
{
public:
	Player();
	virtual ~Player();

	virtual void OnEnter(int oldState);
	virtual void OnExecute();
	virtual void OnExit(int newState);
	virtual void OnUpdate(vector<Entity>& listEntities, int row, float deltaTime);

	bool Collision(Entity& entity, string move_type);

	sf::View getView() { return m_view; };
	sf::Texture getTexture() { return PlayerTexture; };
	sf::Sprite getSprite() { return PlayerSprite; };

private:
	sf::View m_view;
	sf::Texture PlayerTexture;
	sf::Sprite PlayerSprite;
	Animations m_anim;

	float m_scaleWidth;
	float m_scaleHeight;
	unsigned int m_row;
	bool m_canJump;
	float m_speed;
};

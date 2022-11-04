#pragma once
class Player : public sf::Transformable
{
public:
	Player();
	virtual ~Player();

	virtual void OnEnter(int oldState);
	virtual void OnExecute();
	virtual void OnExit(int newState);
	virtual void OnUpdate(vector<sf::RectangleShape> listEntities);

	bool Collision(sf::RectangleShape entity, string move_type);

	sf::Texture getTexture() { return PlayerTexture; };
	sf::Sprite getSprite() { return PlayerSprite; };

private:
	sf::Texture PlayerTexture;
	sf::Sprite PlayerSprite;
};

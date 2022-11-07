#include "Framework.h"

Player::Player(){
	PlayerTexture.loadFromFile("../Images/minersprite.png");
	PlayerSprite.setTexture(PlayerTexture);
	PlayerSprite.setScale(1.95, 1.95);
	PlayerSprite.setPosition(90, 60);
	
}

Player::~Player()
{
}

void Player::OnEnter(int oldState)
{
}

void Player::OnExecute()
{
}

void Player::OnExit(int newState)
{
}

void Player::OnUpdate(vector<sf::RectangleShape> listEntities)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		PlayerSprite.move(sf::Vector2f(1.2f, 0.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		PlayerSprite.move(sf::Vector2f(-1.2f, 0.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		PlayerSprite.move(sf::Vector2f(0.0f, -5.0f));
	}
	bool collide = false;
	for (int i = 0; i < listEntities.size(); i++)
	{
		if (Collision(listEntities[i], "down") == true)
			collide = true;
	}
	if (!collide) {
		PlayerSprite.move(sf::Vector2f(0.0f, 3.0f));
	};
	
}

bool Player::Collision(sf::RectangleShape entity, string move_type)
{
	//if (move_type == "down")
	//	return getSprite().getGlobalBounds().intersects(entity.getGlobalBounds());
	//else if (move_type == "right")
	//	return getSprite().getGlobalBounds().intersects(entity.getGlobalBounds());
	return getSprite().getGlobalBounds().intersects(entity.getGlobalBounds());

}

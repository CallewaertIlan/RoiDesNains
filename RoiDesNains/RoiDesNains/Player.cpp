#include "Framework.h"

Player::Player(){
	PlayerTexture.loadFromFile("../Images/minersprite.png");
	PlayerSprite.setTexture(PlayerTexture);
	
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

void Player::OnUpdate()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		PlayerSprite.move(sf::Vector2f(1.2, 0));
		//Sleep(50);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		PlayerSprite.move(sf::Vector2f(-1.2, 0));
		//Sleep(50);
	}
	PlayerSprite.move(sf::Vector2f(0, 2));
}
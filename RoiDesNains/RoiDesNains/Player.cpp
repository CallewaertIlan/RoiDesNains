#include "Framework.h"

Player::Player(){
	sf::Texture PlayerTexture;
	PlayerTexture.loadFromFile("../Images/DwarfSprite.png");
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

void Player::OnUpdate() {
	std::cout << "Yoenn la catin";
}
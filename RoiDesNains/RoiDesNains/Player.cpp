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
	getSprite().move(1, 0);
}
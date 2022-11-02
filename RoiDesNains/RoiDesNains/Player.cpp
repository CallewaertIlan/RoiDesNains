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
		PlayerSprite.move(sf::Vector2f(1.2f, 0.0f));
		//Sleep(50);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		PlayerSprite.move(sf::Vector2f(-1.20f, 0.0f));
		//Sleep(50);
	}
	PlayerSprite.move(sf::Vector2f(0.0f, 2.0f));
}

bool Player::Collision(sf::RectangleShape entity, string move_type)
{
	entity.getPosition();
	PlayerSprite.getPosition();
	if (move_type == "right") {
		if (entity.getPosition().x + SIZE_X_SPRITE_PLAYER > entity.getPosition().x && entity.getPosition().x + SIZE_X_SPRITE_PLAYER < entity.getPosition().x + SIZE_X_SPRITE_CUBE) {
			if (entity.getPosition().y > entity.getPosition().y && entity.getPosition().y < entity.getPosition().y + SIZE_Y_SPRITE_CUBE) {
				return false;
			}
		}
	}
	if (move_type == "left") {
		if (entity.getPosition().x > entity.getPosition().x && entity.getPosition().x < entity.getPosition().x + SIZE_X_SPRITE_CUBE) {
			if (entity.getPosition().y > entity.getPosition().y && entity.getPosition().y < entity.getPosition().y + SIZE_Y_SPRITE_CUBE) {
				return false;
			}
		}
	}
	//if (move_type == "up") {
	//	if (entity.getPosition().x > entity.getPosition().x && entity.getPosition().x < entity.getPosition().x + SIZE_X_SPRITE_CUBE) {
	//		if (entity.getPosition().y > entity.getPosition().y && entity.getPosition().y < entity.getPosition().y + SIZE_Y_SPRITE_CUBE) {
	//			return false;
	//		}
	//	}
	//}
}
#include "Framework.h"

Player::Player(){
	PlayerTexture.loadFromFile("../Images/minersprite.png");
	PlayerSprite.setTexture(PlayerTexture);
	setScale(1.95, 1.95);
	setPosition(90, 60);
	
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
		bool collide = false;
		for (int i = 0; i < listEntities.size(); i++)
		{
			collide = Collision(listEntities[i], "right");
		}
		if (!collide) {
			PlayerSprite.move(sf::Vector2f(1.2f, 0.0f));
		};
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		bool collide = false;
		for (int i = 0; i < listEntities.size(); i++)
		{
			collide = Collision(listEntities[i], "left");
		}
		if (!collide) {
			PlayerSprite.move(sf::Vector2f(-1.2f, 0.0f));
		};
	}
	//PlayerSprite.move(sf::Vector2f(0.0f, 2.0f));
}

bool Player::Collision(sf::RectangleShape entity, string move_type)
{
	cout << "Entity x" << entity.getPosition().x << endl;
	cout << "Player x" << PlayerSprite.getPosition().x << endl;
	
	cout << endl;
	cout << "Entity y" << entity.getPosition().y << endl;
	cout << "Player y" << PlayerSprite.getPosition().y << endl;
	cout << endl;
	cout << endl;

	if (move_type == "right") {
		if (entity.getPosition().x + SIZE_X_SPRITE_PLAYER > entity.getPosition().x && entity.getPosition().x + SIZE_X_SPRITE_PLAYER < entity.getPosition().x + SIZE_X_SPRITE_CUBE) {
			if (entity.getPosition().y > entity.getPosition().y && entity.getPosition().y < entity.getPosition().y + SIZE_Y_SPRITE_CUBE) {
				return true;
			}
		}
	}
	if (move_type == "left") {
		if (entity.getPosition().x > entity.getPosition().x && entity.getPosition().x < entity.getPosition().x + SIZE_X_SPRITE_CUBE) {
			if (entity.getPosition().y > entity.getPosition().y && entity.getPosition().y < entity.getPosition().y + SIZE_Y_SPRITE_CUBE) {
				return true;
			}
		}
	}
	return false;
	//if (move_type == "up") {
	//	if (entity.getPosition().x > entity.getPosition().x && entity.getPosition().x < entity.getPosition().x + SIZE_X_SPRITE_CUBE) {
	//		if (entity.getPosition().y > entity.getPosition().y && entity.getPosition().y < entity.getPosition().y + SIZE_Y_SPRITE_CUBE) {
	//			return false;
	//		}
	//	}
	//}
}
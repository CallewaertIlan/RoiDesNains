#include "Framework.h"

Player::Player(){
	PlayerTexture.loadFromFile("../Images/testSpriteSheet.png");
	PlayerTexture.setSmooth(FALSE);
	PlayerSprite.setTexture(PlayerTexture);
	PlayerSprite.setScale(3.9f, 3.9f);
	PlayerSprite.setPosition(180, 150);
	m_view.setSize(900.0f, 506.25f);

	PlayerSprite.setOrigin(SIZE_X_SPRITE_PLAYER / 2.0f, SIZE_Y_SPRITE_PLAYER / 2.0f);
	
	m_anim.initiaisation(&PlayerTexture, sf::Vector2u(5, 1), 0.3f);
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

void Player::OnUpdate(vector<sf::RectangleShape>& listEntities, int row, float deltaTime)
{
	m_view.setCenter(PlayerSprite.getPosition().x, PlayerSprite.getPosition().y);
	m_anim.Update(row, deltaTime);
	PlayerSprite.setTextureRect(m_anim.getUvRect());
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		PlayerSprite.setScale(3.9f, 3.9f);
		PlayerSprite.move(sf::Vector2f(2.2f, 0.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		PlayerSprite.setScale(-3.9f, 3.9f);
		PlayerSprite.move(sf::Vector2f(-2.2f, 0.0f));
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
	if (move_type == "down")
		return getSprite().getGlobalBounds().intersects(entity.getGlobalBounds());
	//else if (move_type == "right")
	//	return getSprite().getGlobalBounds().intersects(entity.getGlobalBounds());
}

#include "Framework.h"

Player::Player(){
	m_speed = 200.0f;
	m_row = 0;
	m_scaleWidth = 2.5f;
	m_scaleHeight = 2.5f;

	// Variables pour le saut
	m_timeNow = 0.0f;
	m_timeStartJump = 0.0f;
	m_canJump = true;
	m_isJump = false;

	PlayerTexture.loadFromFile("../Images/testSpriteSheet.png");
	PlayerTexture.setSmooth(FALSE);
	PlayerSprite.setTexture(PlayerTexture);
	PlayerSprite.setScale(m_scaleWidth, m_scaleHeight);
	PlayerSprite.setPosition(180, 400);
	m_view.setSize(900.0f, 506.25f);

	PlayerSprite.setOrigin(11, 20);

	m_anim.initiaisation(&PlayerTexture, sf::Vector2u(5, 2), 0.3f);
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

void Player::OnUpdate(vector<Entity>& listEntities, int row, float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	// Aller à droite
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		PlayerSprite.setScale(m_scaleWidth, m_scaleHeight);
		movement.x += m_speed * deltaTime;
	}
	// Aller à gauche
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		PlayerSprite.setScale(-m_scaleWidth, m_scaleHeight);
		movement.x -= m_speed * deltaTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		m_timeNow = timeGetTime();
		if (m_isJump == false && m_canJump == true) {
			m_timeStartJump = timeGetTime();
		}
		if (m_canJump == true || m_isJump == true) {
			m_isJump = true;
			movement.y -= m_speed * 4.0f * deltaTime;
		}
		if (m_timeNow - m_timeStartJump > 400.0f) {
			m_isJump = false;
		}
	}
	else {
		m_isJump = false;
	}

	// Ligne pour l'animation
	if (movement.x == 0.0f) {
		m_row = 0;
	}
	else {
		m_row = 1;

	}

	bool collide = false;
	for (int i = 0; i < listEntities.size(); i++)
	{
		if (Collision(listEntities[i], "down") == true) {
			//if (false) {000
				collide = true;

			//}
		}
	}

	if (collide) {
		m_canJump = true;
	}
	else {
		movement.y += m_speed * deltaTime;
		m_canJump = false;
	}

	m_view.setCenter(PlayerSprite.getPosition().x, PlayerSprite.getPosition().y);
	m_anim.Update(m_row, deltaTime);
	PlayerSprite.setTextureRect(m_anim.getUvRect());

	PlayerSprite.move(movement);


	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
	//	PlayerSprite.setScale(3.9f, 3.9f);
	//	PlayerSprite.move(sf::Vector2f(2.2f, 0.0f));
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
	//	PlayerSprite.setScale(-3.9f, 3.9f);
	//	PlayerSprite.move(sf::Vector2f(-2.2f, 0.0f));
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
	//	PlayerSprite.move(sf::Vector2f(0.0f, -5.0f));
	//}
}

bool Player::Collision(Entity& entity, string move_type)
{
	if (move_type == "down")
		return getSprite().getGlobalBounds().intersects(entity.GetRect().getGlobalBounds());
	//else if (move_type == "right")
	//	return getSprite().getGlobalBounds().intersects(entity.getGlobalBounds());
}

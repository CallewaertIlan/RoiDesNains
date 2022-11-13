#include "Framework.h"

Player::Player()
{
	m_speed = 0.0f;
	m_row = 0;
	m_scaleWidth = 0.0f;
	m_scaleHeight = 0.0f;

	m_hp = 0;
	m_keys = 0;

	// Variables pour le saut
	m_timeNow = 0.0f;
	m_timeStartJump = 0.0f;
	m_canJump = false;
	m_isJump = false;
	m_timeAddDisplay = 0.0f;
}

Player::~Player()
{
}

void Player::initialisation(float x, float y) {
	m_originalPos.x = x;
	m_originalPos.y = y;
	m_speed = 200.0f;
	m_row = 0;
	m_scaleWidth = 2.5f;
	m_scaleHeight = 2.5f;

	m_hp = 3;
	m_keys = 0;

	// Variables pour le saut
	m_timeNow = 0.0f;
	m_timeStartJump = 0.0f;
	m_canJump = true;
	m_isJump = false;

	PlayerTexture.loadFromFile("../Images/testSpriteSheet.png");
	PlayerTexture.setSmooth(FALSE);
	PlayerSprite.setTexture(PlayerTexture);
	PlayerSprite.setScale(m_scaleWidth, m_scaleHeight);
	PlayerSprite.setPosition(m_originalPos.x, m_originalPos.y);
	m_view.setSize(900.0f, 506.25f);

	PlayerSprite.setOrigin(11, 20);

	m_anim.initiaisation(&PlayerTexture, sf::Vector2u(5, 2), 0.3f);
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

bool Player::OnUpdate(vector<Entity>& listEntities, int row, float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	// Aller à droite
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		PlayerSprite.setScale(m_scaleWidth, m_scaleHeight);
		movement.x += m_speed * deltaTime;
	}
	// Aller à gauche
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		PlayerSprite.setScale(-m_scaleWidth, m_scaleHeight);
		movement.x -= m_speed * deltaTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
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
	else
	{
		m_isJump = false;
	}

	// Ligne pour l'animation
	if (movement.x == 0.0f)
	{
		m_row = 0;
	}
	else
	{
		m_row = 1;

	}

	bool collideFloor = false;
	bool collideCeil = false;
	bool collideLeft = false;
	bool collideRight = false;

	for (int i = 0; i < listEntities.size(); i++)
	{
		if (Collision(listEntities[i]) && listEntities[i].GetType() == Entity::KEY)
		{
			m_keys = 1;
			m_listDisplay.push_back("You took the key !");
		}

		if (Collision(listEntities[i]) && listEntities[i].GetType() == Entity::DOOR)
		{
			if (m_keys > 0 && m_timeAddDisplay + 2000.0f <= timeGetTime())
			{
				m_timeAddDisplay = timeGetTime();
				m_listDisplay.push_back("You opened the door !");
				return true;
			}
			else if (m_timeAddDisplay + 2000.0f <= timeGetTime())
			{
				m_timeAddDisplay = timeGetTime();
				m_listDisplay.push_back("The door is locked... find the key !");
			}
		}
		if (Collision(listEntities[i]) && listEntities[i].GetType() == Entity::FLOOR)
		{
			collideFloor = true;
		}
		else if (Collision(listEntities[i]) && listEntities[i].GetType() == Entity::CEILING)
		{
			movement.y = 0.0f;
			m_isJump = false;
		}
		else if (Collision(listEntities[i]) && listEntities[i].GetType() == Entity::WALL_LEFT)
		{
			if (movement.x < 0.0f)
			{
				movement.x = 0.0f;
			}
		}
		else if (Collision(listEntities[i]) && listEntities[i].GetType() == Entity::WALL_RIGHT)
		{
			if (movement.x > 0.0f)
			{
				movement.x = 0.0f;
			}
		}
		else if (Collision(listEntities[i]) && listEntities[i].GetType() == Entity::PIC)
		{
			PlayerSprite.setPosition(m_originalPos.x, m_originalPos.y);
			m_hp -= 1;
			m_keys -= 1;
		}
	}

	if (collideFloor)
	{
		m_canJump = true;
	}
	else
	{
		movement.y += m_speed * deltaTime;
		m_canJump = false;
	}

	m_view.setCenter(PlayerSprite.getPosition().x, PlayerSprite.getPosition().y);
	m_anim.Update(m_row, deltaTime);
	PlayerSprite.setTextureRect(m_anim.getUvRect());

	PlayerSprite.move(movement);

	return false;
}

bool Player::Collision(Entity& entity)
{
	return getSprite().getGlobalBounds().intersects(entity.GetRect().getGlobalBounds());
}

void Player::refreshListDisplay() {
	vector<string> temporaryListDisplay;
	for (int i = 0; i < m_listDisplay.size(); i++)
	{
		temporaryListDisplay.push_back(m_listDisplay[i]);
	}
	m_listDisplay.clear();

	for (int i = 0; i < m_listDisplay.size(); i++)
	{
		if (i != 0)
			m_listDisplay.push_back(temporaryListDisplay[i]);
	}
}
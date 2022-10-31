#include "Framework.h"

Controls::Controls()
{
	Reset();
}

Controls::~Controls()
{

}

void Controls::Reset()
{
	m_back = NONE;
	m_start = NONE;
	m_invincible = NONE;

	m_fire = false;
	m_up = false;
	m_down = false;
	m_left = false;
	m_right = false;
}

int Controls::GetKey(int key, bool press)
{
	if (press)
	{
		if (key == NONE || key == UP)
			key = DOWN;
		else if (key == DOWN)
			key = PUSH;
	}
	else
	{
		if (key == PUSH || key == DOWN)
			key = UP;
		else if (key == UP)
			key = NONE;
	}
	return key;
}

void Controls::OnUpdate()
{
	m_up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
	m_down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	m_right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	m_left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
	m_fire = sf::Keyboard::isKeyPressed(sf::Keyboard::RControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::LControl);
	m_start = GetKey(m_start, sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
	m_back = GetKey(m_back, sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
	m_invincible = GetKey(m_invincible, sf::Keyboard::isKeyPressed(sf::Keyboard::I));

}
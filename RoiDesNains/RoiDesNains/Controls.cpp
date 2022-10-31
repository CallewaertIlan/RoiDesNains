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

	m_jump = false;
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
	m_jump = sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
	m_down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	m_right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	m_left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
	m_start = GetKey(m_start, sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
	m_back = GetKey(m_back, sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
	m_menu_up = GetKey(m_menu_up, sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
	m_menu_down = GetKey(m_menu_down, sf::Keyboard::isKeyPressed(sf::Keyboard::Down));

}
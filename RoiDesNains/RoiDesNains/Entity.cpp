#include "Framework.h"

Entity::Entity() {

}

Entity::~Entity() {

}

void Entity::initialisation(float width, float height, int type) {
	sf::Vector2f size(width, height);
	m_width = width;
	m_height = height;
	// Taille du recftangle pour l'entity
	m_rect.setSize(size);

	// Texture du rectangle pour l'entity
	setTexture();

}

void Entity::OnUpdate() {

}

void Entity::setTexture() {

	sf::Texture rock;
	rock.loadFromFile("../Images/rock.png");
	sf::Texture pic;
	pic.loadFromFile("../Images/pic.png");
	sf::Texture door;
	door.loadFromFile("../Images/door.png");

	switch (m_type)
	{
	case Entity::ROCK:
		m_texture = rock;
		m_rect.setTexture(&rock);
		break;
	case Entity::PIC:
		break;
	case Entity::PLATFORM:
		break;
	case Entity::DOOR:
		break;
	}

}
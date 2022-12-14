#include "Framework.h"

Entity::Entity() {
	m_type = 0;
}

Entity::~Entity() {

}

void Entity::initialisation(float width, float height, float x, float y, int type, sf::Texture* texture) {
	m_type = type;
	sf::Vector2f size(width, height);
	sf::Vector2f pos(x, y);

	// Taille du rectangle pour l'entity
	m_rect.setSize(size);

	// Positions du rectangle
	m_rect.setPosition(pos);

	// Texture du rectangle pour l'entity
	m_rect.setTexture(texture);

}

void Entity::OnUpdate(float deltaTime) {
	if (m_type == Entity::PIC) {
		//double test = cos(deltaTime);
		m_rect.move(cos(timeGetTime()/500.0f), 0);
	}

	if (m_type == Entity::KEY) {
		// Ajouter la couleur foncer ou supprimer la clef lors d'une collision
	}

}

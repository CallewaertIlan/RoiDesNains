#pragma once
class Entity
{
public:
	enum type
	{
		ROCK = 0,
		PIC,
		PLATFORM,
		DOOR,

	};
	Entity();
	~Entity();

	void initialisation(float width, float height, float x, float y, int type, sf::Texture* texture);
	void OnUpdate(float deltaTime);
	sf::RectangleShape GetRect() { return m_rect; };

private:
	sf::RectangleShape m_rect;
	int m_type;
};



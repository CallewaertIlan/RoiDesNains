#pragma once
class Entity
{
public:
	enum type
	{
		FLOOR = 0,
		PIC,
		WALL_LEFT,
		WALL_RIGHT,
		CEILING,
		DOOR,
		KEY,

	};
	Entity();
	~Entity();

	int GetType() { return m_type; };

	void initialisation(float width, float height, float x, float y, int type, sf::Texture* texture);
	void OnUpdate(float deltaTime);
	sf::RectangleShape GetRect() { return m_rect; };

private:
	sf::RectangleShape m_rect;
	sf::Color m_color;
	int m_type;
};



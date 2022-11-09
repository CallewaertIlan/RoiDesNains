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

	void initialisation(float width, float height, int type);
	void OnUpdate();
	void setTexture();
	sf::RectangleShape GetRect() { return m_rect };

private:
	sf::RectangleShape m_rect;
	int m_type;
	int m_width;
	int m_height;
	sf::Texture m_texture;
};



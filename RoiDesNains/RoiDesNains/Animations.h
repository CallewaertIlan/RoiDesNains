#pragma once
class Animations
{
public:
	Animations();
	~Animations();
	void initiaisation(sf::Texture* texture, sf::Vector2u ImageCount, float SwitchTime);

	void Update(int row, float DeltaTime);

	sf::IntRect getUvRect() { return uvRect; };


private:
	sf::IntRect uvRect;	
	sf::Vector2u ImageCount;
	sf::Vector2u CurrentImage;

	float TotalTime;
	float SwitchTime;

};


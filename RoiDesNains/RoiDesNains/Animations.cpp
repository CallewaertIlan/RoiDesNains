#include "Framework.h"

Animations::Animations()
{
}

void Animations::initiaisation(sf::Texture* texture, sf::Vector2u ImageSetCount, float SwitchSetTime)
{
	ImageCount = ImageSetCount;
	SwitchTime = SwitchSetTime;
	TotalTime = 0.0f;
	CurrentImage.x = 0;
	CurrentImage.y = 0;

	uvRect.width = texture->getSize().x / float(ImageCount.x);
	uvRect.height = texture->getSize().y / float(ImageCount.y);
}

Animations::~Animations()
{
}

void Animations::Update(int row, float DeltaTime)
{
	CurrentImage.y = row;
	TotalTime += DeltaTime;

	if (TotalTime >= SwitchTime)
	{
		TotalTime -= SwitchTime;
		CurrentImage.x++;
		if (CurrentImage.x >= ImageCount.x)
		{
			CurrentImage.x = 0;
		}
	}
	uvRect.left = CurrentImage.x * uvRect.width;
	uvRect.top = CurrentImage.y * uvRect.height;
}
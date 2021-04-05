#include "Food.h"
namespace snake {
	snake::Food::Food()
	{
	}

	snake::Food::~Food()
	{
	}
	sf::CircleShape Food::CreateFood()
	{
		sf::CircleShape food;
		food.setRadius(FOOD_SIZE);

		food.setPosition(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT);
		food.setOrigin(FOOD_SIZE / 2, FOOD_SIZE / 2);
		return food;
	}
}


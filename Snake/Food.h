#pragma once


#ifndef FOOD_H_
#define FOOD_H_
#include <SFML\Graphics.hpp>
#define FOOD_SIZE 3
#define SCREEN_WIDTH 600  
#define SCREEN_HEIGHT  600
namespace snake
{
	class Food
	{
	public:
		Food();
		~Food();
		sf::CircleShape CreateFood();

	private:
	};
}

#endif /* FOOD_H_ */


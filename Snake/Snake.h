#pragma once

#include <SFML\Graphics.hpp>

#ifndef SNAKE_H_
#define SNAKE_H_


#define SNAKE_SPEED 5
#define SNAKE_SQUARE_SIZE 10

struct SnakeNode {
	sf::RectangleShape rect;
	struct SnakeNode *next;
	float x, y;
};
namespace snake
{
	class Snake
	{
	public:
		Snake();
		~Snake();
		
		void MoveUp();
		void MoveDown();
		void MoveLeft();
		void MoveRight();
		void CreateSnake(sf::Texture snakeTexture);
		void CreateSnakeBody();
		SnakeNode * _snakeHead, *_snakeTail, *_tempPtr;
		SnakeNode* GetSnakeHead();
	private:
		sf::Texture _tex;
		struct SnakeNode * tempDataHolder;

	};
}


#endif /* SNAKE_H_ */


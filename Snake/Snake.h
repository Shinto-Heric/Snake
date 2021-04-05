#pragma once

#include <SFML\Graphics.hpp>

#ifndef SNAKE_H_
#define SNAKE_H_


#define SNAKE_SPEED 5
#define SNAKE_SQUARE_SIZE 10
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT  600
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
		SnakeNode * _snakeHead, *_snakeTail, *_prevPtr;
		SnakeNode* GetSnakeHead();
		void CheckBoundary();

	private:
		sf::Texture _tex;
		SnakeNode * tempDataHolder;

	};
}


#endif /* SNAKE_H_ */


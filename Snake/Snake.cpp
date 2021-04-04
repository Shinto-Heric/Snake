

#include "Snake.h"
#include <stdlib.h>
using namespace sf;

namespace snake
{
	Snake::Snake()
	{
		
	}
	Snake::~Snake()
	{

	}
	void Snake::MoveUp()
	{

	}
	void Snake::MoveDown()
	{

	}
	void Snake::MoveLeft()
	{

	}
	void Snake::MoveRight()
	{

	}
	void Snake::CreateSnake(sf::Texture snakeTexture)
	{
		sf::RectangleShape head;
		head.setSize(sf::Vector2f(SNAKE_SQUARE_SIZE, SNAKE_SQUARE_SIZE));
		head.setPosition(300, 300);
		//head.setOrigin(SNAKE_SQUARE_SIZE / 2,SNAKE_SQUARE_SIZE / 2);
		head.setTexture(&snakeTexture);
		SnakeNode* new_node = new SnakeNode;
		new_node->rect = head;
		new_node->next = NULL;
		new_node->x = head.getPosition().x;
		new_node->y = head.getPosition().y;

		if (_snakeHead == NULL)
		{
			_snakeHead = new_node;
			_snakeTail = _snakeHead;
		}
		else
		{
			_snakeTail->next = new_node;
			_snakeTail = _snakeTail->next;
		}

	}
	void Snake::CreateSnakeBody()
	{

	}
	SnakeNode * Snake::GetSnakeHead()
	{
		return _snakeHead;
	}
}
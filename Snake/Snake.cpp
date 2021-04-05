

#include "Snake.h"
#include <stdlib.h>
#include <iostream>
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
		tempDataHolder = _snakeHead;

		while (tempDataHolder->next != NULL)
		{
			_prevPtr = tempDataHolder;
			tempDataHolder = tempDataHolder->next;
			tempDataHolder->x = _prevPtr->rect.getPosition().x;
			tempDataHolder->y = _prevPtr->rect.getPosition().y;
		}
		tempDataHolder->x = _prevPtr->rect.getPosition().x;
		tempDataHolder->y = _prevPtr->rect.getPosition().y;
		_snakeHead->x = _snakeHead->rect.getPosition().x;
		_snakeHead->y = _snakeHead->rect.getPosition().y - SNAKE_SQUARE_SIZE;

		tempDataHolder = _snakeHead;

		while (tempDataHolder->next != NULL)
		{
			tempDataHolder->rect.setPosition(tempDataHolder->x, tempDataHolder->y);
			tempDataHolder = tempDataHolder->next;
		}
		tempDataHolder->rect.setPosition(tempDataHolder->x, tempDataHolder->y);
	}
	void Snake::MoveDown()
	{
		tempDataHolder = _snakeHead;

		while (tempDataHolder->next != NULL)
		{
			_prevPtr = tempDataHolder;
			tempDataHolder = tempDataHolder->next;
			tempDataHolder->x = _prevPtr->rect.getPosition().x;
			tempDataHolder->y = _prevPtr->rect.getPosition().y;
		}
		tempDataHolder->x = _prevPtr->rect.getPosition().x;
		tempDataHolder->y = _prevPtr->rect.getPosition().y;
		_snakeHead->x = _snakeHead->rect.getPosition().x;
		_snakeHead->y = _snakeHead->rect.getPosition().y + SNAKE_SQUARE_SIZE;

		tempDataHolder = _snakeHead;

		while (tempDataHolder->next != NULL)
		{
			tempDataHolder->rect.setPosition(tempDataHolder->x, tempDataHolder->y);
			tempDataHolder = tempDataHolder->next;
		}
		tempDataHolder->rect.setPosition(tempDataHolder->x, tempDataHolder->y);
	}
	void Snake::MoveLeft()
	{
		tempDataHolder = _snakeHead;

		while (tempDataHolder->next != NULL)
		{
			_prevPtr = tempDataHolder;
			tempDataHolder = tempDataHolder->next;
			tempDataHolder->x = _prevPtr->rect.getPosition().x;
			tempDataHolder->y = _prevPtr->rect.getPosition().y;
		}
		tempDataHolder->x = _prevPtr->rect.getPosition().x;
		tempDataHolder->y = _prevPtr->rect.getPosition().y;
		_snakeHead->x = _snakeHead->rect.getPosition().x - SNAKE_SQUARE_SIZE;
		_snakeHead->y = _snakeHead->rect.getPosition().y;

		tempDataHolder = _snakeHead;

		while (tempDataHolder->next != NULL)
		{
			tempDataHolder->rect.setPosition(tempDataHolder->x, tempDataHolder->y);
			tempDataHolder = tempDataHolder->next;
		}
		tempDataHolder->rect.setPosition(tempDataHolder->x, tempDataHolder->y);
	}
	void Snake::MoveRight()
	{
		tempDataHolder = _snakeHead;

		while (tempDataHolder->next != NULL)
		{
			_prevPtr = tempDataHolder;
			tempDataHolder = tempDataHolder->next;
			tempDataHolder->x = _prevPtr->rect.getPosition().x;
			tempDataHolder->y = _prevPtr->rect.getPosition().y;
		}
		tempDataHolder->x = _prevPtr->rect.getPosition().x;
		tempDataHolder->y = _prevPtr->rect.getPosition().y;
		_snakeHead->x = _snakeHead->rect.getPosition().x + SNAKE_SQUARE_SIZE;
		_snakeHead->y = _snakeHead->rect.getPosition().y;

		tempDataHolder = _snakeHead;

		while (tempDataHolder->next != NULL)
		{
			tempDataHolder->rect.setPosition(tempDataHolder->x, tempDataHolder->y);
			tempDataHolder = tempDataHolder->next;
		}
		tempDataHolder->rect.setPosition(tempDataHolder->x, tempDataHolder->y);
	}
	void Snake::CreateSnake(sf::Texture snakeTexture)
	{
		sf::RectangleShape head;
		head.setSize(sf::Vector2f(SNAKE_SQUARE_SIZE, SNAKE_SQUARE_SIZE));
		head.setPosition(300, 300);
		head.setOrigin(SNAKE_SQUARE_SIZE / 2,SNAKE_SQUARE_SIZE / 2);
		head.setTexture(&snakeTexture);
		SnakeNode* new_node = new SnakeNode;
		new_node->rect = head;
		new_node->next = NULL;
		

		if (_snakeHead == NULL)
		{
			_snakeHead = new_node;
			_snakeTail = _snakeHead;
			_prevPtr = _snakeHead;
			new_node->x = head.getPosition().x;
			new_node->y = head.getPosition().y;
		}
		else
		{
			new_node->x = _snakeTail->x;
			new_node->y = _snakeTail->y + SNAKE_SQUARE_SIZE;
			new_node->rect.setPosition(new_node->x,new_node->y);
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
	void Snake::CheckBoundary()
	{
		if (_snakeHead != NULL)
		{
			if (_snakeHead->rect.getPosition().x  <= 0)
			{
				_snakeHead->rect.setPosition(SCREEN_WIDTH ,_snakeHead->rect.getPosition().y);
			}
			else if (_snakeHead->rect.getPosition().x >= SCREEN_WIDTH)
			{
				_snakeHead->rect.setPosition(0, _snakeHead->rect.getPosition().y);
			}
			if (_snakeHead->rect.getPosition().y <= 0)
			{
				_snakeHead->rect.setPosition(_snakeHead->rect.getPosition().x, SCREEN_HEIGHT);
			}
			else if (_snakeHead->rect.getPosition().y >= SCREEN_HEIGHT)
			{
				_snakeHead->rect.setPosition(_snakeHead->rect.getPosition().x ,0);
			}
		}
	}
}
#include "Gameplay.h"
using namespace sf;
namespace snake
{
	Gameplay::Gameplay()
	{
		_firstScreenLoaded = false;
		_isGameActive = true;
		up = down = left = right = false;
		_snake = new Snake();
		_food = new Food();
		_gameOver = false;
		triggerOneTime = false;
		totalScore = 0;
	}
	Gameplay::~Gameplay()
	{
		;

	}
	sf::Text Gameplay::LoadMenuScreen(Font &f)
	{
		_firstScreenLoaded = true;
		score.setFont(f);
		score.setCharacterSize(30);
		score.setPosition(150,250);
		score.setOrigin(score.getLocalBounds().left / 2.0f, score.getLocalBounds().top / 2.0f);
		score.setString("Press SPACE to START\nPress Q to QUIT");
		return score;
	}
	void Gameplay::SetScreenStatus(bool status)
	{
		_firstScreenLoaded = status;
	}
	void Gameplay::SetRenderWindow(sf::RenderWindow& window)
	{
		renderWindow = &window;
	}
	sf::Text Gameplay::GetTextObject()
	{
		return score;
	}
	void Gameplay::HandleGameplayEvents(Event event)
	{

		if (_firstScreenLoaded)
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				_firstScreenLoaded = false;
				_gameOver = false;
				triggerOneTime = true;
				totalScore = 0;
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q)
			{
				_isGameActive = false;
			}
		}
		else
		{
			if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up))
			{
				if (down == false)
				{
					up = true; right = left = false;
				}				
			}
			if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left))
			{
				if (right == false)
				{
					left = true; up = down = false;
				}	
			}
			if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down))
			{
				if (up == false)
				{
					down = true; right = left = false;
				}
			}
			if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right))
			{
				if (left == false)
				{
					right = true; up = down = false;
				}
				
				
			}
		}
		
	}
	bool Gameplay::CheckGameStatus()
	{
		return _isGameActive;
	}
	bool Gameplay::FirstScreenStatus()
	{
		return _firstScreenLoaded;
	}
	bool Gameplay::GetGameOverStatus()
	{
		return _gameOver;
	}
	void Gameplay::SetMovement()
	{
		if (_firstScreenLoaded == false)
		{
			if (up)
			{
				_snake->MoveUp();
			}
			if (down)
			{
				_snake->MoveDown();
			}
			if (left)
			{
				_snake->MoveLeft();
			}
			if (right)
			{
				_snake->MoveRight();
			}
			_snake->CheckBoundary();
			CheckCollison();
		}
	}
	void Gameplay::CreateGameObjects()
	{

	}
	void Gameplay::CreateSnake(long long length)
	{
		while (length)
		{
			_snake->CreateSnake();
			length--;
		}

	}
	std::map<Snake *, sf::RectangleShape> Gameplay::GetSnakeMap()
	{
		return _snakeTextures;
	}

	SnakeNode * Gameplay::GetSnakeHead()
	{
		SnakeNode * temp = _snake->GetSnakeHead();
		return temp;
	}

	void Gameplay::CreateFood()
	{
		snakeFood = _food->CreateFood();
	}

	sf::CircleShape Gameplay::GetFood()
	{
		return snakeFood;
	}

	void Gameplay::CheckCollison()
	{
		headPtr = _snake->GetSnakeHead();
		if (headPtr->rect.getGlobalBounds().intersects(snakeFood.getGlobalBounds()) == true)
		{
			snakeFood.setPosition(rand() % 600, rand() % 600);
			CreateSnake(1);
			totalScore++;
		}
		while (headPtr->next != NULL)
		{
			headPtr = headPtr->next;
			if (headPtr->rect.getGlobalBounds().intersects((_snake->GetSnakeHead())->rect.getGlobalBounds()) == true)
			{
				_gameOver = true;
				_firstScreenLoaded = true; 
				_snake->KillSnake();
				up = down = left = right = false;
				break;
			}
		}
	}
}

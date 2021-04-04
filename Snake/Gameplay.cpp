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
	void Gameplay::SetMovement()
	{
		if (up)
		{
			//_snake->MoveUp();
		}
		else if (down)
		{
			//_snake->MoveDown();
		}
		else if (left)
		{
			//_snake->MoveLeft();
		}
		else if (right)
		{
			//_snake->MoveRight();
		}
	}
	void Gameplay::CreateGameObjects()
	{

	}
	void Gameplay::CreateSnake(long long length)
	{
		while (length)
		{
			_snake->CreateSnake(head);
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

	void Gameplay::SetHeadTex(sf::Texture tex) { head = tex; }
	void Gameplay::SetBodyTex(sf::Texture tex) { body = tex; }
	void Gameplay::SetFoodTex(sf::Texture tex) { food = tex; }
}

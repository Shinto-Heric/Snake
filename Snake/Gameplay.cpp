#include "Gameplay.h"
using namespace sf;
namespace snake
{
	Gameplay::Gameplay()
	{
		_firstScreenLoaded = false;
		_isGameActive = true;
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
}

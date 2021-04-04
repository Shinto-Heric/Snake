
#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_
#include <SFML\Graphics.hpp>
#include <iostream>
#include <sstream>

//Constant variables
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT  600


namespace snake
{
	class Gameplay
	{
	public:
		Gameplay();
		~Gameplay();
		sf::Text LoadMenuScreen(sf::Font &f);
		void SetRenderWindow(sf::RenderWindow& window);
		sf::Text GetTextObject();
		bool FirstScreenStatus();
		bool CheckGameStatus();
		void SetScreenStatus(bool);
		void HandleGameplayEvents(sf::Event);
	private:
		sf::Text score;
		bool _firstScreenLoaded;
		bool _isGameActive;
		sf::RenderWindow *renderWindow;

	};
}

#endif /* GAMEPLAY_H_ */


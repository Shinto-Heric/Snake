//Libraries
#include <iostream>
#include <sstream>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include "Snake.h"
#include "Food.h"
#include "Gameplay.h"
//Glboal variables, functions, classes
using namespace snake;


int main()
{
	//Creating the window
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Snake", sf::Style::Titlebar | sf::Style::Close);

	//Settign the framerate limit to 60 FPS
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
	Gameplay *gameplay = new Gameplay();
	sf::Font font;
	if (font.loadFromFile("Data/font.otf") == 0) //Safe way to load font
	{
		std::cout << "FONT FILE NOT FOUND\n";
		return -1;
	}
	sf::Text WelcomeText =  gameplay->LoadMenuScreen(font);

	sf::Event event;

	//Game loop
	while (gameplay->CheckGameStatus())
	{
		//EVENTS
		while (window.pollEvent(event))
		{
			//Event type is window closed
			if (event.type == sf::Event::Closed)
			{
				//Set play to false in order to stop the game loop
				window.close();
			}
			
			gameplay->HandleGameplayEvents(event);
			
		}

		

		//RENDERING
		window.clear();
		
		//Drawing the shapes

		if (gameplay->FirstScreenStatus())
		{
			window.draw(WelcomeText);
		}
		else
		{

		}
		

		window.display();
	}
	///////////

	//Clean up and close the window
	window.close();

	//Close the program
	return 0;
}
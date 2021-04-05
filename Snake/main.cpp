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

#define DEFAULT_SNAKE_LENGTH 50


int main()
{
	//Creating the window
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Snake", sf::Style::Titlebar | sf::Style::Close);
	//Settign the framerate limit to 60 FPS
	//Snake *snakePtr = new Snake();
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
	//snake texture
	
	gameplay->CreateSnake(DEFAULT_SNAKE_LENGTH);
	gameplay->CreateFood();

	//Game loop

	SnakeNode* drawPtr = gameplay->GetSnakeHead();

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

		gameplay->SetMovement();


		//RENDERING
		window.clear();
		
		//Drawing the shapes

		if (gameplay->GetGameOverStatus() && gameplay->triggerOneTime)
		{
			gameplay->CreateSnake(DEFAULT_SNAKE_LENGTH);
			gameplay->CreateFood();
			gameplay->triggerOneTime = false;
			
					std::stringstream text;
					text << "Your Score \n"<< gameplay->totalScore <<"\n"; //Create the text
					WelcomeText.setString(text.str() + "Press SPACE to START\nPress Q to QUIT"); //Set the score text
		}
		if (gameplay->FirstScreenStatus())
		{
			window.draw(WelcomeText);
		}
		else
		{
			drawPtr = NULL;
			drawPtr = gameplay->GetSnakeHead();
			while (drawPtr->next != NULL)
			{
				window.draw(drawPtr->rect);
				drawPtr = drawPtr->next;
			}
			window.draw(drawPtr->rect);
			window.draw(gameplay->GetFood());
		}
		window.display();
	}
	///////////

	//Clean up and close the window
	window.close();

	//Close the program
	return 0;
}
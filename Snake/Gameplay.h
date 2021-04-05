
#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_
#include <SFML\Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Snake.h"
#include <map>
//Constant variables



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
		void SetMovement();
		void CreateGameObjects();
		void CreateSnake(long long length);
		void SetHeadTex(sf::Texture);
		void SetBodyTex(sf::Texture);
		void SetFoodTex(sf::Texture);
		std::map<Snake *, sf::RectangleShape> GetSnakeMap();
		SnakeNode* GetSnakeHead();
	private:
		sf::Text score;
		bool _firstScreenLoaded;
		bool _isGameActive;
		sf::RenderWindow *renderWindow;
		//Key Status
		bool up, down, left, right;
		std::map<Snake *,sf::RectangleShape> _snakeTextures;
		Snake *_snake;
		sf::Texture head,body,food;
		SnakeNode * headPtr;
	};
}
#endif /* GAMEPLAY_H_ */



#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_
#include <SFML\Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Snake.h"
#include "Food.h"
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
		bool GetGameOverStatus();
		bool CheckGameStatus();
		void SetScreenStatus(bool);
		void HandleGameplayEvents(sf::Event);
		void SetMovement();
		void CreateGameObjects();
		void CreateSnake(long long length);

		std::map<Snake *, sf::RectangleShape> GetSnakeMap();
		SnakeNode* GetSnakeHead();
		void CreateFood();
		sf::CircleShape GetFood();
		void CheckCollison();


	private:
		sf::Text score;
		bool _firstScreenLoaded;
		bool _gameOver;
		bool _isGameActive;
		sf::RenderWindow *renderWindow;
		//Key Status
		bool up, down, left, right;
		std::map<Snake *,sf::RectangleShape> _snakeTextures;
		Snake *_snake;
		Food *_food;
		sf::CircleShape snakeFood;
		SnakeNode * headPtr;
	public:
		bool triggerOneTime;
		long long totalScore;

	};
}
#endif /* GAMEPLAY_H_ */


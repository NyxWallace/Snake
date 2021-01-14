#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <utility>

#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "Snake.h"

class Game
{
public:
	int StartGame();

private:
	int menuOption = 1;
	int direction = 77;
	bool gameOver = false;

	void startMainLoop();
	void clearScreen(char);
	int drawMenu(int);
	int drawEnd();
	int drawBoard(std::vector<std::vector<int>>, std::pair<int, int>);
	std::pair<int, int> getFoodPosition(std::vector<std::vector<int>>);
};


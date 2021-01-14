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
	int Start_game();

private:
	void start_main_loop();
	void clear_screen(char);
	std::pair<int, int> get_food_position(std::vector<std::vector<int>> matrix);
	int Draw_menu(int);
	int Draw_end();
	int Draw_board(std::vector<std::vector<int>> matrix, std::pair<int, int> food);
	int menu_option = 1;
	bool game_over = false;
	int direction = 77;
};


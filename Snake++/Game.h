#pragma once
class Game
{
public:
	int Start_game();

private:
	void start_main_loop();
	void clear_screen(char fill);
	int Draw_menu(int option);
	int menu_option = 1;
};


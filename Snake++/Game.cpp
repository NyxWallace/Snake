#include "Game.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13

int Game::Start_game() 
{
    int key = 0;

    while (true) 
    {
        Draw_menu(menu_option);

        key = _getch();
        // Catch scan code. Ref. to https://stackoverflow.com/a/54581468
        if (key == 224)
        {
            key = _getch();
        }

        switch (key)
        {
        case KEY_UP:
            menu_option = 1;
            break;
        case KEY_DOWN:
            menu_option = 2;
            break;
        case KEY_ENTER:
            if (menu_option == 1)
                // Start game
                start_main_loop();
            else
                // Close game
                exit(0);
        default:
            break;
        }

        clear_screen(' ');
    }
    
    return 0;
}

void Game::start_main_loop() 
{

}

void Game::clear_screen(char fill = ' ') 
{
    COORD tl = { 0,0 };
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, fill, cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}

int Game::Draw_menu(int option)
{
    if (option == 1) 
    {
        std::cout << "___________________________________________________\n";
        std::cout << "|                                                  |\n";
        std::cout << "|       _____               __                     |\n";
        std::cout << "|      / ___/  ____  ____ _/ /_____    __    __    |\n";
        std::cout << "|      \__ \  / __ \/ __ `/ //_/ _ \__/ /___/ /_   |\n";
        std::cout << "|     ___/ / / / / / /_/ /,<  /  __/_  __/_  __/   |\n";
        std::cout << "|    /____/ /_/ /_/\__,_/_/|_|\___/ /_/   /_/      |\n";
        std::cout << "|                                                  |\n";
        std::cout << "|                   -> Start                       |\n";
        std::cout << "|                      Close                       |\n";
        std::cout << "|                                                  |\n";
        std::cout << "|                                                  |\n";
        std::cout << "|             Antoine Farine @ 2021                |\n";
        std::cout << "|__________________________________________________|\n";
    }
    else
    {
        std::cout << "___________________________________________________\n";
        std::cout << "|                                                  |\n";
        std::cout << "|       _____               __                     |\n";
        std::cout << "|      / ___/  ____  ____ _/ /_____    __    __    |\n";
        std::cout << "|      \__ \  / __ \/ __ `/ //_/ _ \__/ /___/ /_   |\n";
        std::cout << "|     ___/ / / / / / /_/ /,<  /  __/_  __/_  __/   |\n";
        std::cout << "|    /____/ /_/ /_/\__,_/_/|_|\___/ /_/   /_/      |\n";
        std::cout << "|                                                  |\n";
        std::cout << "|                      Start                       |\n";
        std::cout << "|                   -> Close                       |\n";
        std::cout << "|                                                  |\n";
        std::cout << "|                                                  |\n";
        std::cout << "|             Antoine Farine @ 2021                |\n";
        std::cout << "|__________________________________________________|\n";
    }

    return 0;
}
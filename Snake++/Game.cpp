#include "Game.h"

// Constant value
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

// Game settings
#define SPEED 2 // High number = Slower speed
#define WIDTH 16
#define HEIGHT 8

int Game::StartGame() 
{
    int key = 0;

    while (true) 
    {
        drawMenu(menuOption);

        key = _getch();
        // Catch scan code. Ref. to https://stackoverflow.com/a/54581468
        if (key == 224)
        {
            key = _getch();
        }

        switch (key)
        {
        case UP:
            menuOption = 1;
            break;
        case DOWN:
            menuOption = 2;
            break;
        case ENTER:
            if (menuOption == 1)
                // Start game
                startMainLoop();
            else
                // Close game
                exit(0);
        default:
            break;
        }

        clearScreen(' ');
    }
    
    return 0;
}

void Game::startMainLoop() 
{
    Snake* snake = new Snake();
    gameOver = false;
    bool food_eaten = true;
    std::pair <int, int> food;

    while (!gameOver) 
    {
        clearScreen(' ');

        std::vector<std::vector<int>> matrix = snake->GetMatrix(WIDTH, HEIGHT);

        if (food_eaten) 
        {
            food = getFoodPosition(matrix);
            food_eaten = false;
        }

        drawBoard(matrix, food);

        for (int i = 0; i < SPEED; ++i) 
        {
            for (int j = 0; j < 10000; ++j)
            {
                if (GetKeyState(VK_UP) & 0x8000)
                {
                    direction = UP;
                }
                if (GetKeyState(VK_DOWN) & 0x8000)
                {
                    direction = DOWN;
                }
                if (GetKeyState(VK_LEFT) & 0x8000)
                {
                    direction = LEFT;
                }
                if (GetKeyState(VK_RIGHT) & 0x8000)
                {
                    direction = RIGHT;
                }
            }
        }

        int snake_x = snake->Head->PosX;
        int snake_y = snake->Head->PosY;

        switch (direction)
        {
        case UP:
            if (snake_x + WIDTH == food.first && snake_y + HEIGHT + 1 == food.second) 
            {
                food_eaten = true;
                snake->EatTo(0, 1);
            }
            else
            {
                snake->MoveTo(0, 1);
            }
            break;
        case DOWN:
            if (snake_x + WIDTH == food.first && snake_y + HEIGHT - 1 == food.second)
            {
                food_eaten = true;
                snake->EatTo(0, -1);
            }
            else
            {
                snake->MoveTo(0, -1);
            }
            break;
        case LEFT:
            if (snake_x + WIDTH - 1 == food.first && snake_y + HEIGHT == food.second)
            {
                food_eaten = true;
                snake->EatTo(-1, 0);
            }
            else
            {
                snake->MoveTo(-1, 0);
            }
            break;
        case RIGHT:
            if (snake_x + WIDTH + 1 == food.first && snake_y + HEIGHT == food.second)
            {
                food_eaten = true;
                snake->EatTo(1, 0);
            }
            else
            {
                snake->MoveTo(1, 0);
            }
            break;
        }

        if (snake->Head->PosX + WIDTH < 0 || snake->Head->PosX + WIDTH >= WIDTH * 2 || snake->Head->PosY + HEIGHT < 0 || snake->Head->PosY + HEIGHT >= HEIGHT * 2)
        {
            gameOver = true;
        }
    }

    delete snake;

    clearScreen(' ');

    drawEnd();

    system("pause");
}

std::pair<int, int> Game::getFoodPosition(std::vector<std::vector<int>> matrix)
{
    std::vector<std::pair<int, int>> candidates;

    int matrix_width = matrix.size();
    int matrix_height = matrix[0].size();
    for (int i = matrix_height - 1; i > 0; i--)
    {
        for (int j = 0; j < matrix_width; ++j)
        {
            if (matrix[j][i] == 0)
            {
                candidates.push_back(std::pair<int, int>(j, i));
            }
        }
    }

    int pos = rand() % candidates.size();

    return candidates[pos];
}

void Game::clearScreen(char fill = ' ') 
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

int Game::drawEnd()
{
    std::cout << "___________________________________________________\n";
    std::cout << "|                                                  |\n";
    std::cout << "|                                                  |\n";
    std::cout << "|                                                  |\n";
    std::cout << "|                                                  |\n";
    std::cout << "|                G A M E   O V E R                 |\n";
    std::cout << "|                                                  |\n";
    std::cout << "|                                                  |\n";
    std::cout << "|                                                  |\n";
    std::cout << "|                                                  |\n";
    std::cout << "|                                                  |\n";
    std::cout << "|                                                  |\n";
    std::cout << "|                                                  |\n";
    std::cout << "|__________________________________________________|\n";

    return 0;
}

int Game::drawMenu(int option)
{
    if (option == 1) 
    {
        std::cout << "___________________________________________________\n";
        std::cout << "|                                                  |\n";
        std::cout << "|       _____               __                     |\n";
        std::cout << "|      / ___/  ____  ____ _/ /_____    __    __    |\n";
        std::cout << "|      \\__ \\  / __ \\/ __ `/ //_/ _ \\__/ /___/ /_   |\n";
        std::cout << "|     ___/ / / / / / /_/ /,<  /  __/_  __/_  __/   |\n";
        std::cout << "|    /____/ /_/ /_/\\__,_/_/|_|\\___/ /_/   /_/      |\n";
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
        std::cout << "|      \\__ \\  / __ \\/ __ `/ //_/ _ \\__/ /___/ /_   |\n";
        std::cout << "|     ___/ / / / / / /_/ /,<  /  __/_  __/_  __/   |\n";
        std::cout << "|    /____/ /_/ /_/\\__,_/_/|_|\\___/ /_/   /_/      |\n";
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

int Game::drawBoard(std::vector<std::vector<int>> matrix, std::pair<int,int> food)
{
    int matrix_width = matrix.size();
    int matrix_height = matrix[0].size();
    for (int i = 0; i < matrix_width + 2; ++i) { std::cout << "_"; }
    std::cout << "\n";
    for (int i = matrix_height-1; i > 0; i--) 
    {
        std::cout << "|";
        for (int j = 0; j < matrix_width; ++j)
        {
            if (matrix[j][i] == 0) 
            {
                if (food.first == j && food.second == i) { std::cout << "+"; }
                else { std::cout << " "; }
            }
            else if (matrix[j][i] == 1) 
            {
                std::cout << "X"; 
            }
            else
            {
                std::cout << "O";
                gameOver = true;
            }
        }
        std::cout << "|\n";
    }

    std::cout << "|";
    for (int j = 0; j < matrix_width; ++j)
    {
        if (matrix[j][0] == 0)
        {
            std::cout << "_";
        }
        else if (matrix[j][0] == 1)
        {
            std::cout << "X";
        }
        else
        {
            std::cout << "O";
            gameOver = true;
        }
    }
    std::cout << "|";

    return 0;
}
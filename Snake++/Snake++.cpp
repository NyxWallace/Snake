// Snake++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int drawLine(int size) 
{
    std::cout << std::string(size, '_') << "\n";

    return 0;
}

int drawBord(int size)
{
    std::cout << "|" << std::string(size-2, ' ') << "|\n";

    return 0;
}

int drawBoard(int width, int height)
{
    drawLine(width);

    for (int i = 0; i < height; i++)
    {
        drawBord(width);
    }
    
    std::cout << "|" << std::string(width-2, '_') << "|\n";

    return 0;
}

int main()
{
    drawBoard(20,10);
}
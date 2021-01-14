#pragma once
#include <vector>
#include "Body.h"

class Snake
{
public:
	Body* Head;
	Body* Tail;

	Snake();

	int MoveTo(int, int);
	int EatTo(int, int);
	std::vector<std::vector<int>> GetMatrix(int , int);
};
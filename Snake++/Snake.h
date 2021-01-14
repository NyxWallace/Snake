#pragma once
#include <vector>
#include "Body.h"

class Snake
{
public:
	Snake();
	Body* Head;
	Body* Tail;
	std::vector<std::vector<int>> get_matrix(int , int);
	int move_to(int pos_x, int pos_y);
	int eat_to(int pos_x, int pos_y);
};
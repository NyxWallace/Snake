#pragma once
#include <vector>
#include "Body.h"

class Snake
{
public:
	Body* Head;
	Body* Tail;
	std::vector<std::vector<int>> get_matrix();
	int move_to(int pos_x, int pos_y);
};
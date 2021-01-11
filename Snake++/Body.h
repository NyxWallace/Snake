#pragma once
class Body
{
public:
	int pos_x, pos_y;
	Body* next;
	Body* prev;
	Body(int x, int y);
};


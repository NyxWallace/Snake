#pragma once
class Body
{
public:
	int PosX, PosY;
	Body* Next;
	Body* Prev;

	Body(int x, int y);
};


#include "Snake.h"

Snake::Snake() 
{
	Head = new Body(0, 0);
	Tail = new Body(-1, 0);

	Head->Next = Tail;
	Tail->Prev = Head;
}

/// <summary>
/// Move to the next cell without increasing the size
/// </summary>
/// <param name="pos_x">Number of units moved on the X ax</param>
/// <param name="pos_y">Number of units moved on the Y axe</param>
/// <returns></returns>
int Snake::MoveTo(int pos_x, int pos_y)
{
	int next_x = 0, next_y = 0;
	next_x = Head->PosX + pos_x;
	next_y = Head->PosY + pos_y;

	Body* new_head = new Body(next_x, next_y);
	new_head->Next = Head;
	Head->Prev = new_head;
	Head = new_head;

	new_head = Tail;
	Tail = Tail->Prev;
	Tail->Next = NULL;
	delete new_head;

	return 0;
}

/// <summary>
/// Move to the next cell and increase the size by one
/// </summary>
/// <param name="pos_x">Number of units moved on the X axe</param>
/// <param name="pos_y">Number of units moved on the Y axe</param>
/// <returns></returns>
int Snake::EatTo(int pos_x, int pos_y)
{
	int next_x = 0, next_y = 0;
	next_x = Head->PosX + pos_x;
	next_y = Head->PosY + pos_y;

	Body* new_head = new Body(next_x, next_y);
	new_head->Next = Head;
	Head->Prev = new_head;
	Head = new_head;

	return 0;
}

/// <summary>
/// Return a matrix of the whole board with 0 if the cell is empty, 1 if a snake body is in the cell or more if snake body parts are overlapping
/// </summary>
/// <param name="width">Half of the board width</param>
/// <param name="height">Half of the board height</param>
/// <returns></returns>
std::vector<std::vector<int>> Snake::GetMatrix(int width, int height)
{
	std::vector<std::vector<int>> matrix(width * 2, std::vector<int>(height * 2, 0));

	Body* current = Head;
	matrix[current->PosX + width][current->PosY + height]++;

	while (current->Next != NULL)
	{
		current = current->Next;
		matrix[current->PosX + width][current->PosY + height]++;
	}

	return matrix;
}


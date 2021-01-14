#include "Snake.h"

Snake::Snake() 
{
	Head = new Body(0, 0);
	Tail = new Body(-1, 0);

	Head->next = Tail;
	Tail->prev = Head;
}

std::vector<std::vector<int>> Snake::get_matrix(int width, int height)
{
	std::vector<std::vector<int>> matrix(width * 2, std::vector<int>(height * 2, 0));

	Body* current = Head;
	matrix[current->pos_x + width][current->pos_y + height]++;

	while (current->next != NULL)
	{
		current = current->next;
		matrix[current->pos_x + width][current->pos_y + height]++;
	}

	return matrix;
}

int Snake::move_to(int pos_x, int pos_y)
{
	int next_x = 0, next_y = 0;
	next_x = Head->pos_x + pos_x;
	next_y = Head->pos_y + pos_y;

	Body* new_head = new Body(next_x, next_y);
	new_head->next = Head;
	Head->prev = new_head;
	Head = new_head;

	new_head = Tail;
	Tail = Tail->prev;
	Tail->next = NULL;
	delete new_head;

	return 0;
}

int Snake::eat_to(int pos_x, int pos_y)
{
	int next_x = 0, next_y = 0;
	next_x = Head->pos_x + pos_x;
	next_y = Head->pos_y + pos_y;

	Body* new_head = new Body(next_x, next_y);
	new_head->next = Head;
	Head->prev = new_head;
	Head = new_head;

	return 0;
}

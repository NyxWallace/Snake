#include "Snake.h"

std::vector<std::vector<int>> Snake::get_matrix()
{
	return std::vector<std::vector<int>>();
}

int Snake::move_to(int pos_x, int pos_y)
{
	Body* new_head = new Body(pos_x, pos_y);
	new_head->next = Head;
	Head->prev = new_head;
	Head = new_head;

	new_head = Tail;
	Tail = Tail->prev;
	delete new_head;

	return 0;
}

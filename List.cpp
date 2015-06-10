#include "List.h"


List::List()
{
	top->m_next = top->m_prev = top;
}

void List::push_front(const int value)
{
	Node* front = top -> m_next;
	Node* elem = new Node(value);

	top->m_next = elem;
	front->m_prev = elem;

	elem->m_next = front;
	elem->m_prev = top;
}

void List::pop_front()
{
	Node* front = top->m_next;
	Node* new_front = front->m_next;

	top->m_next = new_front;
	new_front->m_prev = top;

	delete front;
}

void List::push_back(const int value)
{
	Node* back = top->m_prev;
	Node* elem = new Node(value);

	top->m_prev = elem;
	back->m_next = elem;

	elem->m_next = top;
	elem->m_prev = back;

}

void List::pop_back()
{
	Node* back = top->m_prev;
	Node* new_back = back->m_prev;

	top->m_prev = new_back;
	new_back->m_next = top;

	delete back;
}

int List::front()
{
	return top->m_next->m_data;
}

int List::back()
{
	return top->m_prev->m_data;
}





bool List::empty()
{
	return top == top->m_next;
}




int List::size()
{
	List
}

List::~List()
{

}

#include <iostream>
using namespace std;

template <typename T>
class List
{
private:
	struct Node
	{
		T m_data;
		Node* m_next;
		Node* m_prev;

		Node() :
			m_next(0), m_prev(0)
		{};

		Node(const T& value) : 
			m_data(value), m_next(0), m_prev(0)
		{};

	};

public:
	Node* top = new Node(0);

	List();
	void push_front(const T& value);
	void pop_front();
	void push_back(const T& value);
	void pop_back();
	T& front();
	T& back();

	class iterator
	{
	private:
		friend class List;

		Node* currentNode;

	public:
		iterator() : currentNode(){}

		iterator(Node* num)
		{
			currentNode = num;
		}

		T& operator*() 
		{
			return currentNode->m_data;
		}

		iterator operator++()
		{
			currentNode = currentNode->m_next;
			return *this;
		}

		iterator operator++(int num)
		{
			iterator it = *this;
			currentNode = currentNode->m_next;
			return it;
		}

		bool operator!=(iterator it)
		{
			return currentNode != it.currentNode;
		}
	};

	iterator begin()
	{
		return top->m_next;
	}

	iterator end()
	{
		iterator it = top->m_prev;
		it++;
		return it;
	}

	void insert(iterator it, const T& value);
	void erase(iterator it);
	int size();
	void clear();
	bool empty();

	~List();
};

template <typename T>
List<T>::List() : top(new Node)
{
	top->m_next = top->m_prev = top;
}

template <typename T>
void List<T>::push_front(const T& value)
{
	Node* front = top->m_next;
	Node* elem = new Node(value);

	top->m_next = elem;
	front->m_prev = elem;

	elem->m_next = front;
	elem->m_prev = top;
}

template <typename T>
void List<T>::pop_front()
{
	Node* front = top->m_next;
	Node* new_front = front->m_next;

	top->m_next = new_front;
	new_front->m_prev = top;

	delete front;
}

template <typename T>
void List<T>::push_back(const T& value)
{
	Node* back = top->m_prev;
	Node* elem = new Node(value);

	top->m_prev = elem;
	back->m_next = elem;

	elem->m_next = top;
	elem->m_prev = back;
}


template <typename T>
void List<T>::pop_back()
{
	Node* back = top->m_prev;
	Node* new_back = back->m_prev;

	top->m_prev = new_back;
	new_back->m_next = top;

	delete back;
}

template <typename T>
T& List<T>::front()
{
	return top->m_next->m_data;
}

template <typename T>
T& List<T>::back()
{
	return top->m_prev->m_data;
}

template <typename T>
void List<T>::insert(iterator it, const T& value)
{
	if (it.currentNode == top->m_next)
	{
		this->push_front(value);
		it.currentNode = top->m_next;
	}
	else
	{
		Node* newCurrNode = it.currentNode;
		it.currentNode = new Node;
		newCurrNode = it.currentNode->m_next;
		it.currentNode->m_prev = newCurrNode->m_prev;
		it.currentNode = newCurrNode->m_prev;
		newCurrNode = it.currentNode->m_prev;
		it.currentNode = newCurrNode->m_next;
		it.currentNode->m_data = value;
	}
}

template <typename T>
void List<T>::erase(iterator it)
{
	if (it.currentNode == top->m_next)
	{
		this->pop_front();
		it.currentNode = top->m_next;
	}

	if (it.currentNode == top->m_prev)
	{
		this->pop_back();
		it.currentNode = top->m_prev;
	}

	Node* nextNode = it.currentNode->m_next;
	nextNode->m_prev = it.currentNode->m_prev;
	delete it.currentNode;
	it.currentNode = nextNode->m_prev;
	it.currentNode->m_next = nextNode;
	it.currentNode = nextNode;
}

template <typename T>
int List<T>::size()
{
	Node* node = top;
	int counter = 0;
	while (node != 0)
	{
		counter++;
		node = node->m_next;
	}
	return counter;
}

template <typename T>
void List<T>::clear()
{
	while (!empty())
	{
		pop_front();
	}
	delete top;
}

template <typename T>
bool List<T>::empty()
{
	return top == top->m_next;
}

template <typename T>
List<T>::~List()
{
	while (!empty()) 
	{
		pop_front();
	}
	delete top;
}

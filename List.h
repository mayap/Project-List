#pragma once


//template <typename T>
class List
{
	struct Node
	{
		int m_data;
		Node* m_next;
		Node* m_prev;

		Node(int value) :
			m_data(value), m_next(0), m_prev(0)
		{}

	};

	Node* top;

public:
	List();

	Node* top = new Node(0);

	void push_front(const int value);
	void pop_front();
	void push_back(const int value);
	void pop_back();
	int front();
	int back();

	class iterator
	{
		friend class List;

	private:
		Node* currentNode;

		List* currentList;
		int it;

		iterator(const List* List1, Node* current) : currentList(const_cast<List*>(List1)), currentNode(current)
		{}


	public:

		int operator*() {
			if (currentNode != currentList->top) {
				return currentNode->m_data;
			}
			
		}

		//iterator operator++(){
		//	++it;
		//	currentNode = currentNode->m_next;
		//	//return *this;
		//}
		//iterator operator++(int){
		//	//it++;
		//	//currentNode = 
		//	//return *this;
		//	iterator tmp(*this); 
		//	operator++(); 
		//	return tmp;
		//}
		//bool operator!=(){
		//	
		//}

	};

	iterator begin(){
		iterator it = ;
	}
	iterator end();
	void insert(iterator it, const int value);
	void erase(iterator it);
	int size();
	void clear();
	bool empty();




	~List();


};


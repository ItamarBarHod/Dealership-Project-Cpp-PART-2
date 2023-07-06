#pragma once

#include "Node.h"

template<class T>
class LinkedList
{
private:
	int listSize;
	Node<T>* head;

public:
	LinkedList();
	LinkedList(const LinkedList& other);
	~LinkedList();

	void insertToEnd(T data);
	void remove(int index);
	friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& List);

	Node<T>* getHead() { return head; }
	bool isEmpty() const { return listSize == 0; }
	int size() const { return listSize; }


};
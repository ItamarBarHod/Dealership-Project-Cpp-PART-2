#pragma once

#include <iostream>

template<class T>
class Node
{
private:
	T data;
	Node<T>* next;
public:
	Node(const T& data);
	~Node();

	const T& getData() { return data; }
	Node<T>* getNext() { return next; }
	bool operator==(const Node<T>& node) const { return data == node.data; }

	friend std::ostream& operator<<(std::ostream& os, const Node<T>& node);
};
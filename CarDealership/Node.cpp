#include "Node.h"

template<class T>
Node<T>::Node(const T& data) : data(data), next(nullptr)
{
}

template<class T>
Node<T>::~Node()
{
	if (next)
		delete next;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const Node<T>& node)
{
	os << node.data;
	return  os;
}
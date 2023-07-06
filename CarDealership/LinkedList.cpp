#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList() : head(nullptr), listSize(0)
{
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) : head(other.head), listSize(other.listSize)
{
}

template<class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* current = head;
	for (int i = 0; i < listSize; i++)
	{
		Node<T>* temp = current->getNext();
		delete current;
		current = temp;
	}
}

template<class T>
void LinkedList<T>::insertToEnd(T data)
{
	if (isEmpty())
	{
		head = new Node(data);
	}
	else {
		Node<T>* temp = head;
		while (head)
		{
			temp = head;
			head = head->getNext();
		}
		temp->getNext() = new Node(data);
	}
}

template<class T>
void LinkedList<T>::remove(int index)
{
	if (index < 0 || index >= listSize)
		throw std::out_of_range("index out of list range");
	if (index == 0)
	{
		Node<T>* temp = head->getNext();
		delete head;
		head = temp;
	}
	Node<T>* previous = head, next = head->getNext();
	for (int i = 0; i < index; i++)
	{

	}
}

template<class T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& List)
{
	Node<T>* head = List.getHead();
	while (head)
	{
		os << *head;
		head = head->getNext();
	}
	return os;
}

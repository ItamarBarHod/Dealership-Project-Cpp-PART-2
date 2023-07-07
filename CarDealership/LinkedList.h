#pragma once

template<class T>
class Node
{
public:
	T data;
	Node<T>* next;

public:
	Node(const T& data) : data(data), next(nullptr) {}
	~Node() {}

	template<class T>
	friend std::ostream& operator<<(std::ostream& os, const Node<T>& node)
	{
		os << node.data;
		return  os;
	}
};

template<class T>
class LinkedList
{
public:
	int listSize;
	Node<T>* head;

	LinkedList() : head(nullptr), listSize(0) {}
	LinkedList(const LinkedList& other) : head(other.head), listSize(0)
	{
		Node<T>* node = head;
		while (node)
		{
			insertToEnd(node->data);
			node = node->next;
		}
	}
	~LinkedList()
	{
		while (head)
		{
			Node<T>* previous = head;
			head = head->next;
			delete previous;
		}
	}

	template <class T>
	void insertToEnd(const T& data)
	{
		Node<T>* newNode = new Node<T>(data);
		if (isEmpty())
		{
			head = newNode;
		}
		else {
			Node<T>* temp = head;
			while (temp->next)
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
		listSize++;
	}

	template <class T>
	void remove(int index)
	{
		if (index < 0 || index >= listSize)
			throw std::out_of_range("index out of list range");
		if (head == nullptr)
			return;

		Node<T>* temp = head;
		if (index == 0) {
			head = temp->next;
			delete temp;
			return;
		}
		for (int i = 0; temp != nullptr && i < index - 1; i++)
			temp = temp->next;
		if (temp == nullptr || temp->next == nullptr)
			return;

		Node<T>* next = temp->next->next;
		delete temp->next;
		temp->next = next;
	}

	template<class T>
	friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& List)
	{
		Node<T>* head = List.head;
		while (head)
		{
			os << head->data;
			head = head->next;
		}
		return os;
	}

	bool isEmpty() const { return listSize == 0; }
	int size() const { return listSize; }
};
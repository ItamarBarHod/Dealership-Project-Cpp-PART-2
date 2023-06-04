#include "Worker.h"


Worker::Worker(const char* pName, const Address* address, const Date& birthday, int salary, unsigned numOfAddresses)
	: name(nullptr), address(nullptr), birthday(birthday), salary(salary), numOfAddresses(numOfAddresses)
{
	workerID = ++id;
	setName(pName);
	if (numOfAddresses > 0)
	{
		this->address = new Address[numOfAddresses];
		for (int i = 0; i < numOfAddresses; i++)
		{
			this->address[i] = address[i];
		}
	}
}
Worker::Worker(const Worker& other) : address(nullptr), birthday(other.birthday), salary(other.salary), numOfAddresses(other.numOfAddresses)
{
	workerID = ++id;
	setName(other.name);
	if (other.numOfAddresses > 0)
	{
		address = new Address[other.numOfAddresses];
		for (int i = 0; i < other.numOfAddresses; i++)
		{
			address[i] = other.address[i];
		}
	}
}
Worker::Worker(Worker&& other) : name(nullptr), address(nullptr)
{
	workerID = other.workerID;
	std::swap(name, other.name);
	salary = other.salary;
	numOfAddresses = other.numOfAddresses;
	birthday = other.birthday;
	if (other.numOfAddresses > 0)
	{
		address = new Address[other.numOfAddresses];
		for (int i = 0; i < other.numOfAddresses; i++)
		{
			std::swap(address[i], other.address[i]);
		}
	}
}
Worker& Worker::operator=(const Worker& other)
{
	if (this != &other)
	{
		workerID = other.workerID;
		setName(other.name);
		salary = other.salary;
		numOfAddresses = other.numOfAddresses;
		birthday = other.birthday;
		if (address)
			delete[] address;
		address = nullptr;
		if (other.numOfAddresses > 0)
		{
			address = new Address[other.numOfAddresses];
			for (int i = 0; i < other.numOfAddresses; i++)
			{
				address[i] = other.address[i];
			}
		}
	}
	return *this;
}
Worker& Worker::operator=(Worker&& other)
{
	if (this != &other)
	{
		workerID = other.workerID;
		std::swap(name, other.name);
		salary = other.salary;
		numOfAddresses = other.numOfAddresses;
		birthday = other.birthday;
		if (other.numOfAddresses > 0)
		{
			address = new Address[other.numOfAddresses];
			for (int i = 0; i < other.numOfAddresses; i++)
			{
				std::swap(address[i], other.address[i]);
			}
		}
	}
	return *this;
}
Worker::~Worker()
{
	delete[] name;
	for (int i = 0; i < numOfAddresses; i++)
	{
		delete& address[i];
	}
	delete[] address;
}

std::ostream& Worker::print(std::ostream& out) const
{
	out << "Worker: id: " << workerID << std::endl;
	out << "Name: " << name << std::endl;
	if (address)
	{
		out << "The worker has " << numOfAddresses << "addresses:" << std::endl;
		for (int i = 0; i < numOfAddresses; i++)
		{
			out << address[i] << std::endl;
		}
	}
	else {
		out << "The worker has no address" << std::endl;
	}
	return out;
}

void Worker::setName(const char* str)
{
	if (name)
		delete[] name;
	name = nullptr;
	if (str)
		name = _strdup(str);
}
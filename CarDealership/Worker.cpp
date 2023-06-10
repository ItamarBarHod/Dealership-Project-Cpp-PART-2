#include "Worker.h"

unsigned Worker::id = 1000;

Worker::Worker(std::istream& in)
{
	read(in);
}

Worker::Worker(const char* pName, Address** address, const Date& birthday, int salary, int numOfAddresses)
	: name(nullptr), address(nullptr), birthday(birthday), salary(salary), numOfAddresses(numOfAddresses)
{
	workerID = ++id;
	setName(pName);
	if (numOfAddresses > 0)
	{
		this->address = new Address * [numOfAddresses];
		for (int i = 0; i < numOfAddresses; i++)
		{
			this->address[i] = new Address(*address[i]);
		}
	}
}
Worker::Worker(const Worker& other) : address(nullptr), birthday(other.birthday), salary(other.salary), numOfAddresses(other.numOfAddresses)
{
	workerID = other.workerID;
	setName(other.name);
	if (other.numOfAddresses > 0)
	{
		address = new Address * [other.numOfAddresses];
		for (int i = 0; i < other.numOfAddresses; i++)
		{
			address[i] = new Address(*other.address[i]);
		}
	}
}

Worker::Worker(Worker&& other) noexcept : address(nullptr), name(nullptr)
{
	workerID = other.workerID;
	std::swap(name, other.name);
	salary = other.salary;
	numOfAddresses = other.numOfAddresses;
	birthday = other.birthday;
	if (other.numOfAddresses > 0)
	{
		address = new Address * [other.numOfAddresses];
		for (int i = 0; i < other.numOfAddresses; i++)
		{
			address[i] = nullptr;
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
			address = new Address * [other.numOfAddresses];
			for (int i = 0; i < other.numOfAddresses; i++)
			{
				address[i] = new Address(*other.address[i]);
			}
		}
	}
	return *this;
}
Worker& Worker::operator=(Worker&& other) noexcept
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
			address = new Address * [other.numOfAddresses];
			for (int i = 0; i < other.numOfAddresses; i++)
			{
				address[i] = nullptr;
				std::swap(address[i], other.address[i]);
			}
		}
	}
	return *this;
}
Worker::~Worker()
{
	if (name)
		delete[] name;
	if (address)
	{
		for (int i = 0; i < numOfAddresses; i++)
		{
			delete address[i];
		}
		delete[] address;
	}
}

std::ostream& Worker::print(std::ostream& out) const
{
	if (typeid(out) == typeid(std::ofstream))
	{
		out << workerID << name << std::endl;
		out << numOfAddresses << " ";
		if (address)
		{
			for (int i = 0; i < numOfAddresses; i++)
			{
				out << *address[i];
			}
		}
		out << birthday << std::endl;
		out << salary << " ";
	}
	else {
		out << "id: " << workerID << std::endl;
		out << "Name:" << name << std::endl;
		if (address)
		{
			out << "The worker has " << numOfAddresses << " addresses:" << std::endl;
			for (int i = 0; i < numOfAddresses; i++)
			{
				out << *address[i];
			}
		}
		else {
			out << "The worker has no address" << std::endl;
		}
		out << "Birthday: " << birthday << "\nSalary: " << salary << std::endl;
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

std::ostream& operator<<(std::ostream& out, const Worker& worker)
{
	return worker.print(out);
}

std::istream& Worker::read(std::istream& in)
{
	char buffer[BUFFER_SIZE];
	if (typeid(in) == typeid(std::ifstream))
	{
		in >> workerID;
		id++;
		in.getline(buffer, BUFFER_SIZE);
		name = _strdup(buffer);
		in >> numOfAddresses;
		in.get();
		if (numOfAddresses > 0)
		{
			address = new Address * [numOfAddresses];
			for (int i = 0; i < numOfAddresses; i++)
			{
				address[i] = new Address(in);
			}
		}
		in >> birthday >> salary;
	}
	else {
		std::cout << "Enter worker name: ";
		workerID = ++id;
		in.getline(buffer, BUFFER_SIZE);
		name = _strdup(buffer);
		std::cout << "Enter number of addresses (non negative): ";
		do {
			in >> numOfAddresses;
			in.get();
		} while (numOfAddresses < 0);
		if (numOfAddresses > 0)
		{
			address = new Address * [numOfAddresses];
			for (int i = 0; i < numOfAddresses; i++)
			{
				address[i] = new Address(in);
				in.get();
			}
		}
		std::cout << "Enter birthday day/month/year\n";
		in >> birthday;
		std::cout << "Enter salary: ";
		in >> salary;
	}
	return in;
}
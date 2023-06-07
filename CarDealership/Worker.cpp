#include "Worker.h"

unsigned Worker::id = 1000;

Worker::Worker(std::istream& in) : address(nullptr)
{
	char buffer[100];
	in >> workerID;
	in.getline(buffer, 100);
	name = _strdup(buffer);
	in >> numOfAddresses;
	if (numOfAddresses > 0)
	{
		address = new Address[numOfAddresses];
		for (int i = 0; i < numOfAddresses; i++)
		{
			in >> address[i];
		}
	}
	in >> birthday >> salary;
}

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
Worker::Worker(Worker&& other) noexcept : address(nullptr), name(nullptr)
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
	if (name)
		delete[] name;
	if (address)
		delete[] address;
}

std::ostream& Worker::print(std::ostream& out) const
{
	if (typeid(out) == typeid(std::ofstream))
	{
		out << workerID << " ";
		out << name << std::endl;
		out << numOfAddresses << std::endl;
		if (address)
		{
			for (int i = 0; i < numOfAddresses; i++)
			{
				out << address[i];
			}
		}
		out << birthday << std::endl;
		out << salary << " ";
	}
	else {
		out << "Worker: id: " << workerID << std::endl;
		out << "Name: " << name << std::endl;
		if (address)
		{
			out << "The worker has " << numOfAddresses << " addresses:" << std::endl;
			for (int i = 0; i < numOfAddresses; i++)
			{
				out << address[i];
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
	worker.print(out);
	return out;
}

std::istream& Worker::read(std::istream& in)
{
	char buffer[100];
	if (typeid(in) == typeid(std::ifstream))
	{
		throw "SHOULDNT BE HERE\n";
	}
	else {
		std::cout << "Enter worker name (one word): ";
		workerID = ++id;
		in.getline(buffer, sizeof(buffer));
		name = _strdup(buffer);
		std::cout << "Enter number of addresses (non negative): ";
		do {
			in >> numOfAddresses;
		} while (numOfAddresses < 0);
		if (numOfAddresses > 0)
		{
			address = new Address * [numOfAddresses];
			for (int i = 0; i < numOfAddresses; i++)
			{
				in >> *address[i];
			}
		}
		std::cout << "Enter birthday day/month/year\n";
		in >> birthday;
		std::cout << "Enter salary: ";
		in >> salary;
	}
	return in;
}

std::istream& operator>>(std::istream& in, Worker& worker)
{
	return worker.read();
}
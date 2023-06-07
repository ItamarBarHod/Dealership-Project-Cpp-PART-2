#include "Worker.h"

unsigned Worker::id = 1000;

Worker::Worker() : name(nullptr), address(nullptr), salary(0), numOfAddresses(0)
{
}

Worker::Worker(std::istream& in)
{
	in >> *this;
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
		out << workerID << std::endl;
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

std::istream& operator>>(std::istream& in, Worker& worker)
{
	char buffer[256];
	if (typeid(in) == typeid(std::ifstream))
	{
		in >> worker.workerID;
		in >> buffer;
		worker.name = _strdup(buffer);
		in >> worker.numOfAddresses;
		if (worker.numOfAddresses > 0)
		{
			worker.address = new Address[worker.numOfAddresses];
			for (int i = 0; i < worker.numOfAddresses; i++)
			{
				in >> worker.address[i];
			}
		}
		in >> worker.birthday >> worker.salary;
	}
	else {
		std::cout << "Enter worker name (one word): ";
		worker.workerID = ++worker.id;
		in.getline(buffer, sizeof(buffer));
		worker.name = _strdup(buffer);
		std::cout << "Enter number of addresses (non negative): ";
		do {
			in >> worker.numOfAddresses;
		} while (worker.numOfAddresses < 0);
		if (worker.numOfAddresses > 0)
		{
			worker.address = new Address[worker.numOfAddresses];
			for (int i = 0; i < worker.numOfAddresses; i++)
			{
				in >> worker.address[i];
			}
		}
		std::cout << "Enter birthday day/month/year\n";
		in >> worker.birthday;
		std::cout << "Enter salary: ";
		in >> worker.salary;
	}
	return in;
}
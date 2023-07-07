#include "Worker.h"

unsigned Worker::id = 1000;

Worker::Worker(std::istream& in)
{
	read(in);
}

Worker::~Worker()
{
}

std::ostream& Worker::print(std::ostream& out) const
{
	if (typeid(out) == typeid(std::ofstream))
	{
		printToFile(out);
	}
	else {
		printToScreen(out);
	}
	return out;
}

std::istream& Worker::read(std::istream& in)
{
	if (typeid(in) == typeid(std::ifstream))
	{
		readFromFile(in);
	}
	else {
		readFromUser(in);
	}
	return in;
}

std::ostream& Worker::printToFile(std::ostream& out) const
{
	out << workerID << std::endl;
	out << name << std::endl;
	out << addressList.size() << " ";
	out << addressList << std::endl;
	out << birthday << std::endl;
	out << salary << " ";
	return out;
}

std::ostream& Worker::printToScreen(std::ostream& out) const
{
	out << "id: " << workerID << std::endl;
	out << "Name: " << name << std::endl;
	int size = addressList.size();
	if (size > 0)
	{
		out << "The worker has " << size << " addresses:" << std::endl;
		out << addressList;
	}
	else {
		out << "The worker has no address" << std::endl;
	}
	out << "Birthday: " << birthday << "\nSalary: " << salary << std::endl;
	return out;
}

std::ostream& operator<<(std::ostream& out, const Worker& worker)
{
	return worker.print(out);
}

std::istream& Worker::readFromUser(std::istream& in)
{
	int addressCount;
	std::cout << "Enter worker name: ";
	workerID = ++id;
	std::getline(in, name);
	std::cout << "Enter number of addresses (non negative): ";
	in >> addressCount;
	if (addressCount < 0)
		throw std::invalid_argument("Worker initialization failed: can't have negative number of address");
	in.get();
	for (int i = 0; i < addressCount; i++)
	{
		addressList.insertToEnd(Address(in));
		in.get();
	}
	std::cout << "Enter birthday day/month/year\n";
	in >> birthday;
	std::cout << "Enter salary: (non negative) ";
	in >> salary;
	if (salary < 0)
		throw std::invalid_argument("Worker initialization failed: can't have negative salary");
	return in;
}

std::istream& Worker::readFromFile(std::istream& in)
{
	int addressCount;
	in >> workerID;
	in.get();
	id++;
	std::getline(in, name);
	in >> addressCount;
	in.get();
	for (int i = 0; i < addressCount; i++)
	{
		addressList.insertToEnd(Address(in));
	}
	in >> birthday >> salary;
	return in;
}

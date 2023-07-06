#include "Worker.h"

unsigned Worker::id = 1000;

Worker::Worker(std::istream& in)
{
	read(in);
}

Worker::Worker(const std::string& pName, const LinkedList<Address*>& address, const Date& birthday, int salary)
	: name(pName), birthday(birthday), salary(salary), addressList(address)
{
	workerID = ++id;
}

Worker::~Worker()
{
}

std::ostream& Worker::print(std::ostream& out) const
{
	if (typeid(out) == typeid(std::ofstream))
	{
		out << workerID << name << std::endl;
		out << addressList.size() << " ";
		out << addressList << std::endl;
		out << birthday << std::endl;
		out << salary << " ";
	}
	else {
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
	}
	return out;
}

std::ostream& operator<<(std::ostream& out, const Worker& worker)
{
	return worker.print(out);
}

std::istream& Worker::read(std::istream& in)
{
	int addressCount;
	if (typeid(in) == typeid(std::ifstream))
	{
		in >> workerID;
		id++;
		std::getline(in, name);
		in >> addressCount;
		in.get();
		for (int i = 0; i < addressCount; i++)
		{
			addressList.insertToEnd(new Address(in));
		}
		in >> birthday >> salary;
	}
	else {
		std::cout << "Enter worker name: ";
		workerID = ++id;
		std::getline(in, name);
		std::cout << "Enter number of addresses (non negative): ";
		do {
			in >> addressCount;
			in.get();
		} while (addressCount < 0);
		for (int i = 0; i < addressCount; i++)
		{
			addressList.insertToEnd(new Address(in));
			in.get();
		}
		std::cout << "Enter birthday day/month/year\n";
		in >> birthday;
		std::cout << "Enter salary: ";
		in >> salary;
	}
	return in;
}
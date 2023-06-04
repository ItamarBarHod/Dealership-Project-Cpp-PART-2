#pragma once

#include <iostream>
#include "Date.h"
#include "Address.h"

class Worker {
private:
	static unsigned id;
	unsigned workerID;
	char* name;
	Address* address;
	unsigned numOfAddresses;
	Date birthday;
	int salary;

protected:
	virtual std::ostream& print(std::ostream& out) const;

public:
	Worker();
	Worker(const char* pName, const Address* address, const Date& birthday, int salary, unsigned numOfAddresses);
	Worker(const Worker& other);
	Worker(Worker&& other) noexcept;
	Worker& operator=(const Worker& other);
	Worker& operator=(Worker&& other);
	virtual ~Worker();

	friend std::ostream& operator<<(std::ostream& out, const Worker& worker);
	friend std::istream& operator>>(std::istream& in, Worker& worker);

	int getSalary() const { return salary; }
	void setSalary(int salary) { this->salary = salary; }
	void setName(const char* str);
	const Address* getAddress() const { return address; }
	unsigned getNumOfAddress() const { return numOfAddresses; }
	const Date& getBirthday() const { return birthday; }
	const char* getName() const { return name; }
};

unsigned Worker::id = 1000;


std::ostream& operator<<(std::ostream& out, const Worker& worker)
{
	worker.print(out);
	return out;
}

std::istream& operator>>(std::istream& in, Worker& worker)
{
	return in;
}
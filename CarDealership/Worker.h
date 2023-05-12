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
public:
	Worker(const char* name, const Address* address, Date& birthday, int salary, unsigned numOfAddresses);
	Worker(const Worker& other);
	Worker(Worker&& other);
	Worker& operator=(const Worker& other);
	Worker& operator=(Worker&& other);
	virtual ~Worker();

	friend std::ostream& operator<<(std::ostream& out, const Worker& worker);
	int getSalary() const;
	void setSalary(unsigned salary);
	const Address* getAddress() const;
	unsigned getNumOfAddress() const;
	const Date& getBirthday() const;
	const char* getName() const;
};

unsigned Worker::id = 1000;
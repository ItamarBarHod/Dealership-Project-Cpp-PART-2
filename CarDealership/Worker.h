#pragma once

#include <iostream>
#include "Date.h"
#include "Address.h"

class Worker {
protected:
	static unsigned id;
	unsigned workerID;
	char* name;
	Address* address;
	Date birthday;
	int salary;

protected:
	virtual void toOs(std::ostream& out) const;

public:
	Worker(const char* name, Address& address, Date& birthday, int salary);
	Worker(const Worker& other);
	Worker(Worker&& other);
	Worker& operator=(const Worker& other);
	Worker& operator=(Worker&& other);
	virtual ~Worker();

	friend virtual std::ostream& operator<<(std::ostream& out, const Worker& worker);
	int getSalary() const;
	void setSalary(unsigned salary);
	const Date& getBirthday() const;
	const char* getName() const;
};

unsigned Worker::id = 1000;
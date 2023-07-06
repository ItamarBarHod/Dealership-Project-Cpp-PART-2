#pragma once

#include "Date.h"
#include "Address.h"
#include "LinkedList.h"

class Worker {
protected:
	static unsigned id;
	unsigned workerID;
	std::string name;
	LinkedList<Address*> addressList;
	Date birthday;
	int salary;

protected:
	Worker(std::istream& in);
	Worker(const std::string& pName, const LinkedList<Address*>& address, const Date& birthday, int salary);
	virtual ~Worker();

	virtual std::ostream& print(std::ostream& out) const;
	virtual std::istream& read(std::istream& in);

public:
	friend std::ostream& operator<<(std::ostream& out, const Worker& worker);

	int getSalary() const { return salary; }
	void setSalary(int salary) { this->salary = salary; }
	int getNumOfAddress() const { return addressList.size(); }
	const Date& getBirthday() const { return birthday; }
	const std::string& getName() const { return name; }
};

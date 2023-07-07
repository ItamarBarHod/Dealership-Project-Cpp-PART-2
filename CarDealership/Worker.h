#pragma once

#include "Date.h"
#include "Address.h"
#include "LinkedList.h"

class Worker {
protected:
	static unsigned id;
	unsigned workerID;
	std::string name;
	LinkedList<Address> addressList;
	Date birthday;
	int salary;

protected:
	Worker(std::istream& in);
	virtual ~Worker();

	virtual std::ostream& print(std::ostream& out) const;
	virtual std::ostream& printToFile(std::ostream& out) const;
	virtual std::ostream& printToScreen(std::ostream& out) const;
	virtual std::istream& read(std::istream& in);
	virtual std::istream& readFromUser(std::istream& in);
	virtual std::istream& readFromFile(std::istream& in);

public:
	friend std::ostream& operator<<(std::ostream& out, const Worker& worker);

	void setSalary(int salary) { this->salary = salary; }

	int getSalary() const { return salary; }
	int getNumOfAddress() const { return addressList.size(); }
	const Date& getBirthday() const { return birthday; }
	const std::string& getName() const { return name; }
};

#pragma once

#include "Date.h"
#include "Address.h"

class Worker {
private:
	static unsigned id;
	unsigned workerID;
	char* name;
	Address** address;
	int numOfAddresses;
	Date birthday;
	int salary;

protected:
	virtual std::ostream& print(std::ostream& out) const;
	virtual std::istream& read(std::istream& in)

public:
	Worker(std::istream& in);
	Worker(const char* pName, const Address* address, const Date& birthday, int salary, unsigned numOfAddresses);
	Worker(const Worker& other);
	Worker(Worker&& other) noexcept;
	Worker& operator=(const Worker& other);
	Worker& operator=(Worker&& other) noexcept;
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
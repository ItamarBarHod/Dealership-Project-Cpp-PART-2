#include <iostream>
#include "Date.h"
#include "Location.h"

class Worker {
private:
	char* name;
	Location* address;
	Date birthDay;
	int salary;
public:

	friend virtual std::ostream& operator<<(std::ostream& out, const Worker& worker);
	int getSalary() const;
	void setSalary(unsigned salary);
	const Date& getBirthday() const;
	const char* getName() const;
};
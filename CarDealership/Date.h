#pragma once
#include <iostream>

class Date {
private:
	int year;
	unsigned month;
	unsigned day;
public:
	Date(int year = 1995, unsigned month = 7, unsigned day = 27);

	friend std::ostream& operator<<(std::ostream& out, const Date& date);

	int getYear() const;
	unsigned getMonth() const;
	unsigned getDay() const;
};

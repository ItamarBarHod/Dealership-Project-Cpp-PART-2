#pragma once

#include <iostream>
#include <fstream>

class Date {
	const static int MAX_MONTH = 12;
	const static int MAX_DAY = 31;
	const static int MAX_YEAR = 2023;

private:
	int year;
	unsigned month;
	unsigned day;
public:
	Date();
	Date(std::ifstream& file);
	Date(int year, unsigned month, unsigned day);

	friend std::ostream& operator<<(std::ostream& out, const Date& date);
	friend std::istream& operator>>(std::istream& in, Date& date);

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	int getYear() const { return year; }
	unsigned getMonth() const { return month; }
	unsigned getDay() const { return day; }
};
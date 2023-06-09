#ifndef DATE_H
#define DATE_H
#pragma once

#include <iostream>
#include <fstream>

class Date {
	const static int MAX_MONTH = 12;
	const static int MAX_DAY = 31;
	const static int MIN_YEAR = 1970;
	const static int MAX_YEAR = 2023;

private:
	int year;
	unsigned month;
	unsigned day;

	std::istream& read(std::istream& in);

public:
	Date(std::istream& in);
	Date(int year = 1995, unsigned month = 7, unsigned day = 27);

	friend std::ostream& operator<<(std::ostream& out, const Date& date);
	friend std::istream& operator>>(std::istream& in, Date& date);

	int getYear() const { return year; }
	unsigned getMonth() const { return month; }
	unsigned getDay() const { return day; }
};

#endif
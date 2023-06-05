#pragma once
#include <iostream>
#include <fstream>

class Date {
	const int MAX_MONTH = 12;
	const int MAX_DAY = 31;
	const int MAX_YEAR = 2023;

private:
	int year;
	unsigned month;
	unsigned day;
public:

	Date(int year = 1995, unsigned month = 7, unsigned day = 27);

	friend std::ostream& operator<<(std::ostream& out, const Date& date);
	friend std::istream& operator>>(std::istream& in, Date& date);

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	int getYear() const { return year; }
	unsigned getMonth() const { return month; }
	unsigned getDay() const { return day; }
};


std::ostream& operator<<(std::ostream& out, const Date& date)
{
	if (typeid(out) == typeid(std::ofstream))
	{
		out << date.day << " " << date.month << " " << date.year << std::endl;
	}
	else {
		out << "Date: " << date.day << "/" << date.month << "/" << date.year << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Date& date)
{
	if (typeid(in) == typeid(std::ifstream))
	{
		char delimiter;
		in >> date.day >> delimiter >> date.month >> delimiter >> date.year;
	}
	else {
		in >> date.day >> date.month >> date.year;
	}
	return in;
}
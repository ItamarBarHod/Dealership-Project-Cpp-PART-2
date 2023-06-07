#include "Date.h"


Date::Date()
{
}

Date::Date(std::ifstream& file) : year(0), month(0), day(0)
{
	file >> *this;
}

Date::Date(int year, unsigned month, unsigned day) : year(year), month(month), day(day)
{
}

void Date::setDay(int day)
{
	if (day < 0 || day > MAX_DAY)
	{
		return;
	}
	this->day = day;
}

void Date::setMonth(int month)
{
	if (month < 0 || month > MAX_DAY)
	{
		return;
	}
	this->month = month;
}
void Date::setYear(int year)
{
	if (month < 0 || month > MAX_DAY)
	{
		return;
	}
	this->month = month;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	if (typeid(out) == typeid(std::ofstream))
	{
		out << date.day << " " << date.month << " " << date.year;
	}
	else {
		out << date.day << "/" << date.month << "/" << date.year;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Date& date)
{
	if (typeid(in) == typeid(std::ifstream))
	{
		in >> date.day >> date.month >> date.year;
	}
	else {
		std::cout << "Enter day: ";
		in >> date.day;
		std::cout << "Enter month: ";
		in >> date.month;
		std::cout << "Enter year: ";
		in >> date.year;
	}
	return in;
}
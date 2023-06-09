#include "Date.h"


Date::Date(std::istream& in)
{
	read(in);
}

Date::Date(int year, unsigned month, unsigned day) : year(year), month(month), day(day)
{
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

std::istream& Date::read(std::istream& in)
{
	if (typeid(in) == typeid(std::ifstream))
	{
		in >> day >> month >> year;
	}
	else {
		auto validDate = [=](int day, int month, int year) -> bool
		{
			return day > 0 && day <= 31 && month > 1 && month <= 12 && year >= MIN_YEAR && year <= MAX_YEAR;
		};

		int arr[3] = { 0 };
		bool isValid;
		do {
			std::cout << "Enter day (between 1 and 31): ";
			in >> arr[0];
			std::cout << "Enter month (between 1 and 12): ";
			in >> arr[1];
			std::cout << "Enter year (between " << MIN_YEAR << " and " << MAX_YEAR << "): ";
			in >> arr[2];
			isValid = validDate(arr[0], arr[1], arr[2]);
			if (!isValid)
				std::cout << "Invalid date, try again" << std::endl;
		} while (!isValid);
		day = arr[0];
		month = arr[1];
		year = arr[2];
	}
	return in;
}

std::istream& operator>>(std::istream& in, Date& date)
{
	return date.read(in);
}
#include "Date.h"


Date::Date(int year, unsigned month, unsigned day)
{
	setDay(day);
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

}
void Date::setYear(int year)
{

}
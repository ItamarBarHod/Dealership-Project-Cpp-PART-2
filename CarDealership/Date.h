#include <iostream>

class Date {
private:
	int year;
	unsigned month;
	unsigned day;
public:
	Date();
	Date(int year, unsigned month, unsigned day);
	friend std::istream& operator>>(std::istream& in, const Date& date);
};
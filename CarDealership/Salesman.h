#include "Worker.h"

class Salesman : public Worker {
private:
	unsigned numOfDeals;
	double totalSales;
public:
	Salesman();
	Salesman(const char* name, Address& address, Date& birthday, int salary);
	friend std::ostream& operator<<(std::ostream& out, const Salesman& salesman);
	double getAverageProfit() const; // totalSales / numOfDeals
	bool operator>=(const Salesman& other);
};
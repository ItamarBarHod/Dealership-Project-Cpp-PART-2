
class Location {
private:
	char* city;
	char* street;
	unsigned houseNum;
public:
	Location(const char* city, const char* street, unsigned houseNum);
	Location(const Location& other);
	Location(Location&& other);
	const Location& operator=(const Location& other);
	const Location& operator=(Location&& other);
	~Location();

	const char* getCity() const;
	const char* getStreet() const;
	unsigned getHouseNum() const;

};
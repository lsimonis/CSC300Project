#pragma once
#include <string>
using namespace std;


class Product
{
public:
	Product();
	Product(int UPC, string name, double price);
	Product(int UPC);
	~Product();

	// Get methods
	int getUPC() const;
	string getName() const;
	double getPrice() const;

	// Set Methods
	void setUPC(int UPC);
	void setName(string name);
	void setPrice(double price);

	void print() const;

private:
	string name;
	int UPC;
	double price;
};

#pragma once
#include <string>

using namespace std;

class Product {
public:
	// Constructors
	Product();

	Product(int upc, string name, double price);

	// Destructors
	~Product();

	// Get methods
	int const getUpc();

	string const getName();

	double const getPrice();

	// Set methods
	void setUpc(int upc);

	void setName(string name);

	void setPrice(double price);
	
private:
	// Member variables
	int m_upc;
	
	string m_name;
	
	double m_price;

};
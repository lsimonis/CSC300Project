#pragma once
#include <string>
using namespace std;


class BusinessInfo
{
public:
	BusinessInfo();
	~BusinessInfo();

	// Get methods
	string getName() const;
	string getAddress() const;
	string getCity() const;
	string getState() const;
	string getZipCode() const;
	double getSalesTax() const;

	// Set methods
	void setName(string name);
	void setAddress(string address);
	void setCity(string city);
	void setState(string state);
	void setZipCode(string zipCode);
	void setSalesTax(double salesTax);
	
	// Operators
	void saveBusinessInfo();
	void print() const;

private:
	string name, address, city, state, zipCode;
	double salesTax;
};

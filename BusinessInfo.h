#pragma once

#include <iostream>

using namespace std;

class BusinessInfo {
public:
	// Constructors
	BusinessInfo();

	BusinessInfo(string name, string address, string city, string state, string zipCode,
		double salesTax);
	// Destructors
	~BusinessInfo();

	// Get methods
	string getName();

	string getAddress();

	string getCity();

	string getState();

	string getZipCode();

	double getSalesTax();

	// Set methods
	void const setName(string name);

	void const setAddress(string address);

	void const setCity(string city);

	void const setState(string state);

	void const setZipCode(string zipCode);

	void const setSalesTax(double salesTax);

	// Print method
	friend ostream& operator<<(ostream& outputStream, const BusinessInfo& businessInfo);
private:
	// Member variables
	string m_name;
	
	string m_address;
	
	string m_city;
	
	string m_state;
	
	string m_zipCode;

	double m_salesTax;
};
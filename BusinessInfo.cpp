#include "BusinessInfo.h"
#include <iostream>
#include <string>

using namespace std;

// Constructors
BusinessInfo::BusinessInfo()
{
	m_name, m_address, m_city, m_state, m_zipCode = "";
	m_salesTax = 0.0;
}

BusinessInfo::BusinessInfo(string name, string address, string city, string state,
	string zipCode, double salesTax)
{
	m_name = name;
	m_address = address;
	m_city = city;
	m_state = state;
	m_zipCode = zipCode;
	m_salesTax = salesTax;
}

// Destructors
BusinessInfo::~BusinessInfo() {};

// Get methods
string BusinessInfo::getName()
{
	return m_name;
}

string BusinessInfo::getAddress()
{
	return m_address;
}

string BusinessInfo::getCity()
{
	return m_city;
}

string BusinessInfo::getState()
{
	return m_state;
}

string BusinessInfo::getZipCode()
{
	return m_zipCode;
}

double BusinessInfo::getSalesTax()
{
	return m_salesTax;
}

// Set methods
void const BusinessInfo::setName(string name)
{
	m_name = name;
}

void const BusinessInfo::setAddress(string address)
{
	m_address = address;
}

void const BusinessInfo::setCity(string city)
{
	m_city = city;
}

void const BusinessInfo::setState(string state)
{
	m_state = state;
}

void const BusinessInfo::setZipCode(string zipCode)
{
	m_zipCode = zipCode;
}

void const BusinessInfo::setSalesTax(double salesTax)
{
	m_salesTax = salesTax;
}

// Print method
// Overrides the << operator to print the business info when called on a BusinessInfo
// object. 
// Example:
	// cout << business1;
// Produces:
	// "Business Name
	// 1234 Easy Street
	// San Diego, CA 55555"
ostream& operator<<(ostream& outputStream, const BusinessInfo& businessInfo)
{
	// Set the outputStream
	outputStream
		<< businessInfo.m_name << endl
		<< businessInfo.m_address << endl
		<< businessInfo.m_city << ", "
		<< businessInfo.m_state << " "
		<< businessInfo.m_zipCode << endl;
	
	// Return the ostream object
	return outputStream;
}
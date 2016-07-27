#include <fstream>
#include <iostream>
#include <vector>
#include "BusinessInfo.h"


// Constructor
BusinessInfo::BusinessInfo()
{
	size_t pos = 0;
	string tmpString;
	vector<string> token;
	string delimiter = ",";
	fstream infile;

	infile.open("BusinessInfo.txt", ios::in);

	// If file fails to open then create a new file to load from
	if (infile.fail())
	{
		infile.clear();
		infile.close();

		fstream outfile;
		outfile.open("BusinessInfo.txt", ios::out);
		outfile << "Name" << delimiter << "Address" << delimiter << "City" << delimiter << "State" << delimiter << "ZipCode" << delimiter << 0.0 << delimiter;
		outfile.close();

		infile.open("BusinessInfo.txt", ios::in);
		getline(infile, tmpString);
		infile.close();

		while ((pos = tmpString.find(delimiter)) != string::npos)
		{
			token.push_back(tmpString.substr(0, pos));
			tmpString.erase(0, pos + delimiter.length());
		}

		// Set attributes with data from BusinessInfo.txt
		name = token[0];
		address = token[1];
		city = token[2];
		state = token[3];
		zipCode = token[4];
		salesTax = std::stod(token[5]);
	}

	// Load data from BusinessInfo.txt
	else
	{
		getline(infile, tmpString);
		infile.close();

		while ((pos = tmpString.find(delimiter)) != string::npos)
		{
			token.push_back(tmpString.substr(0, pos));
			tmpString.erase(0, pos + delimiter.length());
		}

		// Set attributes with data from BusinessInfo.txt
		name = token[0];
		address = token[1];
		city = token[2];
		state = token[3];
		zipCode = token[4];
		salesTax = std::stod(token[5]);
	}
}


//De-Constructor
BusinessInfo::~BusinessInfo()
{
}


// Get methods
string BusinessInfo::getName() const
{
	return name;
}


string BusinessInfo::getAddress() const
{
	return address;
}


string BusinessInfo::getCity() const
{
	return city;
}


string BusinessInfo::getState() const
{
	return state;
}


string BusinessInfo::getZipCode() const
{
	return zipCode;
}


double BusinessInfo::getSalesTax() const
{
	return salesTax;
}


// Set methods
void BusinessInfo::setName(string name)
{
	this->name = name;
}


void BusinessInfo::setAddress(string address)
{
	this->address = address;
}


void BusinessInfo::setCity(string city)
{
	this->city = city;
}


void BusinessInfo::setState(string state)
{
	this->state = state;
}


void BusinessInfo::setZipCode(string zipCode)
{
	this->zipCode = zipCode;
}


void BusinessInfo::setSalesTax(double salesTax)
{
	this->salesTax = salesTax;
}


// Save current info to BusinessInfo.txt
void BusinessInfo::saveBusinessInfo()
{
	string delimiter = ",";

	fstream outfile;
	outfile.open("BusinessInfo.txt", ios::out);
	outfile << getName() << delimiter << getAddress() << delimiter << getCity() << delimiter << getState() << delimiter << getZipCode() << delimiter << getSalesTax() << delimiter;
	outfile.close();
}


void BusinessInfo::print() const
{
	cout << "Name:       " << getName() << endl;
	cout << "Address:    " << getAddress() << endl;
	cout << "City:       " << getCity() << endl;
	cout << "State:      " << getState() << endl;
	cout << "Zip Code:   " << getZipCode() << endl;
	cout << "Sales Tax:  " << getSalesTax() << "%" << endl;
}

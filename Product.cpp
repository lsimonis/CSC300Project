#include <fstream>
#include <iostream>
#include "Product.h"


//  Default Constructor
Product::Product()
{
	UPC = 0;
	name = "";
	price = 0;
}


// Constructor
Product::Product(int UPC, string name, double price)
{
	this->UPC = UPC;
	this->name = name;
	this->price = price;
}

Product::Product(int UPC) : UPC(UPC)
{
}


// De-constructor
Product::~Product()
{
}


// Get methods
int Product::getUPC() const
{
	return UPC;
}


string Product::getName() const
{
	return name;
}


double Product::getPrice() const
{
	return price;
}


// Set Methods
void Product::setUPC(int UPC)
{
	this->UPC = UPC;
}


void Product::setName(string name)
{
	this->name = name;
}


void Product::setPrice(double price)
{
	this->price = price;
}


void Product::print() const
{
	cout << "UPC:    " << getUPC() << endl;
	cout << "Name:   " << getName() << endl;
	cout << "Price:  " << getPrice() << endl;
}

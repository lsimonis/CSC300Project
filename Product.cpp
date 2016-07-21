#include "Product.h"

using namespace std;

// Constructors
Product::Product() {
	m_upc = 0;
	m_name = "";
	m_price = 0.0;
}
Product::Product(int upc, string name, double price) {
	m_upc = upc;
	m_name = name;
	m_price = price;
}

// Destructors
Product::~Product() {}

// Get methods
int const Product::getUpc()
{
	return m_upc;
}

string const Product::getName()
{
	return m_name;
}

double const Product::getPrice()
{
	return m_price;
}

// Set methods
void Product::setUpc(int upc)
{
	m_upc = upc;
}

void Product::setName(string name)
{
	m_name = name;
}

void Product::setPrice(double price)
{
	m_price = price;
}
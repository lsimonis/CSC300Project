#include "Invoice.h"
#include <iostream>
#include <iomanip>


Invoice::Invoice(BusinessInfo b):m_business(b)
{
}

Invoice::~Invoice()
{
}

void Invoice::addLineItem(LineItem l)
{
	m_lineItems.push_back(l);
}

void Invoice::printInvoice()
{
	std::cout << std::fixed;
	std::cout << std::setprecision(2);

	vector<LineItem>::const_iterator it;
	for (it = m_lineItems.begin(); it < m_lineItems.end(); ++it) {
		std::cout << "\t\t" << m_business.getName() << std::endl;
		std::cout << "Item";
		if ((it->getQuantity()) > 1) 
			std::cout << "\tX " << it->getQuantity();
		else std::cout << "\t\t";
		std::cout << it->getProduct()->getPrice()<<std::endl;
	}
	std::cout << "--------------------------------------------" << std::endl
		<< "\t\t\tSubtotal:\t$" << this->calculateSubtotal() << std::endl
		<< "\t\t\tSales Tax:\t$" << this->calculateSalestax() << std::endl
		<< "\t\tTotal:\t$" << this->calculateTotal() << std::endl << std::endl;
}

double Invoice::calculateSubtotal() const
{
	double subtotal = 0;
	vector<LineItem>::const_iterator it;

	for (it = m_lineItems.begin(); it < m_lineItems.end(); ++it) {
		subtotal += it->getProduct()->getPrice();
	}
	return subtotal;
}

double Invoice::calculateSalestax() const
{
	return (m_business.getSalesTax()) * (this->calculateSubtotal());
}

double Invoice::calculateTotal() const
{
	return (this->calculateSubtotal()) * (m_business.getSalesTax() + 1);
}

void Invoice::updateInventory() const
{
	Inventory inventory("inventory.csv");

	vector<LineItem>::const_iterator it;

	for (it = m_lineItems.begin(); it < m_lineItems.end(); ++it) {
		
		Product product = *(it->getProduct());

		inventory.updateQuantity(product, it->getQuantity());
	}

}

bool Invoice::isEmpty() const
{
	return m_lineItems.empty();
}


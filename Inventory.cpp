#include "Inventory.h"

#include <iostream>

Inventory::Inventory(std::string f): m_file(f)
{

}

Inventory::~Inventory()
{
	
}

void Inventory::addProduct(Product &p, int q)
{
	try {
		m_fstream.open(m_file.c_str(), fstream::out | fstream::app);
		if (m_fstream.fail()) throw std::invalid_argument("Faile to add Product to Inventory");
		m_fstream << p.getUpc() << "," << p.getName() << "," << p.getPrice() << q << std::endl;		
		m_fstream.close()
	}
	catch (std::invalid_argument &e) {
		std::cerr << e.what() << std::endl;	//todo: write custom exception classes. -lsimonis
	}
	catch (...) {
		std::cerr << "Error, call support\n";
	}
}
void Inventory::removeProduct(Product &p)
{
	std::string search, match = to_string(p.getUpc());

	try {
		m_fstream.open(m_file.c_str(), fstream::in | fstream::app);
		if (m_fstream.fail()) throw std::invalid_argument("Faile to add Product to Inventory");
	}
	catch (std::invalid_argument &e) {
		std::cerr << e.what() << std::endl;	//todo: write custom exception classes. -lsimonis
	}
	catch (...) {
		std::cerr << "Error, call support\n";
	}

	while (m_fstream.good()) {
		std::getline(m_fstream, search, ',');

		if(search == )
	}

}

void Inventory::updateQuantity(int u, int q)
{
}

void Inventory::setQuantity(int u, int q)
{
}

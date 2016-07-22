#include "Inventory.h"

#include <iostream>

Inventory::Inventory(std::string f) : m_file(f)
{
	std::fstream fstr;
	/* "Touch" inventory file to create it on filesystem. */
	try {
		fstr.open(f.c_str(), ios::out);
		if (fstr.fail()) throw std::runtime_error("Failed to create Inventory file");
		fstr.close();
	}
	catch (std::runtime_error &e) {
		std::cerr << e.what() << std::endl;	//todo: write custom exception classes. -lsimonis
	}
	catch (...) {
		std::cerr << "Unknown error creating Inventory file -- call support\n";

	}
}

Inventory::~Inventory()
{
}

void Inventory::addProduct(Product &p, int q)
{
	std::fstream fstr;
	std::string line,
		token,
		delimiter = ",";

	try{
		fstr.open(m_file.c_str(), ios::in);

		if (fstr.fail()) throw std::runtime_error("Failed to add open Inventory file");

		while (std::getline(fstr, line, '\n')) {	//get each line in inventory file, check upc to prevent duplicates
			token = line.substr(0, line.find(delimiter));
			
			if (token == std::to_string(p.getUpc())) throw std::invalid_argument("That UPC is already in the Inventory. Try updating the existing record instead.");

		}
		fstr.close();
		fstr.open(m_file.c_str(), ios::out|ios::app);
		if (fstr.fail()) throw std::runtime_error("Failed to add open Inventory file");
		fstr << p.getUpc() << delimiter << p.getName() << delimiter << p.getPrice() << delimiter << q << std::endl;		
		fstr.close();
	}
	catch (std::runtime_error &e1) {
		std::cerr << e1.what() << std::endl;	//todo: write custom exception classes. -lsimonis
	}
	catch (std::invalid_argument &e2) {
		std::cerr << e2.what() << std::endl;
		fstr.close();
	}
	catch (...) {
		std::cerr << "Unknown error opening inventory file -- call support\n";
	}
}
void Inventory::removeProduct(Product &p)
{
	std::fstream fstr;
	int count = 0, 
		pos=0;
	std::string line, 
		delimiter = ",", 
		token1, 
		token2, 
		token3, 
		token4, 
		match = to_string(p.getUpc()), 
		tempfile = m_file + ".tmp";
	std::fstream temp_fstream;

	try {	//Open Inventory fstream
		fstr.open(m_file.c_str(), ios::in);
		if (fstr.fail()) throw std::runtime_error("Failed to open Inventory file.");
	}
	catch (std::runtime_error &e) {
		std::cerr << e.what() << std::endl;	//todo: write custom exception classes. -lsimonis
	}
	catch (...) {
		std::cerr << "Unknown error opening Inventory file -- call support\n";
	}

	try {	//Open temporary fstream/file
		temp_fstream.open(tempfile.c_str(), fstream::out | fstream::app);
		if (temp_fstream.fail()) throw std::runtime_error("Failed to  open temporary file");
	}
	catch (std::runtime_error &e) {
		std::cerr << e.what() << std::endl;	//todo: write custom exception classes. -lsimonis
	}
	catch (...) {
		std::cerr << "Unkown error opening temporary file call support\n";
	}

	while (std::getline(fstr, line, '\n')) {	//get each line in inventory file, add those that don't match product to be removed to a temporary file.
		pos = line.find(delimiter);
		token1 = line.substr(0, pos);
		line.erase(0, pos + delimiter.length());
		pos = line.find(delimiter);
		token2 = line.substr(0, pos);
		line.erase(0, pos + delimiter.length());
		pos = line.find(delimiter);
		token3 = line.substr(0, pos);
		line.erase(0, pos + delimiter.length());
		pos = line.find('\n');
		token4 = line.substr(0, pos);

		if (token1 != match) {
			temp_fstream << token1 << delimiter << token2 << delimiter << token3 << delimiter <<token4<< std::endl;
		}
		else ++count;
	}
	fstr.close();
	temp_fstream.close();
/*
	if (count == 1) std::cout << std::endl << count << " line deleted" << std::endl;
	else std::cout << std::endl << count << " lines deleted." << std::endl;
	*/
	try {		//Delete existing inventory file.
		if (remove(m_file.c_str()) != 0) throw std::runtime_error("Could Not Remove old inventory file");
	}
	catch (std::runtime_error &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Unknown error removing old inventory file -- call support\n";
	}

	try {		//Rename new inventory file to original filename.
		if (rename(tempfile.c_str(), m_file.c_str()) != 0) throw std::runtime_error("Could Not Rename new Inventory File");
	}
	catch (std::runtime_error &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Unknown error renaming inventory file -- call support\n";
	}

}

void Inventory::updateQuantity(Product &p, int q)
{
	std::fstream fstr;
	int pos,
		quantity;
	std::string token1,
		token2,
		token3,
		token4,
		line,
		delimiter = ",";

	try {	//Open Inventory fstream
		fstr.open(m_file.c_str(), ios::in);
		if (fstr.fail()) throw std::runtime_error("Failed to open Inventory file.");

		while (std::getline(fstr, line, '\n')) {	//get each line in inventory file, tokenize csv
			pos = line.find(delimiter);
			token1 = line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
			pos = line.find(delimiter);
			token2 = line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
			pos = line.find(delimiter);
			token3 = line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
			pos = line.find('\n');
			token4 = line.substr(0, pos);



			if (token1 == std::to_string(p.getUpc())) {
				quantity = std::stoi(token4);
				quantity += q;
				fstr.close();
				this->removeProduct(p);
				this->addProduct(p, quantity);
			}
		}
		fstr.close();
	}
	catch (std::runtime_error &e) {
		std::cerr << e.what() << std::endl;	//todo: write custom exception classes. -lsimonis
	}
	catch (...) {
		std::cerr << "Unknown error opening Inventory file -- call support\n";
	}

}

void Inventory::setQuantity(Product&p, int q)
{
	std::fstream fstr;
	int pos,
		quantity;
	std::string token1,
		token2,
		token3,
		token4,
		line,
		delimiter = ",";

	try {	//Open Inventory fstream
		fstr.open(m_file.c_str(), ios::in);
		if (fstr.fail()) throw std::runtime_error("Failed to open Inventory file.");

		while (std::getline(fstr, line, '\n')) {	//get each line in inventory file, tokenize csv
			pos = line.find(delimiter);
			token1 = line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
			pos = line.find(delimiter);
			token2 = line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
			pos = line.find(delimiter);
			token3 = line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
			pos = line.find('\n');
			token4 = line.substr(0, pos);


			if (token1 == std::to_string(p.getUpc())) {
				quantity = q;
				fstr.close();
				this->removeProduct(p);
				this->addProduct(p, q);
			}
		}
		fstr.close();
	}
	catch (std::runtime_error &e) {
		std::cerr << e.what() << std::endl;	//todo: write custom exception classes. -lsimonis
	}
	catch (...) {
		std::cerr << "Unknown error opening Inventory file -- call support\n";
	}

}

int Inventory::checkQuantity(Product & p)
{
	std::fstream fstr;
	int pos,
		quantity = 0;
	std::string token1,
		token2,
		token3,
		token4,
		line,
		delimiter = ",";

	try {	//Open Inventory fstream
		fstr.open(m_file.c_str(), ios::in);
		if (	fstr.fail()) throw std::runtime_error("Failed to open Inventory file.");

		while (std::getline(fstr, line, '\n')) {	//get each line in inventory file, tokenize csv
			pos = line.find(delimiter);
			token1 = line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
			pos = line.find(delimiter);
			token2 = line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
			pos = line.find(delimiter);
			token3 = line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
			pos = line.find('\n');
			token4 = line.substr(0, pos);

			if (token1 == std::to_string(p.getUpc())) {
				quantity = std::stoi(token4);

			}
		}
		fstr.close();
	}
	catch (std::runtime_error &e) {
		std::cerr << e.what() << std::endl;	//todo: write custom exception classes. -lsimonis
	}
	catch (...) {
		std::cerr << "Unknown error opening Inventory file -- call support\n";
	}

	return quantity;
}

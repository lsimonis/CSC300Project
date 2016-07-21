// James Boyer, Chaung Pha, Lukas Simonis
// Group Project - CSC-300, July 2016

#include <iostream>
#include <string>
#include "BusinessInfo.h"
#include "Product.h"
#include "Inventory.h"

using namespace std;

int main() {

	// Set up a test business
	BusinessInfo testBusiness("Test Business", "1234 Easy Street", "San Diego", "CA", 
		"55555", 8.5);

	// Test the printing function
	cout << testBusiness << endl;

	// Test getters
	cout << "Initial Values:" << endl;
	cout << "\tName: " << testBusiness.getName() << endl;
	cout << "\tAddress: " << testBusiness.getAddress() << endl;
	cout << "\tCity: " << testBusiness.getCity() << endl;
	cout << "\tState: " << testBusiness.getState() << endl;
	cout << "\tZip Code: " << testBusiness.getZipCode() << endl;
	cout << "\tSales Tax: " << testBusiness.getSalesTax() << "%" << endl;

	// Test setters
	testBusiness.setName("New Business");
	testBusiness.setAddress("5678 Easy Way");
	testBusiness.setCity("Daytona Beach");
	testBusiness.setState("FL");
	testBusiness.setZipCode("99999-1234");
	testBusiness.setSalesTax(10.5);

	cout << "New Values:" << endl;
	cout << "\tName: " << testBusiness.getName() << endl;
	cout << "\tAddress: " << testBusiness.getAddress() << endl;
	cout << "\tCity: " << testBusiness.getCity() << endl;
	cout << "\tState: " << testBusiness.getState() << endl;
	cout << "\tZip Code: " << testBusiness.getZipCode() << endl;
	cout << "\tSales Tax: " << testBusiness.getSalesTax() << "%" << endl;

	// Set up a test product
	Product product1(12345, "Widget", 1000.00);

	// Test getters
	cout << "Initial Values:" << endl;
	cout << "\tUPC: " << product1.getUpc() << endl;
	cout << "\tName: " << product1.getName() << endl;
	cout << "\tPrice: " << product1.getPrice() << endl;

	// Test setters
	product1.setUpc(67890);
	product1.setName("Tinker");
	product1.setPrice(5000.00);

	cout << "New Values:" << endl;
	cout << "\tUPC: " << product1.getUpc() << endl;
	cout << "\tName: " << product1.getName() << endl;
	cout << "\tPrice: " << product1.getPrice() << endl;



	/* Testing Inventory -lsimonis */


	//inv.createInventory("inventory.txt");

	Product prod1(31415, "Foo", 3.14);
	Product prod2(741776, "Bar", 2.00);

	Inventory inv("inventory.csv");

	inv.addProduct(prod1, 42);
	inv.addProduct(prod2, 2);

	inv.removeProduct(prod1);

	cout << "Press ENTER to exit...";
	cin.get();
	return 0;
}
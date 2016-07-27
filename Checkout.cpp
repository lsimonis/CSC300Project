#include "Checkout.h"
#include "MainMenu.h"
#include "Invoice.h"
#include <iostream>
#include <string>
#include <sstream>

Checkout::Checkout()
{
	m_menu = std::string("Checkout Menu Selection: \n")
		+ "\t1) New Sale\n"
		+ "\t9) Exit Checkout Menu\n\n";
}

Menu * Checkout::selectOption(int o, bool & f)
{
	Menu *nextMenu = 0;
	bool flag = true;

	try {
		switch (o) {
		case 1:
		{

			std::string input;

			BusinessInfo business;
			Inventory inventory("inventory.csv");
			Invoice invoice(business);



			while (flag) {
				std::cin.clear();
				std::cin.sync();
				input.clear();

				int upc = 0, quantity = 1;
				std::cout << "Enter UPC (or <Enter> to complete sale): ";
				std::getline(std::cin, input);

				if (!input.empty()) {
					std::stringstream(input) >> upc;
					input.clear();	

					std::cout << "\nEnter quantity (or <Enter> for 1): ";
					std::getline(std::cin, input);
					if (!input.empty()) {
						std::stringstream(input) >> quantity;
						input.clear();
					}


					LineItem lineitem(*(inventory.getProduct(upc)), quantity);
				}
				else {
					if (!invoice.isEmpty()) {
						invoice.printInvoice();
						invoice.updateInventory();
					}
					flag = false;
				}
			}

			nextMenu = new Checkout;
			break;
		}


		case 9:
		{
			nextMenu = new MainMenu;
			break;
		}
		

		default:
		{
			throw std::invalid_argument("Please enter a valid selection.");
		}
		}
	}
		catch (std::invalid_argument &e) {
			std::cout << e.what() << std::endl;
		}

	return nextMenu;
}


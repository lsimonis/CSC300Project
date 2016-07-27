#include "Checkout.h"
#include "MainMenu.h"
#include "Invoice.h"
#include <iostream>
#include <string>

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
	double cash;

	try {
		switch (o) {
		case 1:
		{

			std::string input;

			BusinessInfo business;
			Inventory inventory("inventory.csv");
			Invoice invoice(business);



			while (flag) {
				int upc = 0, quantity = 1;
				std::cout << "Enter UPC (or 0 to complete sale): ";
				std::cin >> upc;

				if (upc !=0) {
					std::cout << "\nEnter quantity: ";
					std::cin >> quantity;

					Product *product = inventory.getProduct(upc);

					if (product) {
						LineItem lineitem(*product, quantity);
						invoice.addLineItem(lineitem);
					}
					else std::cout << "UPC not found!\n";

				}
				else {
					if (!invoice.isEmpty()) {
						std::cout << "Amount due: " << invoice.calculateTotal();
						
						std::cout << "\nEnter cash paid: ";
						std::cin >> cash;

						std::cout << "Change due: " << invoice.acceptPayment(cash);
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


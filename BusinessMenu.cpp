#include "BusinessMenu.h"
#include "MainMenu.h"
#include "BusinessInfo.h"


#include <iostream>
#include <fstream>


BusinessMenu::BusinessMenu()
{
	m_menu = std::string("Business Information Menu Selection")
	+ "\t1) Edit Name\n"
	+ "\t2) Edit Address\n" 
	+ "\t3) Edit City\n" 
	+ "\t4) Edit State\n" 
	+ "\t5) Edit Zip Code\n" 
	+ "\t6) Edit Sales Tax\n"
	+ "\t9) Exit Menu\n\n";
}

Menu * BusinessMenu::selectOption(int o, bool & f)
{

	std::string tmpString;
	BusinessInfo contactInfo;


	Menu *nextMenu = 0;

	try {
		switch (o)
		{
			// Accepts and save new business name
		case 1:
		{
			system("CLS");
			std::cout << "Edit Name" << std::endl;
			std::cout << "Enter new business name: ";
			std::cin.ignore();
			std::getline(std::cin, tmpString);
			contactInfo.setName(tmpString);
			contactInfo.saveBusinessInfo();

			nextMenu = new BusinessMenu;

			break;
		}

		// Accepts and save new business address
		case 2:
		{
			system("CLS");
			cout << "Enter new business address: ";
			cin.ignore();
			getline(cin, tmpString);
			contactInfo.setAddress(tmpString);
			contactInfo.saveBusinessInfo();

			nextMenu = new BusinessMenu;

			break;
		}

		// Accepts and save new business city
		case 3:
		{
			system("CLS");
			cout << "Edit City" << endl;
			cout << "Enter new business city: ";
			cin.ignore();
			getline(cin, tmpString);
			contactInfo.setCity(tmpString);
			contactInfo.saveBusinessInfo();

			nextMenu = new BusinessMenu;
		}

		// Accepts and save new business state
		case 4:
		{
			system("CLS");
			cout << "Edit State" << endl;
			cout << "Enter new business state: ";
			cin.ignore();
			getline(cin, tmpString);
			contactInfo.setState(tmpString);
			contactInfo.saveBusinessInfo();

			nextMenu = new BusinessMenu;

			break;
		}

		// Accepts and save new business zip code
		case 5:
		{
			system("CLS");
			cout << "Edit Zip Code" << endl;
			cout << "Enter new business zip code: ";
			cin.ignore();
			getline(cin, tmpString);
			contactInfo.setZipCode(tmpString);
			contactInfo.saveBusinessInfo();

			nextMenu = new BusinessMenu;

			break;
		}

		// Accepts and save new business tax
		case 6:
		{
			system("CLS");
			cout << "Edit Sales Tax" << endl;
			cout << "Enter new business sales tax: ";
			cin.ignore();
			getline(cin, tmpString);
			contactInfo.setSalesTax(std::stod(tmpString));
			contactInfo.saveBusinessInfo();

			nextMenu = new BusinessMenu;

			break;
		}

		// Exit Business Information Menu
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
		std::cerr << e.what() << std::endl;
	}

	return nextMenu;  
}

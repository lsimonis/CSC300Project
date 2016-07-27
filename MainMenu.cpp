#include "MainMenu.h"
#include "BusinessMenu.h"
#include "ProductMenu.h"
#include "Checkout.h"

#include <iostream>

MainMenu::MainMenu()
{

	m_menu = std::string("Point of Sale Menu Selection: \n")	
		+ "\t1) Edit Business Information\n"
		+ "\t2) Edit Product\n"
		+ "\t3) Checkout\n"
		+ "\t9) Exit Program\n\n";
}

Menu * MainMenu::selectOption(int o, bool & f)
{

	Menu *nextMenu = 0;

	try{
		switch (o)
		{
		case 1:
		{
			nextMenu = new BusinessMenu;
			break;
		}
		case 2:
		{
			nextMenu = new ProductMenu;
			break;
		}
		case 3:
		{
			nextMenu = new Checkout;
			break;
		}
		case 9:
		{
			f = true;
		}
		default:
		{
			throw std::invalid_argument("Please enter a valid selection.");
		}

	}

	}
	catch (std::invalid_argument &e)
	{
		std::cerr << e.what()<<std::endl;
	}

	return nextMenu;
}


#include "ProductMenu.h"
#include "MainMenu.h"
#include "Inventory.h"
#include "Product.h"

#include <iostream>

ProductMenu::ProductMenu()
{
	m_menu = std::string("Product Menu Selection\n")
		+ "\t1) Add Product\n"
		+ "\t2) View Product List\n"
		+ "\t3) Update Product quantity\n"
		+ "\t4) Check Product Quantity\n"
		+ "\t5) Remove Product\n"
		+ "\t9) Exit Menu\n\n";
}

Menu * ProductMenu::selectOption(int o, bool & f)
{
	Menu *nextMenu = 0;

	Inventory inventory("inventory.csv");

	std::string name;
	int UPC, quantity;
	double price;

	try {
		switch (o) 
		{
		case 1:
		{
			std::cout << "Enter product UPC:    ";
			std::cin >> UPC;

			std::cout << "\nEnter product name:   ";
			std::cin >> name;

			std::cout << "\nEnter product price:  ";
			std::cin >> price;

			std::cout << "\nEnter product quantity:  ";
			std::cin >> quantity;

			Product product(UPC, name, price);

			inventory.addProduct(product, quantity);

			nextMenu = new ProductMenu;
			
			break;
		}

		case 2:
		{
			inventory.printInventory();

			nextMenu = new ProductMenu;

			break;

		}

		case 3:
		{
			std::cout << "Enter product UPC:    ";
			std::cin >> UPC;

			std::cout << "\nEnter product quantity:  ";
			std::cin >> quantity;

			Product *product = inventory.getProduct(UPC);

			inventory.setQuantity(*product, quantity);

			nextMenu = new ProductMenu;

			break;
		}

		case 4:
		{
			std::cout << "Enter product UPC:    ";
			std::cin >> UPC;

			Product product(UPC);
			std::cout<<"Quantity: "<< inventory.checkQuantity(product)<<std::endl;

			nextMenu = new ProductMenu;

			break;
		}

		case 5:
		{
			std::cout << "Enter product UPC:    ";
			std::cin >> UPC;

			Product product(UPC);
			
			inventory.removeProduct(product);

			nextMenu = new ProductMenu;

			break;
		}

		case 9:
		{
			nextMenu = new MainMenu;
			break;
		}

		default:
		{
			throw std::invalid_argument("Please entera valid selection.");
		}

		}
	}
	catch (std::invalid_argument &e) {
		std::cerr << e.what() << std::endl;
	}
	return nextMenu;
}



// James Boyer, Chaung Pha, Lukas Simonis
// Group Project - CSC-300, July 2016

#include <iostream>
#include <string>
#include "BusinessInfo.h"
#include "Product.h"
#include "Inventory.h"
#include "MainMenu.h"

using namespace std;

int main() {

	Menu *menu = new MainMenu;
	bool quit = false;
	int option = 0;

	while (!quit) {
		
		menu->printMenu();
		
		std::cin >> option;
		Menu *nextMenu = menu->selectOption(option, quit);
		

		if (nextMenu) {
			delete menu;
			menu = nextMenu;
		}

	}

	delete menu;

	return 0;
	}
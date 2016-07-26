#include "BusinessMenu.h"
#include "MainMenu.h"

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

Menu * BusinessMenu::getMenu(int o, bool & f)
{
	return nullptr;  //WIP
}



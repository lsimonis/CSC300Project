#ifndef PRODUCTMENU_H
#define PRODUCTMENU_H

#include "MainMenu.h"

/** ProductMenu for updating product info and inventory 
* @version 1.0
*/
class ProductMenu: public Menu
{
public:
	ProductMenu();

	Menu* selectOption(int o, bool& f);
private:

};



#endif // !PRODUCTMENU_H

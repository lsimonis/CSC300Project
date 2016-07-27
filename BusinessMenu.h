#ifndef BUSINESSMENU_H
#define BUSINESSMENU_H

#include "Menu.h"

/** BusinessMenu for entering business information.
* @version 1.0
*/
class BusinessMenu: public Menu
{
public:
	BusinessMenu();
	/** Define pure virtual function.
	*/
	Menu* selectOption(int o, bool& f);

private:

};

#endif // !BUSINESSMENU_H

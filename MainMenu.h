#ifndef MAINMENU_H
#define MAINMENU_H

#include "Menu.h"

/** MainMenu class inherits from Menu.
* @version 1.0
*/
class MainMenu : public Menu
{
public:

	MainMenu();

	/** Define pure virtual function.
	*/
	Menu* getMenu(int o, bool& f);

};
#endif // !MAINMENU_H

#ifndef MENU_H
#define MENU_H

#include <string>

/** Menu Virtual base class for menus.
* @version 1.0
*/
class Menu
{
public:
	Menu();
	virtual ~Menu();

	/** Returns the next menu to go to.
	* @param	o	Option selected.
	* @param	&f	Flag - quit if true.
	* @return	Menu to navigate to next.
	*/
	virtual Menu* selectOption(int o, bool& f) = 0;

	/** Print the menu. 
	*/
	virtual void printMenu();

protected:
	std::string m_menu;

};

#endif //!MENU_H
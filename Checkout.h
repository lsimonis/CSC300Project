#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "Menu.h"

/** Checkout menu for processing sales.
* @version 1.0
*/
class Checkout: public Menu
{
public:
	Checkout();

	/** Define pure virtual
	*/
	Menu* selectOption(int o, bool& f);


private:

};

#endif // !CHECKOUT_H

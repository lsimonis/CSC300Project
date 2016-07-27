#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <fstream>
#include "Product.h"

/** Inventory Class for tracking Products
* @version 1.0
*/
class Inventory
{
public:
	/** Constructor.
	* @param	f	name of inventory file
	*/
	Inventory(std::string f);
	~Inventory();

	/** Add a new Product to the Inventory.
	* @param	&p	Product to add to Inventory
	* @param	q	Initial Quantity
	*/
	void addProduct(Product &p, int q);

	/** Remove Product from Inventory.
	* @param	&p	Product to remove.
	*/
	void removeProduct(Product &p);

	/** Increment or decrement quantity of Product in Inventory.
	* @param	&p	Product to modify Inventory record of.
	* @param	q	Quantity to add or remove from Inventory
	*/
	void updateQuantity(Product &p, int q);

	/** Set quantity of Product in Inventory. 
	* @param	&p	Product to modify Inventory record of.
	* @param	q	Quantity on hand
	*/
	void setQuantity(Product &p, int q);

	/** Check quantity of  Product on hand.
	* @param	&p	Product to be checked
	* @return	Integer quantity of Product in Inventory
	*/
	int checkQuantity(Product &p);

	/** Print out Inventory.
	*/
	void printInventory() const;

	/** Get a Product object based on UPC input.
	* @param	u	UPC
	* @return	*p	Product pointer.
	*/
	Product* getProduct(int u);

private:
	//std::fstream* m_file_ptr; 
	//std::fstream m_fstream;
	std::string m_file;

};

#endif // !INVENTORY_H

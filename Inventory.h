#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <fstream>
#include "Product.h"

/** Inventory Class for tracking Products
* @author Lukas Simonis
* @version1.0
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
	* @param	p	Product to add to Inventory
	* @param	q	Initial Quantity
	*/
	void addProduct(Product &p, int q);

	/** Remove Product from Inventory.
	* @param	u	UPC
	*/
	void removeProduct(Product &p);

	/** Increment or decrement quantity of Product in Inventory.
	* @param	u	UPC of product
	* @param	q	Quantity to add or remove from Inventory
	*/
	void updateQuantity(Product &p, int q);

	/** Set quantity of Product in Inventory. 
	* @param	u	UPC of Product
	* @param	q	Quantity on hand
	*/
	void setQuantity(Product &p, int q);

	/** Check quantity of  Product on hand.
	* @param	p	Product to be checked
	* @return	Integer quantity of Product in Inventory
	*/
	int checkQuantity(Product &p);

private:
	//std::fstream* m_file_ptr; 
	//std::fstream m_fstream;
	std::string m_file;
};

#endif // !INVENTORY_H

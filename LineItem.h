#ifndef LINEITEM_H
#define LINEITEM_H

#include "Product.h"

/** LineItem objects include information about Products and quantities.
* @version 1.0
*/
class LineItem
{
public:
	LineItem(Product p, int q);
	~LineItem();

	/** Get Product object for given LineItem.
	* @return	Product pointer
	*/
	const Product* getProduct() const;

	/** Get quantity for given LineItem.
	* @return	quantity of the item.
	*/
	int getQuantity() const;

private:
	
	Product m_product;
	int m_quantity;
	double m_price;

};

#endif // !LINEITEM_H

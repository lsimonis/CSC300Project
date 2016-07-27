#include "LineItem.h"

LineItem::LineItem(Product p, int q):m_product(p), m_quantity(q)
{
}

LineItem::~LineItem()
{
}

const Product * LineItem::getProduct() const
{
	const Product *prod_ptr = &m_product;
	return  prod_ptr;
}

int LineItem::getQuantity() const
{
	return m_quantity;
}

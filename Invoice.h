#ifndef INVOICE_H
#define INVOICE_H

#include <vector>
#include "BusinessInfo.h"
#include "LineItem.h"
#include "Inventory.h"

/** Invoice objects contain information about a sale.
* @version 1.0
*/
class Invoice
{
public:
	Invoice(BusinessInfo b);
	~Invoice();

	/** Method to add a line item to the invoice.
	* @param	l	LineItem object.
	*/
	void addLineItem(LineItem l);

	/**Print Invoice.
	*/
	void printInvoice();

	/** Update Inventory.
	*/
	void updateInventory() const;

	/** Check if there are any line items yet.
	*/
	bool isEmpty() const;

	/** Take cash payment and calculate change.
	* @param	c	Amount of cash paid.
	* @return	Change amount.
	*/
	double acceptPayment(double c);

	/** Calculate Total.
	* @return total
	*/
	double calculateTotal() const;

private:
	vector<LineItem> m_lineItems;
	BusinessInfo m_business;
	double m_payment, m_change;

		/** Calculate Subtotal.
		* @return subtotal.
		*/
		double calculateSubtotal() const;

		/** Calculate Sales Tax.
		* @return sales tax.
		*/
		double calculateSalestax()	const;
};

#endif // !INVOICE_H

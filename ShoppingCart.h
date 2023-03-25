#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <vector>
#include <string>
#include "ItemToPurchase.h"

using namespace std;

// Create class ShoppingCart
class ShoppingCart {
	// Declare public methods
public:
	ShoppingCart();
	ShoppingCart(string name, string date);
	string GetCustomerName() const;
	string GetDate() const;
	void AddItem(ItemToPurchase&);
	void RemoveItem(string itemName);
	void ModifyItem(ItemToPurchase);
	int GetNumItemsInCart();
	int GetCostOfCart();
	void PrintTotal();
	void PrintDescriptions();

private:
	string customerName;
	string currentDate;
	vector <ItemToPurchase> cartItems;
};

#endif

#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

// Create class ItemToPurchase
class ItemToPurchase {
	// Declare public methods
public:
	ItemToPurchase();
	ItemToPurchase(string name, string description, int price, int quantity);
	void SetName(string itemName);
	string GetName() const;
	void SetPrice(int itemPrice);
	int GetPrice() const;
	void SetQuantity(int itemQuantity);
	int GetQuantity() const;
	void SetDescription(string itemDescription);
	string GetDescription() const;
	void PrintItemCost();
	void PrintItemDescription();

	ItemToPurchase operator+(const ItemToPurchase& item);
	// Declare the private varibles being used
private:
	string itemName;
	string itemDescription;
	int itemPrice;
	int itemQuantity;
};

#endif
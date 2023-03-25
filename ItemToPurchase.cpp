#include <iostream>
using namespace std;

// Add the header file where methods were declared
#include "ItemToPurchase.h"

// Default contructor to initialize object
ItemToPurchase::ItemToPurchase() {
	itemName = "none";
	itemDescription = "none";
	itemPrice = 0;
	itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity) {
	itemName = name;
	itemDescription = description;
	itemPrice = price;
	itemQuantity = quantity;
}

// Sets the name 
void ItemToPurchase::SetName(string itemName) {
	this->itemName = itemName;
}

// Gets the name 
string ItemToPurchase::GetName() const {
	return itemName;
}

// Sets the Price
void ItemToPurchase::SetPrice(int itemPrice) {
	this->itemPrice = itemPrice;
}

// Gets the price
int ItemToPurchase::GetPrice() const {
	return itemPrice;
}

// Sets the Quantity
void ItemToPurchase::SetQuantity(int itemQuantity) {
	this->itemQuantity = itemQuantity;
}

// Gets the Quantity
int ItemToPurchase::GetQuantity() const {
	return itemQuantity;
}

// Sets description
void ItemToPurchase::SetDescription(string itemDescription) {
	this->itemDescription = itemDescription;
}

// Gets description
string ItemToPurchase::GetDescription() const {
	return itemDescription;
}

// Prints Item cost
void ItemToPurchase::PrintItemCost() {
	cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" <<
		itemQuantity * itemPrice << endl;
}

// Prints item description
void ItemToPurchase::PrintItemDescription() {
	cout << itemName << ": " << itemDescription << endl;
}

// + operator that will add the prices of two items together and return on object with that price
ItemToPurchase ItemToPurchase::operator+(const ItemToPurchase& item) {
	ItemToPurchase totPrice;

	totPrice.itemPrice = (this->itemPrice * this->itemQuantity) + (item.itemPrice * item.itemQuantity);

	return totPrice;
}
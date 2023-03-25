#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Add the header file where methods were declared
#include "ShoppingCart.h"

// Default contructor to initialize object
ShoppingCart::ShoppingCart() {
	customerName = "none";
	currentDate = "January 1, 2016";
}

// Cnstructor when given date and name
ShoppingCart::ShoppingCart(string name, string date) {
	customerName = name;
	currentDate = date;
}

// Gets customers name
string ShoppingCart::GetCustomerName() const {
	return customerName;
}

// Gets the date
string ShoppingCart::GetDate() const {
	return currentDate;
}

// Adds and item to cart
void ShoppingCart::AddItem(ItemToPurchase& newItem) {
	
	string userItem;
	string userDescription;
	int userPrice;
	int userQuantity;

	cout << "Enter the item name:" << endl;
	getline(cin, userItem);
	newItem.SetName(userItem);

	cout << "Enter the item description:" << endl;
	getline(cin, userDescription);
	newItem.SetDescription(userDescription);

	cout << "Enter the item price:" << endl;
	cin >> userPrice;
	newItem.SetPrice(userPrice);

	cout << "Enter the item quantity:" << endl;
	cin >> userQuantity;
	newItem.SetQuantity(userQuantity);

	cartItems.push_back(newItem);
}

// Removes an item when given name (if exists)
void ShoppingCart::RemoveItem(string itemName) {
	bool removed = false;
	for (std::vector<ItemToPurchase>::size_type i = 0; i < cartItems.size(); i++) {
		if (cartItems[i].GetName() == itemName) {
			removed = true;
			cartItems.erase(cartItems.begin() + i);
		}
	}
	if (removed == false) {
		cout << "Item not found in cart. Nothing removed." << endl;
	}
}


// Modify an items description, price, or quantity
void ShoppingCart::ModifyItem(ItemToPurchase modItem) {
	bool foundItem = false;
	// Searches list to see if the name exists
	for (std::vector<ItemToPurchase>::size_type i = 0; i < cartItems.size(); i++) {
		if (cartItems[i].GetName() == modItem.GetName()) {
			// check to make sure item doesnt have default values
				// changes the exisiting information to the new modified info
			cartItems[i].SetQuantity(modItem.GetQuantity());
			foundItem = true;
			break;
		}
	}
	if (foundItem == false) {
		cout << "Item not found in cart. Nothing modified." << endl;
	}
}

// calculates and return total number of items in the cart
int ShoppingCart::GetNumItemsInCart() {
	int sumItemsInCart = 0;
	for (std::vector<ItemToPurchase>::size_type i = 0; i < cartItems.size(); i++) {
		if (cartItems[i].GetQuantity() > 0) {
			sumItemsInCart += cartItems[i].GetQuantity();
		}
	
	}
	return sumItemsInCart;
}

// calculates and returns total number of item in the cart
int ShoppingCart::GetCostOfCart() {
	int costOfCartTotal = 0;
	int quantity;  
	int price; 
	for (int i = 0; i < cartItems.size(); i++) {
		quantity = cartItems[i].GetQuantity();
		price = cartItems[i].GetPrice();
		if (quantity > 0) {
			costOfCartTotal += price * quantity;
		}
	}
	return costOfCartTotal;
}


// Prints the total of all aspects of the cart
void ShoppingCart::PrintTotal() {
	cout << customerName << "'s Shopping Cart - " << currentDate << endl;
	cout << "Number of Items: " << GetNumItemsInCart() << endl;
	cout << endl;
	if (cartItems.size() > 0) {
		for (std::vector<ItemToPurchase>::size_type i = 0; i < cartItems.size(); i++) {
			cartItems[i].PrintItemCost();
		}
	}
	else {
		cout << "SHOPPING CART IS EMPTY" << endl;
	}
	cout << endl;
	cout << "Total: $" << GetCostOfCart() << endl;
}


// Prints the description of all items
void ShoppingCart::PrintDescriptions() {
	cout << customerName << "'s Shopping Cart - " << currentDate << endl;
	cout << endl;
	cout << "Item Descriptions" << endl;
	if (cartItems.size() > 0) {
		for (std::vector<ItemToPurchase>::size_type i = 0; i < cartItems.size(); i++) {
			cartItems[i].PrintItemDescription();
		}
	}
	else {
		cout << "SHOPPING CART IS EMPTY" << endl;
	}
}
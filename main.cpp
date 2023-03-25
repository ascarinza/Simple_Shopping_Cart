#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu() {
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
}

void ExecuteMenu(char choice, ShoppingCart& userCart) {
    string userInput;
    switch (choice) {
    case 'o':
    {
        cout << "OUTPUT SHOPPING CART" << endl;
        userCart.PrintTotal();
        break;
    }
    case 'i':
    {
        cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
        userCart.PrintDescriptions();
        break;
    }
    case 'a':
    {
        ItemToPurchase newItem;
        cout << "ADD ITEM TO CART" << endl;
        userCart.AddItem(newItem);
        break;
    }
    case 'd':
    {
        cout << "REMOVE ITEM FROM CART" << endl;
        cout << "Enter name of item to remove:" << endl;
        getline(cin, userInput);
        userCart.RemoveItem(userInput);
        break;
    }
    case 'c':
    {
        ItemToPurchase modifiedItem;
        int newQuant;
        cout << "CHANGE ITEM QUANTITY" << endl;
        cout << "Enter the item name:" << endl;
        getline(cin, userInput);
        modifiedItem.SetName(userInput);
        cout << "Enter the new quantity:" << endl;
        cin >> newQuant;
        modifiedItem.SetQuantity(newQuant);
        userCart.ModifyItem(modifiedItem);
    }

    }
}


int main() {
    string customerName;
    string currentDate;
    char userChoice = 'r';

    // Get date and name and create a new shopping cart object with input 
    cout << "Enter customer's name:" << endl;
    getline(cin, customerName);
    cout << "Enter today's date:" << endl;
    getline(cin, currentDate);
    cout << endl;
    cout << "Customer name: " << customerName << endl;
    cout << "Today's date: " << currentDate << endl;

    ShoppingCart userCart(customerName, currentDate);

    while (userChoice != 'q') {
        cout << endl;
        PrintMenu();
        cout << "Choose an option:" << endl;
        cin >> userChoice;
        cin.ignore();

        while ((userChoice != 'a') && (userChoice != 'd') && (userChoice != 'c') &&
            (userChoice != 'o') && (userChoice != 'q') && userChoice != 'i') {
            cout << "Choose an option:" << endl;
            cin >> userChoice;
            cin.ignore();
            if (userChoice == 'q') {
                break;
            }
        }
        
        ExecuteMenu(userChoice, userCart);
    }
    return 0;
}
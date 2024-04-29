#include <iostream>
#include <string>
#include "ItemToPurchase.h"
using namespace std;

//Default Constructor
ItemtoPurchase::ItemToPurchase() : itemName("none"), itemDescription("none"), itemDescription("none"), 
    itemPrice(0), itemQuantity(0) {}

ItemtoPurchase::ItemToPurchase(string  name, string description, int price, int quantity) : itemName(name), 
    itemDescription(description), itemPrice(price), itemQuantity(quantity) {}

// Sets item name
void ItemToPurchase::SetName(string name) {
    itemName = name;
}

// Returns item name
string ItemtoPurchase::GetName() const {
    return itemName;
}

//Sets item description
void ItemToPurchase::SetDescription(string description) {
    itemDescription = description;
}

// Returns item description
string ItemtoPurchase::GetDescription() const {
    return itemDescription;
}

// Sets item price
void ItemToPurchase::SetPrice(int price) {
    itemPrice = price;
}

// Returns item price
int ItemtoPurchase::GetPrice() const {
    return itemPrice;
}

// Sets item quantity
void ItemToPurchase::SetQuantity(int quantity) {
    itemQuantity = quantity;
}

// Returns item quantity
int ItemtoPurchase::GetQuantity() const {
    return itemQuantity;
}

// Print cost
void ItemToPurchase::PrintItemCost() const {
    cout << itemName << "" << itemQuantity << " @ $" << itemPrice << " = $" << itemQuantity * itemPrice << endl;
}

// Print description
void ItemtoPurchase::PrintItemDescription() const {
    cout << itemName << ": " << itemDescription << endl;
}
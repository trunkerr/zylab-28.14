#include <iostream>
#include <string>
#include <vector>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"
using namespace std;

// Default constructor 
ShoppingCart::ShoppingCart() : customerName("none"), currentDate("January 1, 2016") {}

// Constructor with customer name and current date
ShoppingCart::ShoppingCart(string customerName, string currentDate)
    : customerName(customerName), currentDate(currentDate) {}

// Returns the customer's name
string ShoppingCart::GetCustomerName() const {
    return customerName;
}

// Returns the current date
string ShoppingCart::GetDate() const {
    return currentDate;
}

// Adds an item to the shopping cart
void ShoppingCart::AddItem(ItemToPurchase item) {
    cartItems.push_back(item);
}

// Removes an item from the cart by name
void ShoppingCart::RemoveItem(string itemName) {
    bool found = false;
    for (int i = 0; i < cartItems.size(); i++) {
        if (cartItems[i].GetName() == itemName) {
            cartItems.erase(cartItems.begin() + i);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

// Modifies an item in the cart
void ShoppingCart::ModifyItem(ItemToPurchase item) {
    bool found = false;
    for (auto& cartItem : cartItems) {
        if (cartItem.GetName() == item.GetName()) {
            if (item.GetDescription() != "none" || item.GetPrice() != 0 || item.GetQuantity() != 0) {
                if (item.GetDescription() != "none") {
                    cartItem.SetDescription(item.GetDescription());
                }
                if (item.GetPrice() != 0) {
                    cartItem.SetPrice(item.GetPrice());
                }
                if (item.GetQuantity() != 0) {
                    cartItem.SetQuantity(item.GetQuantity());
                }
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}

// Returns the total items in the cart
int ShoppingCart::GetNumItemsInCart() const {
    int totalQuantity = 0;
    for (const auto& item : cartItems) {
        totalQuantity += item.GetQuantity();
    }
    return totalQuantity;
}

// Returns the total cost of the items in the cart
int ShoppingCart::GetCostOfCart() const {
    int totalCost = 0;
    for (const auto& item : cartItems) {
        totalCost += item.GetPrice() * item.GetQuantity();
    }
    return totalCost;
}
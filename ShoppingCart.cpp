#include "ShoppingCart.h"
#include <iostream>


ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
}


ShoppingCart::ShoppingCart(string name, string date) {
    customerName = name;
    currentDate = date;
}


string ShoppingCart::GetCustomerName() const {
    return customerName;
}


string ShoppingCart::GetDate() const {
    return currentDate;
}


void ShoppingCart::AddItem(ItemToPurchase item) {
    cartItems.push_back(item);
}


void ShoppingCart::RemoveItem(string name) {
    bool found = false;
    for (unsigned int i = 0; i < cartItems.size(); ++i) {
        if (cartItems[i].GetName() == name) {
            cartItems.erase(cartItems.begin() + i);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}


void ShoppingCart::ModifyItem(ItemToPurchase item) {
    bool found = false;
    for (unsigned int i = 0; i < cartItems.size(); ++i) {
        if (cartItems[i].GetName() == item.GetName()) {
            if (!item.GetDescription().empty()) {
                cartItems[i].SetDescription(item.GetDescription());
            }
            if (item.GetPrice() != 0) {
                cartItems[i].SetPrice(item.GetPrice());
            }
            if (item.GetQuantity() != 0) {
                cartItems[i].SetQuantity(item.GetQuantity());
            }
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}


int ShoppingCart::GetNumItemsInCart() {
    int numItems = 0;
    for (unsigned int i = 0; i < cartItems.size(); ++i) {
        numItems += cartItems[i].GetQuantity();
    }
    return numItems;
}


double ShoppingCart::GetCostOfCart() {
    double totalCost = 0;
    for (unsigned int i = 0; i < cartItems.size(); ++i) {
        totalCost += cartItems[i].GetPrice() * cartItems[i].GetQuantity();
    }
    return totalCost;
}


void ShoppingCart::PrintTotal() {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;

    if (cartItems.empty()) {
        cout << "SHOPPING CART IS EMPTY" << endl;
        cout << "\n";
        cout << "Total: $0\n";
        return;
    }

    for (unsigned int i = 0; i < cartItems.size(); ++i) {
        cartItems[i].PrintItemCost();
    }

    cout << endl << "Total: $" << GetCostOfCart() <<endl;
}


void ShoppingCart::PrintDescriptions() {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;
    cout << "Item Descriptions" << endl;

    if (cartItems.empty()) {
        cout << "SHOPPING CART IS EMPTY" << endl;
        return;
    }

    for (unsigned int i = 0; i < cartItems.size(); ++i) {
        cartItems[i].PrintItemDescription();
    }
}

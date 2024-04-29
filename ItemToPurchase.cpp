#include <iostream>
#include <string>
#include "ItemToPurchase.h"
using namespace std;

//Default Constructor
ItemtoPurchase::ItemToPurchase() : itemName("none"), itemDescription("none"), itemDescription("none"), itemPrice(0), itemQuantity(0) {}

ItemtoPurchase::ItemToPurchase(string  name, string description, int price, int quantity) : itemName(name)

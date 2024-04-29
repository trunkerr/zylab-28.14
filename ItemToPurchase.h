#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H


#include <string>
using namespace std;

class ItemToPurchase {
   
   public:
      ItemToPurchase();
      ItemToPurchase(string name, string description, int price = 0, int quantity = 0);
      void SetName(string name);
      string GetName() const;
      void SetDescription(string description);
      string GetDescription() const;
      void SetPrice(int price);
      int GetPrice() const;
      void SetQuantity(int quantity);
      int GetQuantity() const;
      void PrintItemCost();
      void PrintItemDescription();
   
   private:
      string itemName;
      string itemDescription;
      int itemPrice;
      int itemQuantity;
};


#endif

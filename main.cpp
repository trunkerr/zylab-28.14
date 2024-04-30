#include <iostream>

#include "ShoppingCart.h"
#include "ItemToPurchase.h"


void PrintMenu(){
         cout << "\nMENU\n"
         << "a - Add item to cart\n"

         << "d - Remove item from cart\n"

         << "c - Change item quantity\n"

         << "i - Output items' descriptions\n"

         << "o - Output shopping cart\n"

         << "q - Quit\n"
         <<"\n";
             
}


void ExecuteMenu(char choice, ShoppingCart &cart){
   switch (choice) {

        case 'a': {
           cout << "ADD ITEM TO CART"<< endl;

            string name, description;

            int price, quantity;

            cout << "Enter the item name:"<<endl;

            cin.ignore();

            getline(cin, name);

            cout << "Enter the item description:"<<endl;

            getline(cin, description);

            cout << "Enter the item price:"<<endl;

            cin >> price;

            cout << "Enter the item quantity:"<<endl;

            cin >> quantity;

            

            ItemToPurchase item(name, description, price, quantity);

            cart.AddItem(item);
            PrintMenu();

            break;

        }
        case 'd': {
           cout << "REMOVE ITEM FROM CART"<< endl;

            string name;

            cout << "Enter name of item to remove:"<<endl;

            cin.ignore();

            getline(cin, name);

            cart.RemoveItem(name);
            PrintMenu();

            break;

        }

        case 'c': {
           
           cout << "CHANGE ITEM QUANTITY"<< endl;

            string name;

            int quantity;

            cout << "Enter the item name:"<<endl;

            cin.ignore();

            getline(cin, name);

            cout << "Enter the new quantity:"<<endl;

            cin >> quantity;

            

            ItemToPurchase item;

            item.SetName(name);

            item.SetQuantity(quantity);

            cart.ModifyItem(item);
            PrintMenu();

            break;

        }

        case 'i': {
           
           cout << "OUTPUT ITEMS' DESCRIPTIONS"<< endl;

            cart.PrintDescriptions();
            PrintMenu();

            break;

        }

        case 'o': {
            cout << "OUTPUT SHOPPING CART"<< endl;

            cart.PrintTotal();
            PrintMenu();

            break;

        }

        case 'q': {

            break;

        }

        default: {

            cout << "Invalid option. Please try again." << endl;

            break;

        }

    }

}
   


int main() {

    string customerName;

    string currentDate;

    

    cout << "Enter customer's name:\n";

    getline(cin, customerName);

    

    cout << "Enter today's date:\n";

    getline(cin, currentDate);

    

    cout << "\nCustomer name: " << customerName << endl;
    

    cout << "Today's date: " << currentDate << endl;
    

    

    ShoppingCart cart(customerName, currentDate);

     PrintMenu();

    char choice = '\0';
   
    do {
       
        cout << "Choose an option:\n";
        cin >> choice;

        switch (choice) {
            case 'a':
            case 'd':
            case 'c':
            case 'i':
            case 'o':
            case 'q':
                ExecuteMenu(choice, cart);
                break;
            default:
                cin.clear();
        }
    } while (choice != 'q');

    return 0;
}

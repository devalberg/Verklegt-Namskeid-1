#include "Admin_Menu_Pizza.h"

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <conio.h>

#include "BottomService.h"
#include "ToppingService.h"
#include "SizeService.h"

using namespace std;

Admin_Menu_Pizza::Admin_Menu_Pizza()
{
    //ctor
}

void Admin_Menu_Pizza::run()
{
    bool cont = true;
    while (cont)
    {
        system("CLS");
        cout << "======================================" << endl;
        cout << "            Manage Pizzas" << endl;
        cout << "======================================" << endl << endl;

        vector<Pizza> items = _service.view_items();
        cout << "List of all pizzas in the database:" << endl;
        for (unsigned int i = 0 ; i < items.size(); i++)
        {
            cout << "Name: " << left << setw(32) << items[i].get_name() << "Shortcut: [" << items[i].get_identity() << "]\tPrice: " << items[i].get_price();
            cout << endl;
        }
        cout << endl;


        cout << "Commands:" << endl;
        cout << "\t1. Add new item" << endl;
        cout << "\t2. Delete a item" << endl;

        cout << "Type in your command or type 'back' to go back to previous menu" << endl;

        cont = get_command();
    }

}

bool Admin_Menu_Pizza::get_command()
{
    while (true)
    {
        string input;
        cin >> input;

        if (input == "1")
        {
            add_item();
            break;
        }
        else if (input == "2")
        {
            delete_item();
            break;
        }
        else if (input == "back")
        {
            return false;
        }
        else
        {
            cout << "Invalid input, please try again" << endl;
        }
    }

    return true;
}

void Admin_Menu_Pizza::add_item()
{
    BottomService b;
    SizeService s;
    ToppingService t;

    string name;
    char identity;
    Size _size;
    Bottom bottom;
    vector<Topping> toppings;
    bool crust = false;
    int price;

    char tempChar;

    bool cont = true;
    while (cont)
    {
        cout << "Creating a new pizza for the menu, type '\\' anywhere to cancel" << endl;

        vector<Size> sizes = s.view_items();
        vector<Bottom> bottoms = b.view_items();
        vector<Topping> tops = t.view_items();

        cout << "Choose the name: ";
        cin.ignore();
        getline(cin, name);
        if (check_for_cancel(name)) break;

        cout << "Choose shortcut: ";
        cin >> identity;
        if (check_for_cancel(identity)) break;

        cout << "\nChoose the toppings: (type '0' to stop adding toppings)" << endl;

        for (unsigned int i = 0 ; i < tops.size() ; i++)
        {
            cout << setw(2) << tops[i].get_identity() <<": " << left << setw(10) << tops[i] << "Price: " << tops[i].get_price() << endl;
        }

        Topping tempTop;

        do
        {
            cin >> tempChar;
            if (check_for_cancel(tempChar)) break;
            tempTop.set_identity(tempChar);
            toppings.push_back(tempTop);
        }
        while (tempChar != '0');

        cout << "Cheesy crust? ('y'): ";
        char temp;
        cin >> temp;
        if (temp == 'y')
        {
            crust = true;
        }


        cout << "\nSet the price:" << endl;
        cin >> price;

        try
        {
            _service.add_item(_service.finalize_pizza_admin(name, identity, _size, bottom, toppings, crust, price));
            cout << "Pizza successfully added!" << endl;

        }
        catch (InvalidItemIdExceptions e)
        {
            cout << e.get_error() << endl;
        }
        catch (InvalidItemPriceException e)
        {
            cout << e.get_error() << endl;
        }
        catch (InvalidItemNameException e)
        {
            cout << e.get_error() << endl;
        }
        system("pause");
        system("CLS");
        break;
    }
}

void Admin_Menu_Pizza::delete_item()
{
    string item_to_delete;
    string confirm;
    cout << "Deleting a bottom:" << endl;
    cout << "Type in the item you would like to delete (type '\\' anywhere to cancel)" << endl;
    cin.ignore();
    getline(cin, item_to_delete);

    cout << "Are you sure you would like to delete the item: " << item_to_delete << "(type 'yes' to confirm)" << endl;
    cin >> confirm;

    if (confirm == "yes")
    {
        try
        {
            _service.delete_item(item_to_delete);
            cout << "Item deleted successfully" << endl;
            system("pause");
            system("cls");
        }
        catch(InvalidItemNameException e)
        {
            e.get_error();
        }
    }
}




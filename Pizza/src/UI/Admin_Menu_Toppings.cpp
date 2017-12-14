#include "Admin_Menu_Toppings.h"

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

Admin_Menu_Toppings::Admin_Menu_Toppings()
{
    //ctor
}

void Admin_Menu_Toppings::run()
{
    bool cont = true;
    while (cont)
    {
        system("CLS");
        cout << "======================================" << endl;
        cout << "            Manage toppings" << endl;
        cout << "======================================" << endl << endl;


        vector<Topping> toppings = _service.view_items();
        if (!toppings.size())
        {
            cout << "There are no toppings in the database, add one!" << endl;
        }
        cout << "List of all toppings in the database" << endl;
        for (unsigned int i = 0 ; i < toppings.size(); i++)
        {
            cout << left << "\tTopping name: " << setw(22) << toppings[i].get_name()  << "Shortcut: " << setw(5)  <<
                 toppings[i].get_identity() << "Vegan: " << setw(10);

            if (toppings[i].get_is_vegan())
            {
                cout << "Yes";
            }
            else
            {
                cout << "No";
            }

            cout << "Price: " << toppings[i].get_price() << "Kr." << endl;
        }

        cout << "Commands:" << endl;
        cout << "\t1. Add new topping" << endl;
        cout << "\t2. Delete a topping" << endl;

        cout << "Type in your command or type 'back' to go back to previous menu" << endl;

        cont = get_command();
    }

}

bool Admin_Menu_Toppings::get_command()
{
START:
    string input;
    cin >> input;

    if (input == "1")
    {
        add_item();
    }
    else if (input == "2")
    {
        delete_item();
    }
    else if (input == "back")
    {
        return false;
    }
    else
    {
        cout << "Invalid input, please try again" << endl;
        goto START;
    }

    return true;
}

void Admin_Menu_Toppings::add_item()
{
    bool cont = true;
    while (cont)
    {
        string name;
        char identity;
        int price;
        bool is_vegan;
        cout << "Adding Topping (Type '\\' any where to cancel)"  << endl;

        while(true)
        {
            cout << "Name of bottom: ";
            cin.ignore();
            getline(cin, name);
            if (check_for_cancel(name)) break;

            cout << "Shortcut: ";
            cin >> identity;
            if (check_for_cancel(identity)) break;

            cout << "Price: ";
            cin >> price;
            if (check_for_cancel(incase_fail(price))) break;

            cout << "Is vegan? ('y' for yes): ";
            char temp;
            cin >> temp;
            if (check_for_cancel(incase_fail(temp))) break;
            if (temp == 'y')
            {
                is_vegan = true;
            }

            try
            {
                _service.add_item(Topping(name, identity, price, is_vegan));
                cout << "Topping has been added!" << endl;
                break;
            }
            catch (InvalidItemIdExceptions e)
            {
                cout << e.get_error() << endl;
            }
            catch (InvalidItemNameException e)
            {
                cout << e.get_error() << endl;
            }
            catch (InvalidItemPriceException e)
            {
                cout << e.get_error() << endl;
            }
        }

        char input;
        cout << "Would you like to add another item? (type 'y' for yes)" << endl;
        cin >> input;
        if (input == 'y')
        {
            cont = true;
        }
        else
        {
            system("CLS");
            cont = false;
        }
    }
}

void Admin_Menu_Toppings::delete_item()
{
    bool cont = true;
    while (cont)
    {
        string item_to_delete;
        string confirm;
        cout << "Deleting a bottom (type '\\' any where to cancel):" << endl;

        while(true)
        {
            cout << "Type in the item you would like to delete" << endl;
            cin.ignore();
            getline(cin, item_to_delete);
            if (check_for_cancel(item_to_delete)) break;

            cout << "Are you sure you would like to delete the item: " << item_to_delete << "? (type 'yes' to confirm)" << endl;
            cin >> confirm;

            if (confirm == "yes")
            {
                try
                {
                    _service.delete_item(item_to_delete);
                    cout << "Item deleted successfully" << endl;
                    break;
                }
                catch(InvalidItemNameException e)
                {
                    cout << e.get_error() << endl;
                }
            }
            else
            {
                cout << "Item has not been deleted" << endl;
                break;
            }
        }

        char input;
        while (true)
        {
            cout << "\nDelete another item? ('y'): ";
            cin >> input;
            if (input == 'y')
            {
                cont = true;
                break;
            }
            else
            {
                cont = false;
                break;
            }
        }
    }

}

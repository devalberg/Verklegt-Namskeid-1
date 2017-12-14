#include "Sales_Create_Order.h"
#include "LocationService.h"
#include <cstdlib>
Sales_Create_Order::Sales_Create_Order()
{
    this->customer_name = "\0";
    this->customer_phone = "\0";
    this->comment = "\0";
}

void Sales_Create_Order::run()
{
    while (true)
    {
        system("cls");
        print_order();

        cout << "Creating order" << endl << endl;

        cout << "1. Add Pizza from Menu" << endl;
        cout << "2. Add Custom pizza" << endl;
        cout << "3. Add Sides" << endl;
        cout << "4. Add Drinks\n" << endl;

        cout << "5. Customer name" << endl;
        cout << "6. Customer phone" << endl;
        cout << "7. Pickup location" << endl;
        cout << "8. Comment\n" << endl;

        cout << "9. Delete an item\n" << endl;
        cout << "0. Complete order" << endl;
        get_input();

    }
}

void Sales_Create_Order::print_order()
{
   //if (customer_name != "\0")
    {
        cout << "Customer name: " << this->customer_name << endl;
    }
    //if (customer_phone != "\0")
    //{
        cout << "Customer phone: " << this->customer_phone << endl;
    //}

    Location l;
    //if (location.get_name() != l.get_name())
    {
        cout << "Location: " << this->location.get_name() << endl;
    }

    if (pizzas.size())
    {
        cout << "Pizzas:" << endl;

        for (unsigned int i = 0 ; i < pizzas.size() ; i++)
        {
            cout << "\t" << pizzas[i].get_name() << "\tKr." << pizzas[i].get_price() << endl;
            cout << "\t  Contains: ";

            for (unsigned int j = 0 ; j < pizzas[i].get_toppings().size() ; j++)
            {
                cout << pizzas[i].get_toppings()[j].get_counter() << " " << pizzas[i].get_toppings()[j].get_name();
                if (pizzas[i].get_toppings()[j+1].get_name() != "\0")
                    cout << ", ";
                else break;
            }
            cout << endl;
        }
        cout << endl;
    }

    if (sides.size())
    {
        cout << "Sides: " << endl;

        for (unsigned int i = 0 ; i < sides.size() ; i++)
        {
            cout << "\t" << sides[i].get_name() << "\t" << sides[i].get_price() << endl;
        }

        cout << endl;
    }

    if (drinks.size())
    {
        cout << "Drinks: " << endl;

        for (unsigned int i = 0 ; i < drinks.size() ; i++)
        {
            cout << "\t" << drinks[i].get_name() << "\t" << drinks[i].get_price() << endl;
        }

        cout << endl;
    }

    if (comment != "\0")
    {
        cout << "Comment: " << this->comment << endl;
    }
    cout << endl;
}


void Sales_Create_Order::get_input()
{
    char input;
    cin >> input;

    vector<Drink> tempDrinks;
    vector<Side> tempSides;

    if (input == '1')
    {
        system("cls");
        Sales_Menu_Pizza p;
        pizzas.push_back(p.run());
    }
    else if (input == '2')
    {
        system("cls");
        Sales_Menu_Custom_Pizza cp;
        pizzas.push_back(cp.run());

    }
    else if (input == '3')
    {
        system("cls");
        Sales_Menu_Sides s;
        tempSides = s.run();

        for (unsigned int i = 0 ; i < tempSides.size() ; i++)
        {
            sides.push_back(tempSides[i]);
        }

    }
    else if (input == '4')
    {
        system("cls");
        Sales_Menu_Drinks d;
        tempDrinks = d.run();

        for (unsigned int i = 0 ; i < tempDrinks.size() ; i++)
        {
            drinks.push_back(tempDrinks[i]);
        }

    }
    else if (input == '5')
    {
        system("cls");
        cout << "Customer name: ";
        cin.ignore();
        getline(cin, customer_name);
    }
    else if (input == '6')
    {
        system("cls");
        cout << "Customer phone: ";
        cin.ignore();
        getline(cin, customer_phone);
    }
    else if (input == '7')
    {
        choose_location();
    }
    else if (input == '8')
    {
        system("cls");
        cout << "Comment: ";
        cin.ignore();
        getline(cin, comment);
    }
    else if (input == '9')
    {
        system("cls");
        delete_items();
    }
    else if (input == '0')
    {
        if (customer_name != "\0" && customer_phone != "\0" && location.get_name() != "\0")
        {
            system("cls");
            Order order(pizzas, sides, drinks, customer_name, customer_phone, comment, location, delivery, paid);
            _service.create_order(order);
        }
        else if(customer_name == "\0")
        {
            cout << "Remember to fill in name" << endl;
            system("pause");
        }
        else if(customer_phone == "\0")
        {
            cout << "Remember to fill in phone number" << endl;
            system("pause");
        }
        else if(location.get_name() == "\0")
        {
            cout << "Remember to fill in location" << endl;
            system("pause");
        }
        else
        {
            cout << "You done fucked up" << endl;
            system("pause");
        }

    }
}

void Sales_Create_Order::delete_items()
{
    cout << "What would you like to delete?" << endl;

    cout << "1. A pizza" << endl;
    cout << "2. A Side" << endl;
    cout << "3. A Drink" << endl;

    char choice;
    cin >> choice;
    if (choice == '1')
    {
        delete_pizza();
    } else if (choice == '2')
    {
        delete_side();
    } else if (choice == '3')
    {
        delete_drink();
    }
}

void Sales_Create_Order::delete_pizza()
{
    cout << "Choose the number you would like to delete: " << endl;

    for (unsigned int i = 0 ; i < pizzas.size() ; i++)
    {
        cout << "\t" << i+1 << ". " << pizzas[i].get_name() << endl;
    }

    int index;
    cin >> index;

    pizzas.erase(pizzas.begin()+index-1);
}

void Sales_Create_Order::delete_side()
{
    cout << "Choose the number you would like to delete: " << endl;

    for (unsigned int i = 0 ; i < sides.size() ; i++)
    {
        cout << "\t" << i+1 << ". " << sides[i].get_name() << endl;
    }

    int index;
    cin >> index;

    sides.erase(sides.begin()+index-1);
}

void Sales_Create_Order::delete_drink()
{
    cout << "Choose the number you would like to delete: " << endl;

    for (unsigned int i = 0 ; i < drinks.size() ; i++)
    {
        cout << "\t" << i+1 << ". " << drinks[i].get_name() << endl;
    }

    int index;
    cin >> index;

    drinks.erase(drinks.begin()+index-1);
}

Location Sales_Create_Order::choose_location()
{
    Location location;
    LocationService l;
    vector <Location> locations = l.view_items();

    system("CLS");
    cout << "Choose delivery location:" << endl;
    for (unsigned int i = 0 ; i < locations.size() ; i++)
    {
        cout << i+1 << ". " << locations[i].get_name() << endl;
    }
    int choice;
    cin >> choice;

    this->location = locations[choice-1];

    return locations[choice-1];
}

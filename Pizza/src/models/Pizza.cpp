#include "Pizza.h"
#include <iomanip>
#include <iostream>
#include <vector>

#include "BottomService.h"
#include "SizeService.h"
using namespace std;

Pizza::Pizza()
{
    strcpy(this->name,"\0");
    identity = '\0';
    price = 0;
}

/// Used when admin creating a new pizza menu;
Pizza::Pizza(string name, char identity, vector<Topping> toppings, bool crust, int price)
{
    strcpy(this->name,name.c_str());
    this->identity = identity;
    this->crust = crust;
    this->price = price;

    for (unsigned int i = 0 ; i < toppings.size() ; i++)
    {
        this->toppings[i] = toppings[i];
    }
}

/// Set functions

void Pizza::set_name(string name)
{
    strcpy(this->name,name.c_str());
}
void Pizza::set_identity(char identity)
{
    this->identity = identity;
}
void Pizza::set_size(char input)
{
    SizeService s;
    vector<Size> sizes = s.view_items();

    for (unsigned int i = 0 ; i < sizes.size() ; i++)
    {
        if (sizes[i].get_identity() == input)
        {
            this->_size = sizes[i];
            break;
        }
    }
}
void Pizza::set_bottom(char input)
{
    BottomService b;
    vector<Bottom> bottoms = b.view_items();

    for (unsigned int i = 0 ; i < bottoms.size() ; i++)
    {
        if (bottoms[i].get_identity() == input)
        {
            this->bottom = bottoms[i];
            break;
        }
    }
}
void Pizza::set_toppings(vector<Topping> toppings)
{
    for (unsigned int i = 0 ; i < toppings.size() ; i++)
    {
        this->toppings[i] = toppings[i];
    }
}
void Pizza::set_price(int price)
{
    this->price = price;
}
void Pizza::set_crust(bool crust)
{
    this->crust = crust;
}

/// Get functions
string Pizza::get_name() const
{
    return string(this->name);
}

char Pizza::get_identity() const
{
    return this->identity;
}
Size Pizza::get_size() const
{
    return this->_size;
}
Bottom Pizza::get_bottom() const
{
    return this->bottom;
}
vector<Topping> Pizza::get_toppings()
{
    vector<Topping> toppings(begin(this->toppings), end(this->toppings));
    return toppings;
}
int Pizza::get_price() const
{
    return this->price;
}
bool Pizza::get_crust() const
{
    return this->crust;
}


ostream& operator << (ostream& out, Pizza& pizza)
{
    out << left << "\tName: " << setw(22) << pizza.name  << "Size: " << setw(10) << pizza._size << "Shortcut: " << setw(10) <<
        pizza.identity << "Cheesy Crust: " << setw(15);
    if (pizza.crust)
    {
        out << "yes";
    }
    else
    {
        out << "no";
    }
    out << "Price: " << pizza.price << "Kr." << endl;

    out << "\tToppings: ";

    vector<Topping> toppings;

    for (unsigned int j = 0; j < pizza.get_toppings().size() ; j++)
    {
        toppings.push_back(pizza.get_toppings()[j]);
    }

    for (unsigned int j = 0 ; j < toppings.size(); j++)
    {
        out << toppings[j] << " [" << toppings[j].get_counter() << "]";
        if (toppings[j+1].get_name() == "\0") break;
        else out << ", ";
    }
    cout << endl;

    return out;
}

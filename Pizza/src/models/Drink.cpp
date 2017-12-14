#include "Drink.h"

Drink::Drink()
{
    this->name[0] = '\0';
    this->identity = '\0';
    this->price = 0;
}

Drink::Drink(string name, char identity, int price)
{
    strcpy(this->name,name.c_str());
    this->identity = identity;
    this->price = price;
}


/// GET FUNCTIONS

string Drink::get_name() const
{
    return string(this->name);
}
char Drink::get_identity() const
{
    return this->identity;
}

int Drink::get_price() const
{
    return this->price;
}


/// SET FUNCTIONS

void Drink::set_name(string name)
{
    strcpy(this->name,name.c_str());
}

void Drink::set_identity(char identity)
{
    this->identity = identity;
}

void Drink::set_price(int price)
{
    this->price = price;
}

ostream& operator << (ostream& out, Drink& drink)
{
    out << string(drink.name);
    return out;
}


#include "Topping.h"

Topping::Topping()
{
    this->name[0] = '\0';
    this->identity = '\0';
    this->price = 0;
    this->is_vegan = 0;
    this->counter = 0;
}

Topping::Topping(string name, char identity, int price, bool is_vegan)
{
    strcpy(this->name,name.c_str());
    this->identity = identity;
    this->price = price;
    this->is_vegan = is_vegan;
    this->counter = 1;
}


/// GET FUNCTIONS

string Topping::get_name() const
{
    string temp = string(this->name);
    return temp;
}

int Topping::get_counter() const
{
    return this->counter;
}

char Topping::get_identity() const
{
    return this->identity;
}

int Topping::get_price() const
{
    return this->price;
}

bool Topping::get_is_vegan() const
{
    return this->is_vegan;
}


/// SET FUNCTIONS

void Topping::set_name(string name)
{
    strcpy(this->name,name.c_str());
}

void Topping::set_identity(char identity)
{
    this->identity = identity;
}

void Topping::set_counter(int counter)
{
    this->counter = counter;
}

void Topping::set_price(int price)
{
    this->price = price;
}

void Topping::set_is_vegan(bool vegan)
{
    this->is_vegan = vegan;
}

ostream& operator << (ostream& out, Topping& topping)
{
    out << string(topping.name);
    return out;
}

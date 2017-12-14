#include "Side.h"
Side::Side()
{
    this->name[0] = '\0';
    this->identity = '\0';
    this->price = 0;
    this->is_vegan = 0;
}

Side::Side(string name, char identity, int price, bool is_vegan)
{
    strcpy(this->name,name.c_str());
    this->identity = identity;
    this->price = price;
    this->is_vegan = is_vegan;
}


/// GET FUNCTIONS

string Side::get_name() const
{
    string temp = string(this->name);
    return temp;
}

char Side::get_identity() const
{
    return this->identity;
}

int Side::get_price() const
{
    return this->price;
}

bool Side::get_is_vegan() const
{
    return this->is_vegan;
}


/// SET FUNCTIONS

void Side::set_name(string name)
{
    strcpy(this->name,name.c_str());
}

void Side::set_identity(char identity)
{
    this->identity = identity;
}

void Side::set_price(int price)
{
    this->price = price;
}

void Side::set_is_vegan(bool vegan)
{
    this->is_vegan = vegan;
}

ostream& operator << (ostream& out, Side& side)
{
    out << string(side.name);
    return out;
}

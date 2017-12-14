#include "Bottom.h"

Bottom::Bottom()
{
    this->name[0] = '\0';
    this->identity = '\0';
    this->price = 0;
}

Bottom::Bottom(string name, char identity, int price)
{
    strcpy(this->name,name.c_str());
    this->identity = identity;
    this->price = price;
}


/// GET FUNCTIONS

string Bottom::get_name() const
{
    return string(this->name);
}

char Bottom::get_identity() const
{
    return this->identity;
}

int Bottom::get_price() const
{
    return this->price;
}


/// SET FUNCTIONS

void Bottom::set_name(string name)
{
    strcpy(this->name,name.c_str());
}

void Bottom::set_identity(char identity)
{
    this->identity = identity;
}

void Bottom::set_price(int price)
{
    this->price = price;
}

ostream& operator << (ostream& out, Bottom& bottom)
{
    out << string(bottom.name);
    return out;
}


#include "Size.h"

#include <iomanip>
using namespace std;
Size::Size()
{
    strcpy(this->_size, "\0");
    this->identity = '\0';
    this->price = 0;
}

Size::Size(string _size, char identity, int price)
{
    strcpy(this->_size, _size.c_str());
    this->identity = identity;
    this->price = price;
}


/// GET FUNCTIONS

string Size::get_name() const
{
    return string(this->_size);
}

char Size::get_identity() const
{
    return this->identity;
}

int Size::get_price() const
{
    return this->price;
}


/// SET FUNCTIONS

void Size::set_name(string name)
{
    strcpy(this->_size,name.c_str());
}

void Size::set_identity(char identity)
{
    this->identity = identity;
}

void Size::set_price(int price)
{
    this->price = price;
}

ostream& operator << (ostream& out, Size& _size)
{
    return out;
}

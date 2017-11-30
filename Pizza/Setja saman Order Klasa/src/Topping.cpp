#include "Topping.h"

Topping::Topping()
{

}

Topping::Topping (string _name, double _price, bool _is_vegan)
{
    this->name = _name;
    this->is_vegan = _is_vegan;
    this->price = _price;
}

string Topping::get_name()
{
    return this->name;
}

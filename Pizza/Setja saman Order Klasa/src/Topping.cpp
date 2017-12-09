#include "Topping.h"

Topping::Topping()
{

}

Topping::Topping (string _name, double _price, bool _is_vegan, unsigned int _topping_id)
{
    this->name = _name;
    this->is_vegan = _is_vegan;
    this->price = _price;
    this->topping_id = _topping_id;
}

string Topping::get_name()
{
    return this->name;
}

double Topping::get_price()
{
    return this->price;
}

unsigned int Topping::get_id()
{
    return this->topping_id;
}

void Side::change_string_to_arr(char arr[], string name)
{
   unsigned int n=name.size();

    for(unsigned int i = 0; i <= n; i++)
        {
            arr[i]=name[i];
        }
}

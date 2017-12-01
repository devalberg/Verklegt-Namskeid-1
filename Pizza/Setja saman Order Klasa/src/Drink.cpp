#include "Drink.h"

Drink::Drink()
{
    this->price = 0;
    this->size_in_l = 0;
    this->name = "";

}

Drink::Drink(int _price, double _size_in_l, string _name)
{
    this->price = _price;
    this->size_in_l = _size_in_l;
    this->name = _name;
}

ostream &operator << (ostream& out, Drink& current_drink)
{
    out << current_drink.name << " " << current_drink.size_in_l << "L " << current_drink.get_price() << "kr." << endl;

    return out;
}

double Drink::get_price()
{
    return this->price;
}

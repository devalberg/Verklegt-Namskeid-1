#include "Side.h"

Side::Side()
{
    this->name = "";
    this->price = 0;
    this->is_vegan = false;
}

Side::Side(string _name, double _price, bool _is_vegan)
{
    this->name = _name;
    this->price = _price;
    this->is_vegan = _is_vegan;
}

ostream &operator << (ostream& out, Side& current_side)
{
    out << current_side.name <<" " << current_side.price << " kr." << endl ;
    return out;
}



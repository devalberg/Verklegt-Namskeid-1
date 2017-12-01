#ifndef DRINK_H
#define DRINK_H
#include "Topping.h"


class Drink
{
    public:
        Drink();
        Drink(int _price, double _size_in_l, string _name);
        double get_price();
        friend ostream &operator << (ostream& out, Drink& current_drink);

    private:
        int price;
        int drink_id;
        double size_in_l;
        string name;


};

#endif // DRINK_H

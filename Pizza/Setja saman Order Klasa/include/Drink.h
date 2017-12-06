#ifndef DRINK_H
#define DRINK_H
#include "Topping.h"


class Drink
{
    public:
        Drink();
        Drink(int _price, double _size_in_l, string _name, int drink_id);
        double get_price();
        double get_size_in_l();
        unsigned int get_id();
        string get_name();
        friend ostream &operator << (ostream& out, vector <Drink>& current_drink_list);

    private:
        int price;
        unsigned int drink_id;
        double size_in_l;
        string name;


};

#endif // DRINK_H

#ifndef DRINK_H
#define DRINK_H
#include "Topping.h"
const unsigned int MAX_DRINKS = 20;


class Drink
{
    public:
        Drink();
        Drink(int _price, double _size_in_l, string _name, int drink_id);
        unsigned int get_id();
        double get_price();
        double get_size_in_l();
        char* get_name();
        void change_string_to_arr(char arr[], string name);

        friend ostream &operator << (ostream& out, Drink* current_drink_list);

    private:
        int price;
        unsigned int drink_id;
        double size_in_l;
        char name[20];


};

#endif // DRINK_H

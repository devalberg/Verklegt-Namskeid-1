#ifndef TOPPING_H
#define TOPPING_H
#include <iostream>
#include <string>
#include <vector>
 using namespace std;


class Topping
{
    public:
        Topping();
        Topping(string _name, double _price , bool _is_vegan, unsigned int _topping_id);
        double get_price();
        string get_name();
        unsigned int get_id();
        void change_string_to_arr(char arr[], string name);


    private:
        double price;
        unsigned int topping_id;
        bool is_vegan;
        string name;


};

#endif // TOPPING_H

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
        Topping(string _name, double _price , bool _is_vegan);
        string get_name();


    private:
        double price;
        int topping_id;
        bool is_vegan;
        string name;


};

#endif // TOPPING_H

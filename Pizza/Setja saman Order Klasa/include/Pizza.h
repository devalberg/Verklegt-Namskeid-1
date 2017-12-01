#ifndef PIZZA_H
#define PIZZA_H
#include "Topping.h"

class Pizza
{
    public:
        Pizza();
        Pizza(vector<Topping> _all_toppings, int _pizza_size, bool _cheesy_crust, double _price);
        void add_topping(Topping current_topping);
        void onoffmenu(bool onoff);
        bool is_on_menu();
        bool is_cheesy_crust();
        friend ostream &operator << (ostream& out,  Pizza& current_pizza);


    private:
        vector<Topping> all_toppings;
        string name;
        string bottom;
        bool cheesy_crust;
        bool on_menu;
        unsigned int number_of_toppings;
        int pizza_size;
        int pizza_id;
        double price;


};

#endif // PIZZA_H

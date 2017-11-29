#ifndef PIZZA_H
#define PIZZA_H
#include "Topping.h"

class Pizza
{
    public:
        Pizza();
        Pizza(vector<Topping> _all_toppings, int _pizza_size, bool _cheesy_crust);
        void add_topping(Topping current_topping);
        bool is_on_menu();
        bool is_cheesy_crust();
        bool onoffmenu(bool onoff);
        friend ostream &operator << (ostream& out,  Pizza& current_pizza);


    private:
        vector<Topping> all_toppings;
        string name;
        bool cheesy_crust;
        bool on_menu;
        int number_of_toppings;
        int pizza_size;


};

#endif // PIZZA_H

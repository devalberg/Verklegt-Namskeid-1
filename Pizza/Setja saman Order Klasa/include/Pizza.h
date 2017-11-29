#ifndef PIZZA_H
#define PIZZA_H
#include <vector>
#include "Topping.h"
#include <iostream>

using namespace std;

class Pizza
{
    public:
        Pizza();
        add_topping();

    private:
        vector<Topping> all_toppings;
        int number_of_toppings;
        int pizza_size;
};

#endif // PIZZA_H

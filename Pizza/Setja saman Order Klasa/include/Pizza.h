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

    private:
        vector<Topping> all_toppings;
};

#endif // PIZZA_H

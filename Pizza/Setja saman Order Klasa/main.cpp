#include <iostream>
#include "Pizza.h"
#include "Order.h"
#include "Topping.h"

using namespace std;

int main()
{

vector<Topping> _all_toppings;
int _pizza_size = 16;
bool _cheesy_crust = true;

vector<Topping> no_toppings;
int _pizza_size_2 = 35;
bool _cheesy_crust_2 = false;

Topping pepperoni("pepperoni", 100, 0);
_all_toppings.push_back(pepperoni);


Pizza pizza(_all_toppings, _pizza_size, _cheesy_crust, 1350);
Pizza pizza_2(no_toppings, _pizza_size_2, _cheesy_crust_2, 1500);

pizza.onoffmenu(false);
pizza_2.onoffmenu(false);

Drink FizzBuzz(50, 0.5, "FizzBuzz");

Order order(9999);
pizza.add_topping(pepperoni);
order.add_pizza(pizza);
order.add_pizza(pizza_2);
order.add_drink(FizzBuzz);
order.add_drink(FizzBuzz);
order.add_drink(FizzBuzz);
order.add_drink(FizzBuzz);

Side guac("guac", 150, 0);
order.add_side(guac);
order.add_side(guac);
order.add_side(guac);
order.add_side(guac);
order.add_side(guac);
order.add_side(guac);

cout << order;
    return 0;
}

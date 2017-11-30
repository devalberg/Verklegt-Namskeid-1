#include <iostream>
#include "Pizza.h"
#include "Order.h"
#include "Topping.h"

using namespace std;

int main()
{

//vector<Topping> _all_oppings;
//_all_oppings
vector<Topping> _all_toppings;
int _pizza_size = 16;
bool _cheesy_crust = false;


Topping pepperoni("pepperoni", 100, 0);
//_all_toppings.push_back(pepperoni);
Pizza pizza(_all_toppings, _pizza_size, _cheesy_crust);
pizza.onoffmenu(true);

Order order;
//pizza.add_topping(pepperoni);
order.add_pizza(pizza);



cout << "This is the order: " << order;
    return 0;
}

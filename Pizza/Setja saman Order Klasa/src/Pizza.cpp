#include "Pizza.h"

Pizza::Pizza()
{

}

Pizza::Pizza(vector<Topping> _all_toppings, int _pizza_size, bool _cheesy_crust)
{
    this->all_toppings = _all_toppings;
    this->pizza_size = _pizza_size;
    this->cheesy_crust = _cheesy_crust;
    this->name = "Custom pizza";
}

void Pizza::add_topping(Topping current_topping)
{
    this->all_toppings.push_back(current_topping);
}

ostream &operator << (ostream& out,  Pizza& current_pizza)
{
    if (current_pizza.is_on_menu() == true)
    {
        out << current_pizza.pizza_size << " inch " << current_pizza.name;
        if(current_pizza.cheesy_crust == true)
        {
            out << " with cheesy crust";
        }
        return out;
    }
    else
    {
        out << current_pizza.pizza_size << " inch pizza with " ;
        for (int i = 0; i < current_pizza.number_of_toppings; i++)
        {


           out << (current_pizza.all_toppings[i]).get_name();
        }
    }
}

bool Pizza::is_cheesy_crust()
{
    return (this->cheesy_crust);
}

bool Pizza::is_on_menu()
{
    return (this->on_menu);
}

bool Pizza::onoffmenu(bool onoff)
{
    this->on_menu = onoff;
}

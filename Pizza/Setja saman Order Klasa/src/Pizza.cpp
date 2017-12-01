#include "Pizza.h"

Pizza::Pizza()
{

}

Pizza::Pizza(vector<Topping> _all_toppings, int _pizza_size, bool _cheesy_crust, double _price)
{
    this->all_toppings = _all_toppings;
    this->pizza_size = _pizza_size;
    this->cheesy_crust = _cheesy_crust;
    this->name = "Custom pizza";
    this->number_of_toppings = this->all_toppings.size();
    this->bottom = "Classic";
    this->price = _price;
}

void Pizza::add_topping(Topping current_topping)
{
    this->all_toppings.push_back(current_topping);
    this->number_of_toppings++;
}

ostream &operator << (ostream& out,  Pizza& current_pizza)
{
    out << endl << "\t" ;

    if (current_pizza.is_on_menu() == true)
    {
        out << current_pizza.pizza_size << "\" " << current_pizza.name << current_pizza.bottom << " bottom";
        if(current_pizza.cheesy_crust == true)
        {
            out << " (Cheesy Crust)" << endl;
            out << "\t" << "\t" << "\t" << current_pizza.price;

        }
        return out;
    }
    else
    {
        out << current_pizza.pizza_size << "\" Custom pizza: " << current_pizza.bottom << " bottom";

        if(current_pizza.cheesy_crust == true)
        {
            out << "(Cheesy Crust)";

        }

        out << endl;

        for (unsigned int i = 0; i < current_pizza.number_of_toppings; i++)
        {
           out << "\t" << "\t" << (current_pizza.all_toppings[i]).get_name() << endl;
        }

        out << "\t" << "\t" << "\t" << current_pizza.price << "kr.";
    }

    return out;
}

bool Pizza::is_cheesy_crust()
{
    return (this->cheesy_crust);
}

bool Pizza::is_on_menu()
{
    return (this->on_menu);
}

void Pizza::onoffmenu(bool onoff)
{
    this->on_menu = onoff;
}

#include "Pizza.h"

Pizza::Pizza()
{

}

Pizza::Pizza(vector<Topping> _all_toppings, int _pizza_size, bool _cheesy_crust, double _price, double _total_price)
{
    this->all_toppings = _all_toppings;
    this->pizza_size = _pizza_size;
    this->cheesy_crust = _cheesy_crust;
    this->name = "Custom pizza";
    this->number_of_toppings = this->all_toppings.size();
    this->bottom = "Classic";
    this->base_price = _price;
    this->total_price = _total_price;
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
            out << "\t" << "\t" << "\t" << current_pizza.total_price;
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

//        for (unsigned int i = 0; i < current_pizza.number_of_toppings; i++)
//        {

    unsigned int number_of_topping_types = 30;
    unsigned int n;

    for (unsigned int i = 0; i < number_of_topping_types ; i++)
    {
        n = 0;
        for(unsigned int j = 0; j < current_pizza.all_toppings.size() ; j++)
        {
            if (current_pizza.all_toppings[j].get_id() == i)
            {
                n++;
            }
        }
            if (n > 0)
            {
                for(unsigned int k = 0; k < current_pizza.all_toppings.size(); k++)
                {
                    if(i == current_pizza.all_toppings[k].get_id())
                    {
                        out << "\t" << "\t" << current_pizza.all_toppings[k].get_name() << " " << n << "x" << endl;
                        k = current_pizza.all_toppings.size();
                    }
                }
            }
         //  out << "\t" << "\t" << (current_pizza.all_toppings[i]).get_name() << endl;

    }

        //}
        out << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << current_pizza.get_price() << "kr.";
    }
    return out;
}

double Pizza::get_price()
{
    if(this->is_on_menu() == false)
    {
        this->total_price = 0;
        total_price += this->base_price;

            for(unsigned int i = 0; i < this->number_of_toppings; i++)
            {
                total_price += all_toppings[i].get_price();
            }
            if(this->cheesy_crust == true)
            {
                total_price += 250;
            }
    }
    total_price /= 15;
    total_price *= this->pizza_size;
    return this->total_price;
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

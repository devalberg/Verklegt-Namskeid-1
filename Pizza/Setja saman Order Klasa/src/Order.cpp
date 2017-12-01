#include "Order.h"



Order::Order(double _total_price)
{
    this->total_price = _total_price;
    this->order_id = 69;
}

ostream &operator << (ostream& out,  Order& current_order)
{
    char user_type = 's';

    if(user_type == 's')
    {
        out << "Order number: " << current_order.order_id << endl;
        out << "--------------------------------------------------------" << endl;
        out << "Pizzas:";
        out << "\t";
            for(unsigned int i = 0; i < current_order.pizza_list.size(); i++)
            {
                out << current_order.pizza_list[i] << " ";
            }
        out << endl << endl ;
        out << "--------------------------------------------------------" << endl;
        out << "Drinks:" << endl;
            for(unsigned int i = 0; i < current_order.drinks_list.size(); i++)
            {
                out << "\t" << current_order.drinks_list[i] << " ";
            }
        out << endl ;
        out << "--------------------------------------------------------" << endl;
        out << "Sides: " << endl;
            for(unsigned int i = 0; i < current_order.sides_list.size(); i++)
            {
                out << "\t" << current_order.sides_list[i] << " ";
            }

    }
    /*
    else if(user_type == 'b')
    {

    }
    else if(user_type == 'd')
    {

    }

*/
        out << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        out << "\t" << "\t" << "\t" << "Total: " << current_order.total_price << "kr.";
    return out;
}


void Order::add_pizza(Pizza current_pizza)
{
    this->pizza_list.push_back(current_pizza);
}

void Order::add_drink(Drink current_drink)
{
    this->drinks_list.push_back(current_drink);
}
void Order::add_side(Side current_side)
{
    this->sides_list.push_back(current_side);
}



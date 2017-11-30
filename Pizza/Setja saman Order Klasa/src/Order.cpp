#include "Order.h"



Order::Order()
{
    this->id_num = 69;
}


void Order::add_pizza(Pizza current_pizza)
{
    this->pizza_list.push_back(current_pizza);
}


ostream &operator << (ostream& out,  Order& current_order)
{
    char user_type = 's';

    if(user_type = 's')
    {
        out << "Order number: " << current_order.id_num;
        out << "    ";
            for(int i = 0; i < current_order.pizza_list.size(); i++)
            {
                out << current_order.pizza_list[i] << " ";
            }
    }
    /*
    else if(user_type = 'b')
    {

    }
    else if(user_type = 'd')
    {

    }

    out << "Wubbaluba dub dub";
*/

    return out;
}




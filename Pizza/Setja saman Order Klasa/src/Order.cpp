#include "Order.h"



Order::Order()
{

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

                out << current_order.drinks_list << " ";

        out << endl ;
        out << "--------------------------------------------------------" << endl;
        out << "Sides: " << endl;

                out << current_order.sides_list;


    }
    /*
    else if(user_type == 'b')
    {

    }
    else if(user_type == 'd')
    {

    }

*/
        current_order.update_price();
        out << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        out << "\t" << "\t" << "\t" << "Total: " << current_order.total_price << "kr." << endl << endl;
        out << "Comment:" << current_order.comment << endl;
        out << "Name: " << current_order.name << endl;
        out << "Phone: " << current_order.name << endl;
        out  << "Address: " << current_order.address << endl << endl;
    return out;
}


void Order::update_price()
{

    this->total_price = 0;
    double pizza_price = 0;
    double drink_price = 0;
    double sides_price = 0;

    for(unsigned int i = 0; i < this->pizza_list.size(); i++)
    {
        pizza_price += this->pizza_list[i].get_price();
    }
    this->total_price += pizza_price;

        for(unsigned int i = 0; i < this->drinks_list.size(); i++)
    {
        drink_price += this->drinks_list[i].get_price();
    }
    this->total_price += drink_price;

        for(unsigned int i = 0; i < this->sides_list.size(); i++)
    {
        sides_price += this->sides_list[i].get_price();
    }
    this->total_price += sides_price;
}

void Order::print_comment()
{
cin.getline(comment, 140);
cout << comment;
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





void Order::change_name()
{
    cout << "Name: ";
    cin >> this->name;
}

void Order::change_phone()
{
    cout << "Phone number: ";
    cin >> this->phone;
}

void Order::change_address()
{
    cout << "Address: ";
    cin >> this->address;
}

void Order::change_comment()
{
    cout << "Comment: ";
    cin >> this->comment;
}

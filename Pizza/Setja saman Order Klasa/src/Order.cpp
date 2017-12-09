#include "Order.h"

void Order::take_side_order(Order& current_order)
{
/// Kannski hafa öll nöfn með jafn marga stafi, fylla inn í með auðum plássum
    ///Þarf að lesa öll sides úr skrá
    Side really_bad_wings("Really Bad Wings", 300, 0, 2);
    Side guac("guac, the real guac", 150, 0, 0);
    Side cold_pizza("Cold Personal Pizza", 450, 0, 1);

        char temp_side_id;
    cout << "Input side id: 'g' = guac, 'w' = wings, 'p' = personal pizza, 'b' = Go back: ";

    while(true)
        {
        cin >> temp_side_id;
        if (temp_side_id == 'g')
        {
            current_order.add_side(guac);
            cout << "guac, the real guac x1" << endl;
            /// Ætti mikklu frekar að vera guac.get_name()
        }
        else if (temp_side_id == 'w')
        {
            current_order.add_side(really_bad_wings);
            cout << "Really Bad Wings x1" << endl;
        }
        else if (temp_side_id == 'p')
        {
            current_order.add_side(cold_pizza);
            cout << "Cold Personal Pizza x1" << endl;
        }
        else if (temp_side_id == 'b')
        {
            break;
        }
        else(cout << "Wrong input m88");
        }
}


void Order::take_drink_order(Order& current_order)
{

    ///Þarf að lesa alla Drinks úr skrá

        Drink FizzBuzz_S(50, 0.5, "FizzBuzz", 0);
        Drink FizzBuzz_L(100, 1, "FizzBuzz", 1);
        Drink PurpleDrank_S(100, 0.5, "PurpleDrank", 2);
        Drink PurpleDrank_L(200, 1, "PurpleDrank", 3);

        char temp_side_id;
    cout << "Input drink: 'F' = FizzBuzz 1l, 'f' = FizzBuzz 0.5l, 'P' = Purple Drank 1l, 'p' = Purple Drank 0.5l, 'b' = Go back: ";

    while(true)
        {
        cout << endl;
        cin >> temp_side_id;
        if (temp_side_id == 'F')
        {
            current_order.add_drink(FizzBuzz_L);
            cout << "FizzBuzz, Large x1" << endl;
        }
        else if (temp_side_id == 'f')
        {
            current_order.add_drink(FizzBuzz_S);
            cout << "FizzBuzz, Small x1" << endl;
        }
        else if (temp_side_id == 'P')
        {
            current_order.add_drink(PurpleDrank_L);
            cout << "Purple Drank, Large x1" << endl;
        }
        else if (temp_side_id == 'p')
        {
            current_order.add_drink(PurpleDrank_S);
            cout << "Purple Drank, Small x1" << endl;
        }
        else if (temp_side_id == 'q')
        {
            break;
        }
        else(cout << "Wrong input m88");
        }
}


Order::Order()
{
    this->status = 0;
    this->number_of_sides = 0;
    this->number_of_drinks = 0;
    this->comment[0] = '\0';
    this->name[0] = '\0';
    this->phone[0] = '\0';
    this->address[0] = '\0';
    this-> order_id = 0;
    this-> number_of_sides = 0;
    this-> number_of_drinks = 0;
}

ostream &operator << (ostream& out, Order& current_order)
{
    char user_type = 's';

    if(user_type == 's')
    {

        out << "Order number: " << current_order.order_id << endl;
        out << "--------------------------------------------------------" << endl;
   /*     out << "Pizzas:";
        out << "\t";
            for(unsigned int i = 0; i < current_order.pizza_list.size(); i++)
            {
                out << current_order.pizza_list[i] << " ";
            }
        out << endl << endl ;
        out << "--------------------------------------------------------" << endl;
   */       out << "Drinks:" << endl;

            out << current_order.drinks_list << " ";

        out << endl ;
        out << "--------------------------------------------------------" << endl;
        out << "Sides: " << endl;
        out << current_order.sides_list;

    }

    else if(user_type == 'b')
    {

    }
    else if(user_type == 'd')
    {

    }

        current_order.update_price();
        out << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        out << "\t" << "\t" << "\t" << "Total: " << current_order.total_price << "kr." << endl << endl;
        out << "Comment:" << current_order.comment[0] << endl;
        out << "Name: " << current_order.name[0] << endl;
        out << "Phone: " << current_order.name[0] << endl;
        out << "Address: " << current_order.address[0] << endl << endl;
        out << "========================================================" << endl;
        out << endl << endl;

    return out;
}

istream &operator >> (istream& in, Order& current_order)
{
    char user_input;

    while(true)
    {
    cout << "Add pizza 'p'" << endl << "Add drink 'd'" << endl << "Add side dish 's'" << endl << "Complete order 'c'" << endl;
    cin >> user_input;

        if (user_input == 's')
        {
            current_order.take_side_order(current_order);
        }
        else if (user_input == 'd')
        {
         current_order.take_drink_order(current_order);
        }
        else if (user_input == 'p')
        {
            cout << "Coming soon :^)" << endl;
    //    current_order.take_pizza_order(current_order);
        }
        else if (user_input == 'c')
        {
            break;
        }
        else (cout << "m8? are you even doing? try again" << endl);


    }
    return in;
}

void Order::update_price()
{

    this->total_price = 0;
    double pizza_price = 0;
    double drink_price = 0;
    double sides_price = 0;
/*
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
*/
    for(unsigned int i = 0; i < this->number_of_sides; i++)
    {
        sides_price += this->sides_list[i].get_price();
    }
    this->total_price += sides_price;
}

unsigned int Order::get_order_id()
{
    return this->order_id;
}



void Order::print_comment()
{
cin.getline(comment, 140);
cout << comment;
}


void Order::add_pizza(Pizza current_pizza)
{
//    this->pizza_list.push_back(current_pizza);
}

void Order::add_drink(Drink current_drink)
{
    Drink temp_drink(0 ,0 , " ", 999);
    drinks_list[this->number_of_drinks] = current_drink;
    drinks_list[this->number_of_drinks + 1] = temp_drink;

    this->number_of_drinks++;
}
void Order::add_side(Side current_side)
{
    Side temp_side(" ",0 ,0 , 999);
    sides_list[this->number_of_sides] = current_side;
    sides_list[this->number_of_sides + 1] = temp_side;

    this->number_of_sides++;
}


void Order::change_status(int status)
{
    this->status = status;
}

void Order::change_order_id(int k)
{
    this->order_id = k;
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

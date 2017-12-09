#include "Order.h"
#include <fstream>

int numbOfOrders()
{
    ifstream fin;
    fin.open("Orders.dat", ios::binary|ios::app);

    fin.seekg(0, fin.end);
    int numbOfOrders  = fin.tellg() / sizeof(Order);
    fin.seekg(0, fin.beg);

    return numbOfOrders;
}

void vieworders(Order* orders, int numbOfOrders)
{
    for(int i = 0; i < numbOfOrders; ++i)
    {
        Order temp_order = orders[i];

            cout << temp_order << endl;
    }
}

void deleteorder(Order* orders)
{
    unsigned int input;

    vieworders(orders, numbOfOrders());

    cout << "Which order would you like to delete? ";
    cin >> input;

    ifstream fin;
    fin.open("Orders.dat", ios::binary);

    Order *neworder = new Order[numbOfOrders()];

    fin.read((char*)neworder, sizeof(Order)* numbOfOrders());
    fin.close();

    int k;
    for(int i = 0; i < numbOfOrders(); i++)
    {
        if(input == neworder[i].get_order_id())
        {
            neworder[i].change_status(300);
            k = i;
            break;
        }
    }
    fstream fout;
    fout.open("Orders.dat", ios::binary | ios::out | ios::in);

    fout.seekp(sizeof(Order)*k);
    fout.write((char*)&neworder[k], sizeof(Order));
    fout.close();
   // delete[] neworder;
}
void createorder()
{
    int k;
    Order order;
    ifstream kin;
    kin.open("ordernumber.txt");
    kin >> k;
    kin.close();

    k++;

    ofstream kout;
    kout.open("ordernumber.txt");
    kout << k;
    kout.close();

    order.change_order_id(k);

    cin >> order;
    //cout << "Cheeky cout hehehheh";
    ofstream fout;
    fout.open("Orders.dat", ios::binary|ios::app);

    fout.write((char*)&order, sizeof(Order));
    fout.close();
}
int main()
{
    char input;

    do
    {

        ifstream fin;
        fin.open("Orders.dat", ios::binary|ios::app);

        int numberoforders  = numbOfOrders();

        Order *orders = new Order[numberoforders];

        fin.read((char*)orders, sizeof(Order)* numberoforders);
        fin.close();

        cout << "Order menu:" << endl;
        cout << "View 'v', Create 'c', Delete 'd':";
        cin >> input;
        if(input == 'd')
        {
            deleteorder(orders);
        }
        else if(input == 'v')
        {
            vieworders(orders, numbOfOrders());
        }
        else if(input == 'c')
        {
            createorder();
        }
        delete[] orders;

    }while(input != 'q');

    return 0;
}

/*
Order order2;

cin >> order2;

//cout << order << endl;
cout << order2;

    return 0;
}




vector<Topping> _all_toppings;
int _pizza_size = 16;
bool _cheesy_crust = true;

vector<Topping> no_toppings;
int _pizza_size_2 = 18;
bool _cheesy_crust_2 = false;

Topping pepperoni("pepperoni", 100, 0, 0);
Topping not_pineapple("Not Pineapple", 200, 1, 1);
_all_toppings.push_back(pepperoni);
_all_toppings.push_back(not_pineapple);


Pizza pizza(_all_toppings, _pizza_size, _cheesy_crust, 1350, 0);
Pizza pizza_plain(no_toppings, _pizza_size_2, _cheesy_crust_2, 1350, 0);
Pizza twin_pizza1(_all_toppings, _pizza_size, _cheesy_crust, 1350, 0);
Pizza twin_pizza2(_all_toppings, _pizza_size, _cheesy_crust, 1350, 0);

pizza.onoffmenu(false);
pizza_plain.onoffmenu(false);
twin_pizza1.onoffmenu(false);
twin_pizza2.onoffmenu(false);

Drink FizzBuzz_S(50, 0.5, "FizzBuzz", 0);
Drink FizzBuzz_L(100, 1, "FizzBuzz", 1);
Drink PurpleDrank_S(100, 0.5, "PurpleDrank", 2);
Drink PurpleDrank_L(200, 1, "PurpleDrank", 3);


Order order;
pizza.add_topping(pepperoni);
pizza.add_topping(pepperoni);

order.add_pizza(pizza);
order.add_pizza(pizza_plain);
order.add_pizza(twin_pizza1);
order.add_pizza(twin_pizza2);

order.add_drink(FizzBuzz_S);
order.add_drink(FizzBuzz_L);
order.add_drink(PurpleDrank_L);
order.add_drink(FizzBuzz_S);
order.add_drink(FizzBuzz_L);
order.add_drink(FizzBuzz_L);
order.add_drink(PurpleDrank_L);
order.add_drink(FizzBuzz_L);
order.add_drink(FizzBuzz_L);
order.add_drink(PurpleDrank_L);
order.add_drink(PurpleDrank_S);

Side guac("guac, the real guac", 150, 0, 0);
Side cold_pizza("Cold Personal Pizza", 450, 0, 1);
Side really_bad_wings("Really Bad Wings", 300, 0, 2);
/// Kannski hafa öll nöfn með jafn marga stafi, fylla inn í með auðum plássum

order.add_side(really_bad_wings);
order.add_side(guac);
order.add_side(cold_pizza);
order.add_side(really_bad_wings);
order.add_side(guac);
order.add_side(cold_pizza);
order.add_side(cold_pizza);
order.add_side(guac);
order.add_side(guac);
order.add_side(cold_pizza);
order.add_side(guac);
order.add_side(guac);
*/

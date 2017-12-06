#include "Order.h"

int main()
{

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
cout << order;
    return 0;
}




/*


cout << "Comment:" ;
cin.getline(comment, 140);
cout << "Name: "  ;
cin.getline(name, 35);
cout << "Phone: ";
cin.getline(phone, 16);
cout  << "Address: ";
cin.getline(address, 32);



        cout << "Comment:" << comment << endl;
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
        cout  << "Address: " << address << endl << endl;
*/

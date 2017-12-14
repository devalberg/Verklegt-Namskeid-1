#ifndef PIZZA_H
#define PIZZA_H

#include "Size.h"
#include "Bottom.h"
#include "Topping.h"
#include <vector>

const unsigned int MAXNAMESIZE = 50;

class Pizza
{
public:
    Pizza();
/// Used when admin creating a new pizza menu;
    Pizza(string name, char identity, vector<Topping> toppings, bool crust, int price);

    /// Set functions
    void set_name(string name);
    void set_identity(char identity);
    void set_size(char input);
    void set_bottom(char input);
    void set_toppings(vector<Topping> toppings);
    void set_price(int price);
    void set_crust(bool crust);

    friend ostream& operator << (ostream& out, Pizza& pizza);

    /// Get functions
    string get_name() const;
    char get_identity() const;
    Size get_size() const;
    Bottom get_bottom() const;
    vector<Topping> get_toppings();
    int get_price() const;
    bool get_crust() const;

private:
    char name[MAXNAMESIZE];
    char identity;
    Topping toppings[MAXTOPPINGS];
    Bottom bottom;
    bool crust;
    int price;
    Size _size;

};

#endif // PIZZA_H

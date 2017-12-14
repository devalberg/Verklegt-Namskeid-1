#ifndef TOPPING_H
#define TOPPING_H

#include "commonItemProperties.h"

const unsigned int MAXTOPPINGS = 50;
class Topping
{
    public:
        Topping();
        Topping(string name, char identity, int price, bool is_vegan);

        /// Get functions
        string get_name() const;
        char get_identity() const;
        int get_price() const;
        bool get_is_vegan() const;
        int get_counter() const;

        /// Set functions
        void set_name(string name);
        void set_identity(char identity);
        void set_price(int price);
        void set_is_vegan(bool vegan);
        void set_counter(int counter);

        friend ostream& operator << (ostream& out, Topping& topping);

    private:
        char name[MAXTOPPINGS];
        char identity;
        int price;
        bool is_vegan;
        int counter;
};

#endif // TOPPING_H

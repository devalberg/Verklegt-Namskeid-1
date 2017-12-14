#ifndef DRINK_H
#define DRINK_H

#include "commonItemProperties.h"

class Drink
{
    public:
        Drink();
        Drink(string name, char identity, int price);

        /// Get functions
        string get_name() const;
        char get_identity() const;
        int get_price() const;

        /// Set functions
        void set_name(string name);
        void set_identity(char identity);
        void set_price(int price);

        friend ostream& operator << (ostream& out, Drink& drink);

    private:
        char name[MAXITEMNAMESIZE];
        char identity;
        int price;
};

#endif // DRINK_H

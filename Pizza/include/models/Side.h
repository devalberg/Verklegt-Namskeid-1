#ifndef SIDE_H
#define SIDE_H

#include "commonItemProperties.h"

class Side
{
public:
    Side();
    Side(string name, char identity, int price, bool is_vegan);

    /// Get functions
    string get_name() const;
    char get_identity() const;
    int get_price() const;
    bool get_is_vegan() const;

    /// Set functions
    void set_name(string name);
    void set_identity(char identity);
    void set_price(int price);
    void set_is_vegan(bool vegan);

    friend ostream& operator << (ostream& out, Side& side);
private:
    char name[32];
    char identity;
    int price;
    bool is_vegan;
};

#endif // SIDE_H

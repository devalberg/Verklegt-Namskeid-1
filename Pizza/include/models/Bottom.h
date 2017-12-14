#ifndef BOTTOM_H
#define BOTTOM_H

#include "commonItemProperties.h"

class Bottom
{
public:
    Bottom();
    Bottom(string name, char identity, int price);

    /// Get functions
    string get_name() const;
    char get_identity() const;
    int get_price() const;

    /// Set functions
    void set_name(string name);
    void set_identity(char identity);
    void set_price(int price);

    friend ostream& operator << (ostream& out, Bottom& bottom);

private:
    char name[MAXITEMNAMESIZE];
    char identity;
    int price;
};

#endif // BOTTOM_H

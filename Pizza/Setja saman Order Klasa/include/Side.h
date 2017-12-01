#ifndef SIDE_H
#define SIDE_H
#include "Topping.h"

class Side
{
    public:
        Side();
        Side(string _name, double _price, bool _is_vegan);
        friend ostream &operator << (ostream& out, Side& current_side);


    private:
        string name;
        double price;
        int topping_id;
        bool is_vegan;

};

#endif // SIDE_H

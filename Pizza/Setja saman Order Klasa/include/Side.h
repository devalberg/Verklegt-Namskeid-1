#ifndef SIDE_H
#define SIDE_H
#include "Topping.h"
const unsigned int MAX_SIDES = 20;

class Side
{
    public:
        Side();
        Side(string _name, double _price, bool _is_vegan, unsigned int _side_id);
        char* get_name();
        double get_price();
        unsigned int get_id();
        friend ostream &operator << (ostream& out, Side* current_side_list);
        void change_string_to_arr(char arr[], string name);


    private:
        char name[20];
        double price;
        unsigned int side_id;
        bool is_vegan;

};

#endif // SIDE_H

///char[]->string
///string -/> char[]

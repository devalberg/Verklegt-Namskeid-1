#ifndef SIDE_H
#define SIDE_H
#include "Topping.h"

class Side
{
    public:
        Side();
        Side(string _name, double _price, bool _is_vegan, unsigned int _side_id);
        string get_name();
        ///Þarf ekki að vera char array, má vera string
        double get_price();
        unsigned int get_id();
        friend ostream &operator << (ostream& out, vector <Side>& current_side_list);


    private:
        string name;
        ///Breyta í char, char getur orðið string
        double price;
        unsigned int side_id;
        bool is_vegan;

};

#endif // SIDE_H

///char[]->string
///string -/> char[]

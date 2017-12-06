#include "Side.h"

Side::Side()
{
    this->name = "";
    this->price = 0;
    this->is_vegan = false;
}

Side::Side(string _name, double _price, bool _is_vegan, unsigned int _side_id)
{
    this->name = _name;
    this->price = _price;
    this->is_vegan = _is_vegan;
    this->side_id = _side_id;
}

ostream &operator << (ostream& out, vector <Side>& current_side_list)
{
    /// Þarf fall til að vita hvað það eru til mörg sides
    unsigned int number_of_side_types = 30;
    unsigned int n;

    for (unsigned int i = 0; i < number_of_side_types ; i++)
    {
        n = 0;
        for(unsigned int j = 0; j < current_side_list.size() ; j++)
        {
            if (current_side_list[j].get_id() == i)
            {
                n++;
            }
        }
            if (n > 0)
            {
                for(unsigned int k = 0; k < current_side_list.size(); k++)
                {
                    if(i == current_side_list[k].get_id())
                    {
                        out << "\t" << current_side_list[k].get_name() << "\t" << current_side_list[k].get_price() << "kr." << "\t" << n << "x" << endl;
                        k = current_side_list.size();
                    }
                }

            }
    }
        return out;
}

string Side::get_name()
{
    return this->name;
}

unsigned int Side::get_id()
{
    return this->side_id;
}

double Side::get_price()
{
    return this->price;
}


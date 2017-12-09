#include "Side.h"
#include <cstring>
Side::Side()
{
    this->name[0] = '0';
    this->price = 0;
    this->is_vegan = false;
}

Side::Side(string _name, double _price, bool _is_vegan, unsigned int _side_id)
{
    change_string_to_arr(this->name, _name);
    this->price = _price;
    this->is_vegan = _is_vegan;
    this->side_id = _side_id;
}



char* Side::get_name()
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


ostream &operator << (ostream& out, Side* current_side_list)
{
    /// Þarf fall til að vita hvað það eru til mörg sides nota bara 30 að því að
    unsigned int number_of_side_types = 30;
    unsigned int n;
    unsigned int number_of_sides;

    for (number_of_sides = 0; number_of_sides < MAX_SIDES; number_of_sides++)
    {
        if (current_side_list[number_of_sides].get_id() == 999)
        {
            break;
        }
    }

    for(unsigned int i = 0; i < number_of_side_types; i++ )
    {
        n = 0;
        for(unsigned int j = 0; j < number_of_sides ; j++)
        {
            if (current_side_list[j].get_id() == i)
            {
                n++;
            }
        }
            if (n > 0)
            {
                for(unsigned int k = 0; k < number_of_sides; k++)
                {
                    if(i == current_side_list[k].get_id())
                    {
                        out << "\t" << current_side_list[k].get_name() << "\t" << current_side_list[k].get_price();
                        out << "kr." << "\t" << n << "x" << endl;
                        break;
                    }
                }

            }
    }
        return out;
}

void Side::change_string_to_arr(char arr[], string name)
{
   unsigned int n=name.size();

    for(unsigned int i = 0; i <= n; i++)
        {
            arr[i]=name[i];
        }
}

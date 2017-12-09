#include "Drink.h"

Drink::Drink()
{
    this->price = 0;
    this->size_in_l = 0;
    this->name[0] = '\0';

}

char* Drink::get_name()
{
        return this->name;
}

Drink::Drink(int _price, double _size_in_l, string _name, int _drink_id)
{
    this->price = _price;
    this->size_in_l = _size_in_l;
    change_string_to_arr(this->name, _name);
    this->drink_id = _drink_id;
}

ostream &operator << (ostream& out, vector <Drink>& current_drink_list)
{
//    get_number_of_sodas();
/// Þetta falla þarf að geta náð í fjölda drinkja sem hafa verið skráð í kerfið
    unsigned int number_of_drink_types = 30;
    unsigned int n;

    for (unsigned int i = 0; i < number_of_drink_types ; i++)
    {
        n = 0;
        for(unsigned int j = 0; j < current_drink_list.size() ; j++)
        {
            if (current_drink_list[j].get_id() == i)
            {
                n++;
            }
        }
            if (n > 0)
            {
                for(unsigned int k = 0; k < current_drink_list.size(); k++)
                {
                    if(i == current_drink_list[k].get_id())
                    {
                        out << "\t" << current_drink_list[k].get_name() <<" " << current_drink_list[k].get_size_in_l() << " l    \t" << current_drink_list[k].get_price() << "kr." << "\t" << n << "x" << endl;
                        k = current_drink_list.size();
                    }
                }

            }
    }
        return out;
}

void Drink::change_string_to_arr(char arr[], string name)
{
   unsigned int n=name.size();

    for(unsigned int i = 0; i <= n; i++)
        {
            arr[i]=name[i];
        }
}

double Drink::get_price()
{
    return this->price;
}

unsigned int Drink::get_id()
{
    return this->drink_id;
}
char* Drink::get_name()
{
    return this->name;
}

double Drink::get_size_in_l()
{
    return this->size_in_l;
}

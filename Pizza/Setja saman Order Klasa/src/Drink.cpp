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

ostream &operator << (ostream& out, Drink* current_drink_list)
{
//    get_number_of_sodas();
/// Þetta falla þarf að geta náð í fjölda drinkja sem hafa verið skráð í kerfið
    unsigned int number_of_drink_types = 30;
    unsigned int n;
    unsigned int number_of_drinks;

    for(number_of_drinks = 0; number_of_drinks < MAX_DRINKS; number_of_drinks++)
    {
      if (current_drink_list[number_of_drinks].get_id() == 999)
        {
            break;
        }
    }

    for (unsigned int i = 0; i < number_of_drink_types ; i++)
    {
        n = 0;
        for(unsigned int j = 0; j < number_of_drinks; j++)
        {
            if (current_drink_list[j].get_id() == i)
            {
                n++;
            }
        }
            if (n > 0)
            {
                for(unsigned int k = 0; k < number_of_drinks; k++)
                {
                    if(i == current_drink_list[k].get_id())
                    {
                        out << "\t" << current_drink_list[k].get_name() <<" " << current_drink_list[k].get_size_in_l();
                        out << " l    \t" << current_drink_list[k].get_price() << "kr." << "\t" << n << "x" << endl;
                        break;
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

unsigned int Drink::get_id()
{
    return this->drink_id;
}

double Drink::get_price()
{
    return this->price;
}

double Drink::get_size_in_l()
{
    return this->size_in_l;
}

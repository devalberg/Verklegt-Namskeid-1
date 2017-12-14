#include "DrinkService.h"

DrinkService::DrinkService()
{
    //ctor
}

////////////////////// Manipulate items ///////////////////////////
void DrinkService::add_item(const Drink& item)
{
    if (validate_name(item.get_name()) && validate_identity(item.get_identity()) && validate_price(item.get_price()))
    {
        _repository.newItem(item);
    }
}

void DrinkService::delete_item(string item_name)
{
    vector<Drink> itemsList = _repository.get_items();

    bool found = false;
    for (unsigned int i = 0 ; i < itemsList.size() ; i++)
    {
        if (! itemsList[i].get_name().compare(item_name) )
        {
            itemsList.erase(itemsList.begin() + i);
            found = true;
            break;
        }
    }

    if (!found)
    {
        throw InvalidItemNameException(false);
    }

    _repository.editItem(itemsList);
}

vector<Drink> DrinkService::view_items()
{
    return _repository.get_items();
}

char DrinkService::is_char_in_vector(vector<char> _vector, char _input)
{
     for(unsigned int i = 0; i < _vector.size(); i++)
    {
        if(_input == _vector[i])
        {
            return true;
        }
    }
    return false;
}

void DrinkService::add_by_char(vector<Drink> drink_vector, vector<Drink>& drink_list, char input)
{
        for(unsigned int i = 0; i < drink_vector.size(); i++)
        {
            if(drink_vector[i].get_identity() == input)
            {
                drink_list.push_back(drink_vector[i]);
                break;
            }
        }
}

Drink* DrinkService::vector_to_array(vector<Drink> drink_vector)
{
    Drink drink_array[MAX_DRINKS];
    for(unsigned int i = 0; i < drink_vector.size(); i++)
    {
        drink_array[i] = drink_vector[i];
    }
    return drink_array;
}

/////////////////// validate ////////////////////////

bool DrinkService::validate_name(string name)
{
    if (name.length() < 1 || name.length() > MAXITEMNAMESIZE )
    {
        throw InvalidItemNameException();
    }

    vector<Drink> items = _repository.get_items();

    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (!name.compare(items[i].get_name()))
        {
            throw InvalidItemNameException(name);
        }
    }

    return true;
}

bool DrinkService::validate_identity(char identity)
{
    if(!isalpha(identity))
    {
        throw InvalidItemIdExceptions();
    }

    vector<Drink> items = _repository.get_items();

    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (identity == items[i].get_identity())
        {
            throw InvalidItemIdExceptions(identity);
        }
    }

    return true;
}

bool DrinkService::validate_price(int price)
{
    if(price <= 0)
    {
        throw InvalidItemPriceException();
    }
    return true;
}

bool DrinkService::check_match(char identity)
{
    vector<Drink> items = _repository.get_items();
    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (identity == items[i].get_identity())
        {
            this->drink = items[i];
            return true;
        }
    }

    return false;
}

Drink DrinkService::get_drink()
{
    return this->drink;
}

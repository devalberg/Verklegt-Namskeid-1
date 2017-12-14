#include "ToppingService.h"

ToppingService::ToppingService()
{
    //ctor
}

////////////////////// Manipulate items ///////////////////////////
void ToppingService::add_item(const Topping& item)
{
    if (validate_name(item.get_name()) && validate_identity(item.get_identity()) && validate_price(item.get_price()))
    {
        _repository.newItem(item);
    }
}

void ToppingService::delete_item(string item_name)
{
    vector<Topping> itemsList = _repository.get_items();

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

vector<Topping> ToppingService::view_items()
{
    return _repository.get_items();
}

void ToppingService::collate_toppings(vector<Topping>& toppings)
{
    vector<Topping> collated;
    bool match = false;
    if (toppings.size() != 0)
    {
        collated.push_back(toppings[0]);

        for (unsigned int i = 1 ; i < toppings.size() ; i++)
        {
            for (unsigned int j = 0 ; j < collated.size() ; j++)
            {
                if (toppings[i].get_identity() == collated[j].get_identity())
                {
                    int counter = collated[j].get_counter()+1;
                    collated[j].set_counter(counter);
                    match = true;
                    break;
                }
            }
            if (!match)
            {
                collated.push_back(toppings[i]);
            }
            match = false;
        }
    }

    toppings = collated;
}


/// VALIDATIONS
bool ToppingService::validate_name(string name)
{
    if (name.length() < 1 || name.length() > MAXITEMNAMESIZE )
    {
        throw InvalidItemNameException();
    }

    vector<Topping> items = _repository.get_items();

    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (!name.compare(items[i].get_name()))
        {
            throw InvalidItemNameException(name);
        }
    }

    return true;
}

bool ToppingService::validate_identity(char identity)
{
    if(!isalpha(identity))
    {
        throw InvalidItemIdExceptions();
    }

    vector<Topping> items = _repository.get_items();

    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (identity == items[i].get_identity())
        {
            throw InvalidItemIdExceptions(identity);
        }
    }
    return true;
}

bool ToppingService::validate_price(int price)
{
    if(price <= 0)
    {
        throw InvalidItemPriceException();
    }
    return true;
}

bool ToppingService::check_match(char identity)
{
    vector<Topping> items = _repository.get_items();
    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (identity == items[i].get_identity())
        {
            this->topping = items[i];
            return true;
        }
    }

    return false;
}

Topping ToppingService::get_topping()
{
    return this->topping;
}

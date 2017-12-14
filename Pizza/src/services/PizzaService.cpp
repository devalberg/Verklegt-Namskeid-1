#include "PizzaService.h"

#include "BottomService.h"
#include "ToppingService.h"
#include "SizeService.h"

PizzaService::PizzaService()
{
    //ctor
}



////////////////////// Manipulate items ///////////////////////////
void PizzaService::add_item(const Pizza& item)
{
    vector<Pizza> itemsList = _repository.get_items();

    for (unsigned int i = 0 ; i < itemsList.size() ; i++)
    {
        if ( ! itemsList[i].get_name().compare(item.get_name()) )
        {
            throw InvalidItemNameException(itemsList[i].get_name());
        }
    }

    _repository.newItem(item);
}

void PizzaService::delete_item(string item_name)
{
    vector<Pizza> itemsList = _repository.get_items();

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

vector<Pizza> PizzaService::view_items()
{
    return _repository.get_items();
}


Pizza PizzaService::finalize_pizza_admin(string name, char identity, Size& _size, Bottom& bottom, vector<Topping> toppings, bool crust, int price)
{
    BottomService b;
    SizeService s;
    ToppingService t;

    vector<Bottom> bottoms = b.view_items();
    vector<Size> sizes = s.view_items();
    vector<Topping> tops = t.view_items();
    vector<Pizza> pizzas = view_items();

    vector<Topping> tempTops;

    bool found = false;

    // Identity

    for (unsigned int i = 0 ; i < pizzas.size() ; i++)
    {
        if (identity == pizzas[i].get_identity())
        {
            throw InvalidItemIdExceptions(true);
        }
    }

    // toppings
    found = false;
    for (unsigned int i = 0 ; i < toppings.size() ; i++)
    {
        for (unsigned int j = 0 ; j < tops.size(); j++)
        {
            if (toppings[i].get_identity() == tops[j].get_identity())
            {
                tempTops.push_back(tops[j]);
                found = true;
                break;
            }
        }
        if (!found)
        {
            throw InvalidItemIdExceptions('t');
        }
    }

    t.collate_toppings(tempTops);

    if (price < 0)
    {
        throw InvalidItemPriceException();
    }

    Pizza pizza(name, identity, tempTops, crust, price);

    return pizza;
}

bool PizzaService::check_match(char input) {

    vector<Pizza> items = _repository.get_items();
    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (input == items[i].get_identity())
        {
            pizza = items[i];
            return true;
        }
    }

    return false;
}

Pizza PizzaService::get_pizza()
{
    return this->pizza;
}




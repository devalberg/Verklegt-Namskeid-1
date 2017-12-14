#include "OrderRepository.h"

#include <fstream>
#include <cstring>

OrderRepository::OrderRepository()
{
    //ctor
}


void OrderRepository::readFromDatabase()
{
    ///Bara pending

    Order item;
    itemsList.clear();

    ifstream fin("order_database/active_orders.dat", ios::binary);

    if (fin.is_open())
    {
        fin.seekg(0, fin.end);
        unsigned int records = fin.tellg() / sizeof(Order);
        fin.seekg(0, fin.beg);

        for (unsigned int i = 0 ;  i < records ; i++)
        {
            fin.read((char*) &item, sizeof(Order));
            itemsList.push_back(item);
        }
    }

    fin.close();

}

void OrderRepository::readFromLegacy()
{

    Order item;
    itemsList.clear();

    ifstream fin("order_database/legacy_orders.dat", ios::binary);

    if (fin.is_open())
    {
        fin.seekg(0, fin.end);
        unsigned int records = fin.tellg() / sizeof(Order);
        fin.seekg(0, fin.beg);

        for (unsigned int i = 0 ;  i < records ; i++)
        {
            fin.read((char*) &item, sizeof(Order));
            itemsList.push_back(item);
        }
    }

    fin.close();

}

vector<Order> OrderRepository::get_items()
{
    readFromDatabase();
    return itemsList;
}

vector<Order> OrderRepository::get_legacy_items()
{
    readFromLegacy();
    return itemsList;
}

////////////////////////////////////  WRITING  ////////////////////////////////////
#include <iostream>

void OrderRepository::newItem(const Order& item)
{
    ofstream fout;
    fout.open("order_database/active_orders.dat", ios::binary | ios::app);

    fout.write((char*) &item, sizeof(Order));
    fout.close();
}

void OrderRepository::editItem(vector<Order> items)
{
    itemsList = items;
    Order writeItems;
    ofstream fout("order_database/active_orders.dat", ios::binary);

    for (unsigned int i = 0 ; i < itemsList.size() ; i++)
    {
        writeItems = itemsList[i];
        fout.write((char*) &writeItems, sizeof(Order));
    }
    fout.close();
}

void OrderRepository::moveToLegacy(const Order& item)
{
    ofstream fout;
    fout.open("order_database/legacy_orders.dat", ios::binary | ios::app);

    fout.write((char*) &item, sizeof(Order));
    fout.close();
}

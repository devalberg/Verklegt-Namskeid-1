#include "PizzaRepository.h"

#include <fstream>
#include <cstring>

using namespace std;
PizzaRepository::PizzaRepository()
{
    //ctor
}

void PizzaRepository::readFromDatabase()
{
    Pizza item;
    itemsList.clear();

    ifstream fin("menu_database/pizzas.dat", ios::binary);

    if (fin.is_open())
    {
        fin.seekg(0, fin.end);
        unsigned int records = fin.tellg() / sizeof(Pizza);
        fin.seekg(0, fin.beg);

        for (unsigned int i = 0 ;  i < records ; i++)
        {
            fin.read((char*) &item, sizeof(Pizza));
            itemsList.push_back(item);
        }
    }

    fin.close();

}

vector<Pizza> PizzaRepository::get_items()
{
    readFromDatabase();
    return itemsList;
}


////////////////////////////////////  WRITING  ////////////////////////////////////

void PizzaRepository::newItem(const Pizza& item)
{
    ofstream fout;
    fout.open("menu_database/pizzas.dat", ios::binary | ios::app);

    fout.write((char*) &item, sizeof(Pizza));
    fout.close();


}

void PizzaRepository::editItem(vector<Pizza> items)
{
    itemsList = items;
    Pizza writeItems;
    ofstream fout("menu_database/pizzas.dat", ios::binary);

    for (unsigned int i = 0 ; i < itemsList.size() ; i++)
    {
        writeItems = itemsList[i];
        fout.write((char*) &writeItems, sizeof(Pizza));
    }

    fout.close();

}

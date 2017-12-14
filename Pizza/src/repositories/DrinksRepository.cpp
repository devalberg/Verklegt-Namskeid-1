#include "DrinksRepository.h"

#include <fstream>
#include <cstring>

using namespace std;
DrinksRepository::DrinksRepository()
{
    //ctor
}

void DrinksRepository::readFromDatabase()
{
    Drink item;
    itemsList.clear();

    ifstream fin("menu_database/drinks.dat", ios::binary);

    if (fin.is_open())
    {
        fin.seekg(0, fin.end);
        unsigned int records = fin.tellg() / sizeof(Drink);
        fin.seekg(0, fin.beg);

        for (unsigned int i = 0 ;  i < records ; i++)
        {
            fin.read((char*) &item, sizeof(Drink));
            itemsList.push_back(item);
        }
    }

    fin.close();

}

vector<Drink> DrinksRepository::get_items()
{
    readFromDatabase();
    return itemsList;
}


////////////////////////////////////  WRITING  ////////////////////////////////////

void DrinksRepository::newItem(const Drink& item)
{
    ofstream fout;
    fout.open("menu_database/drinks.dat", ios::binary | ios::app);

    fout.write((char*) &item, sizeof(Drink));
    fout.close();


}

void DrinksRepository::editItem(vector<Drink> items)
{
    itemsList = items;
    Drink writeItems;
    ofstream fout("menu_database/drinks.dat", ios::binary);

    for (unsigned int i = 0 ; i < itemsList.size() ; i++)
    {
        writeItems = itemsList[i];
        fout.write((char*) &writeItems, sizeof(Drink));
    }

    fout.close();

}

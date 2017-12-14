#include "ToppingRepository.h"

#include <fstream>
#include <cstring>


using namespace std;
ToppingRepository::ToppingRepository()
{
    //ctor
}

void ToppingRepository::readFromDatabase()
{
    Topping item;
    itemsList.clear();

    ifstream fin("menu_database/toppings.dat", ios::binary);

    if (fin.is_open())
    {
        fin.seekg(0, fin.end);
        unsigned int records = fin.tellg() / sizeof(Topping);
        fin.seekg(0, fin.beg);

        for (unsigned int i = 0 ;  i < records ; i++)
        {
            fin.read((char*) &item, sizeof(Topping));
            itemsList.push_back(item);
        }
    }

    fin.close();

}

vector<Topping> ToppingRepository::get_items()
{
    readFromDatabase();
    return itemsList;
}


////////////////////////////////////  WRITING  ////////////////////////////////////

void ToppingRepository::newItem(const Topping& item)
{
    ofstream fout;
    fout.open("menu_database/toppings.dat", ios::binary | ios::app);

    fout.write((char*) &item, sizeof(Topping));
    fout.close();


}

void ToppingRepository::editItem(vector<Topping> items)
{
    itemsList = items;
    Topping writeTopping;
    ofstream fout("menu_database/toppings.dat", ios::binary);

    for (unsigned int i = 0 ; i < itemsList.size() ; i++)
    {
        writeTopping = itemsList[i];
        fout.write((char*) &writeTopping, sizeof(Topping));
    }

    fout.close();

}

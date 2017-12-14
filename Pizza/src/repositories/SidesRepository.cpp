#include "SidesRepository.h"

#include <fstream>
#include <cstring>

using namespace std;
SidesRepository::SidesRepository()
{
    //ctor
}

void SidesRepository::readFromDatabase()
{
    Side item;
    itemsList.clear();

    ifstream fin("menu_database/sides.dat", ios::binary);

    if (fin.is_open())
    {
        fin.seekg(0, fin.end);
        unsigned int records = fin.tellg() / sizeof(Side);
        fin.seekg(0, fin.beg);

        for (unsigned int i = 0 ;  i < records ; i++)
        {
            fin.read((char*) &item, sizeof(Side));
            itemsList.push_back(item);
        }
    }

    fin.close();

}

vector<Side> SidesRepository::get_items()
{
    readFromDatabase();
    return itemsList;
}


////////////////////////////////////  WRITING  ////////////////////////////////////

void SidesRepository::newItem(const Side& item)
{
    ofstream fout;
    fout.open("menu_database/sides.dat", ios::binary | ios::app);

    fout.write((char*) &item, sizeof(Side));
    fout.close();


}

void SidesRepository::editItem(vector<Side> items)
{
    itemsList = items;
    Side writeItems;
    ofstream fout("menu_database/sides.dat", ios::binary);

    for (unsigned int i = 0 ; i < itemsList.size() ; i++)
    {
        writeItems = itemsList[i];
        fout.write((char*) &writeItems, sizeof(Side));
    }

    fout.close();

}

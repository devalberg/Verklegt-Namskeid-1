#include "LocationRepository.h"
#include <fstream>

LocationRepository::LocationRepository()
{
    //ctor
}

void LocationRepository::readFromDatabase()
{
    Location item;
    itemsList.clear();

    ifstream fin("menu_database/locations.dat", ios::binary);

    if (fin.is_open())
    {
        fin.seekg(0, fin.end);
        unsigned int records = fin.tellg() / sizeof(Location);
        fin.seekg(0, fin.beg);

        for (unsigned int i = 0 ;  i < records ; i++)
        {
            fin.read((char*) &item, sizeof(Location));
            itemsList.push_back(item);
        }
    }

    fin.close();

}

vector<Location> LocationRepository::get_items()
{
    readFromDatabase();
    return itemsList;
}


////////////////////////////////////  WRITING  ////////////////////////////////////

void LocationRepository::newItem(const Location& item)
{
    ofstream fout;
    fout.open("menu_database/locations.dat", ios::binary | ios::app);

    fout.write((char*) &item, sizeof(Location));
    fout.close();


}

void LocationRepository::editItem(vector<Location> items)
{
    itemsList = items;
    Location writeItems;
    ofstream fout("menu_database/locations.dat", ios::binary);

    for (unsigned int i = 0 ; i < itemsList.size() ; i++)
    {
        writeItems = itemsList[i];
        fout.write((char*) &writeItems, sizeof(Location));
    }

    fout.close();

}

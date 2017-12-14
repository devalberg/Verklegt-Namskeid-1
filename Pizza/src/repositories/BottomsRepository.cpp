#include "BottomsRepository.h"

#include <fstream>
#include <cstring>

using namespace std;
BottomsRepository::BottomsRepository()
{
    //ctor
}

void BottomsRepository::readFromDatabase()
{
    Bottom item;
    itemsList.clear();

    ifstream fin("menu_database/bottoms.dat", ios::binary);

    if (fin.is_open())
    {
        fin.seekg(0, fin.end);
        unsigned int records = fin.tellg() / sizeof(Bottom);
        fin.seekg(0, fin.beg);

        for (unsigned int i = 0 ;  i < records ; i++)
        {
            fin.read((char*) &item, sizeof(Bottom));
            itemsList.push_back(item);
        }
    }

    fin.close();

}

vector<Bottom> BottomsRepository::get_items()
{
    readFromDatabase();
    return itemsList;
}


////////////////////////////////////  WRITING  ////////////////////////////////////

void BottomsRepository::newItem(const Bottom& item)
{
    ofstream fout;
    fout.open("menu_database/bottoms.dat", ios::binary | ios::app);

    fout.write((char*) &item, sizeof(Bottom));
    fout.close();


}

void BottomsRepository::editItem(vector<Bottom> items)
{
    itemsList = items;
    Bottom writeItems;
    ofstream fout("menu_database/bottoms.dat", ios::binary);

    for (unsigned int i = 0 ; i < itemsList.size() ; i++)
    {
        writeItems = itemsList[i];
        fout.write((char*) &writeItems, sizeof(Bottom));
    }

    fout.close();

}

#include "SizeRepository.h"

#include <fstream>
#include <cstring>

using namespace std;
SizeRepository::SizeRepository()
{
    //ctor
}

void SizeRepository::readFromDatabase()
{
    Size item;
    itemsList.clear();

    ifstream fin("menu_database/sizes.dat", ios::binary);

    if (fin.is_open())
    {
        fin.seekg(0, fin.end);
        unsigned int records = fin.tellg() / sizeof(Size);
        fin.seekg(0, fin.beg);

        for (unsigned int i = 0 ;  i < records ; i++)
        {
            fin.read((char*) &item, sizeof(Size));
            itemsList.push_back(item);
        }
    }

    fin.close();

}

vector<Size> SizeRepository::get_items()
{
    readFromDatabase();
    return itemsList;
}


////////////////////////////////////  WRITING  ////////////////////////////////////

void SizeRepository::newItem(const Size& item)
{
    ofstream fout;
    fout.open("menu_database/sizes.dat", ios::binary | ios::app);

    fout.write((char*) &item, sizeof(Size));
    fout.close();


}

void SizeRepository::editItem(vector<Size> items)
{
    itemsList = items;
    Size writeItems;
    ofstream fout("menu_database/sizes.dat", ios::binary);

    for (unsigned int i = 0 ; i < itemsList.size() ; i++)
    {
        writeItems = itemsList[i];
        fout.write((char*) &writeItems, sizeof(Size));
    }

    fout.close();

}

#include "LoginRepository.h"

#include <fstream>
#include <cstring>


LoginRepository::LoginRepository()
{
    //ctor
}

void LoginRepository::readFromDatabase()
{
    User user;
    usersList.clear();

    ifstream fin("users_database/usersdata.dat", ios::binary);

    if (fin.is_open())
    {
        fin.seekg(0, fin.end);
        unsigned int records = fin.tellg() / sizeof(User);
        fin.seekg(0, fin.beg);

        for (unsigned int i = 0 ;  i < records ; i++)
        {
            fin.read((char*) &user, sizeof(User));
            usersList.push_back(user);
        }
    }

    fin.close();

}

vector<User> LoginRepository::get_users()
{
    readFromDatabase();
    return usersList;
}


////////////////////////////////////  WRITING  ////////////////////////////////////

void LoginRepository::newUser(const User& user)
{
    ofstream fout("users_database/usersdata.dat", ios::binary | ios::app);

    fout.write((char*) &user, sizeof(User));

    fout.close();
}

void LoginRepository::editUser(vector<User> users)
{
    usersList = users;
    User writeUser;
    ofstream fout("users_database/usersdata.dat", ios::binary);

    for (unsigned int i = 0 ; i < usersList.size() ; i++)
    {
        writeUser = usersList[i];
        fout.write((char*) &writeUser, sizeof(User));
    }

    fout.close();
}




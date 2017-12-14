#ifndef LOGINREPOSITORY_H
#define LOGINREPOSITORY_H

#include <vector>

#include "User.h"

using namespace std;


class LoginRepository
{
    public:
        LoginRepository();

        /// Write types;
        void newUser(const User& user);
        void editUser(vector<User> users);

        /// Function called by service to get list of users;
        vector<User> get_users();

    private:
        /// Reads data from datafile and stores in userList
        void readFromDatabase();

        /// Vector to keep all the users retrieved from datafile;
        vector<User> usersList;
};

#endif // LOGINREPOSITORY_H

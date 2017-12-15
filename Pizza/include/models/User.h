#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include "Location.h"
using namespace std;

const int MAXUSERNAME = 20;
const int MAXPASSWORD = 20;

class User
{
    public:
        /// Constructors
        User();
        User(char* username, char* password, char userType);
        User(string username, string password, char userType);
        Location location;

        /// Get different attributes
        string get_username() const;
        string get_password() const;
        char get_userType() const;

        /// Set different attributes
        void set_username(string username);
        void set_password(char* password);
        void set_userType(char userType);

        friend ostream& operator << (ostream& out, User& user);

    private:
        char username[MAXUSERNAME+1];
        char password[MAXPASSWORD+1];
        char userType;
};

#endif // USER_H

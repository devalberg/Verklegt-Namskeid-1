#include "User.h"
#include <cstring>
#include <iostream>
User::User()
{
    this->username[0] = '\0';
    this->password[0] = '\0';
    this->userType = '\0';
}

User::User(string username, string password, char userType)
{
    strcpy(this->username, username.c_str());
    strcpy(this->password, password.c_str());
    this->userType = userType;
}

User::User(char* username, char* password, char userType)
{
    strcpy(this->username, username);
    strcpy(this->password, password);
    this->userType = userType;
}


string User::get_username() const
{
    string username = string(this->username);
    return username;
}

string User::get_password() const
{
    string password = string(this->password);
    return password;
}

char User::get_userType() const
{
    return userType;
}

void User::set_username(string username)
{
    strcpy(this->username, username.c_str());
}

void User::set_password(char* password)
{
    strcpy(this->password, password);
}

void User::set_userType(char userType)
{
    this->userType = userType;
}

ostream& operator << (ostream& out, User& user)
{
    out << user.username;
    return out;
}

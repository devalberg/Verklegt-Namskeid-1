#ifndef LOGIN_H
#define LOGIN_H

struct Userpass
{
    std::string username;
    std::string password;
};

Userpass admin = {"admin", "password"};

bool login();
void check();

#endif // LOGIN_H_

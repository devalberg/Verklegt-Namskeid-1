#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

struct Userpass
{
    std::string username;
    std::string password;
};


bool login();

#endif // LOGIN_H_

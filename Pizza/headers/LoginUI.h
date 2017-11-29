#ifndef LOGINUI_H
#define LOGINUI_H
#include <string>
using namespace std;
class LoginUI
{
    public:
        char start_loginUI();
        void access(char chr);
        char getUserType();
    private:
        char userType;
};

struct Userpass
{
    std::string username;
    std::string password;
    char type;
};

char login();


#endif // LOGINUI_H

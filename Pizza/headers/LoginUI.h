#ifndef LOGINUI_H
#define LOGINUI_H
#include <string>
using namespace std;
class LoginUI
{
public:
    LoginUI(char* username, char* password, char userType);
    void start_loginUI();
    void access();
    char getUserType();
    char getUsername();
    friend istream& operator >> (istream& in, LoginUI& account);
private:
    char username[20];
    char password[20];
    char userType;
};


#endif // LOGINUI_H

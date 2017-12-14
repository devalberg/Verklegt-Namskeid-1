#ifndef INVALIDUSERNAMEEXCEPTION_H
#define INVALIDUSERNAMEEXCEPTION_H

#include <string>
using namespace std;

class InvalidUsernameException
{
    public:
        /// Called invalid username format
        InvalidUsernameException();

        /// Called when username not found in system
        InvalidUsernameException(string username, bool exist);
        string get_error();
    private:
        string message;
};

#endif // INVALIDUSERNAMEEXCEPTION_H

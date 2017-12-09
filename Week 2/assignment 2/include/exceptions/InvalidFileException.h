#ifndef INVALIDFILEEXCEPTION_H
#define INVALIDFILEEXCEPTION_H

#include <string>
#include "InvalidFileException.h"

using namespace std;

class InvalidFileException
{
    public:
        InvalidFileException();
        string get_error();
    private:
};

#endif // INVALIDFILEEXCEPTION_H

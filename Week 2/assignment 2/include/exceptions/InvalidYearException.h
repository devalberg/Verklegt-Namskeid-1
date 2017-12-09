#ifndef INVALIDYEAREXCEPTION_H
#define INVALIDYEAREXCEPTION_H

#include <string>
using namespace std;

class InvalidYearException
{
public:
    InvalidYearException();
    InvalidYearException(int year);
    string get_error();

private:
    int year;

};

#endif // INVALIDYEAREXCEPTION_H

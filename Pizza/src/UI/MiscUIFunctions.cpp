#include "MiscUIFunctions.h"

bool check_for_cancel(string input)
{
    for (unsigned int i = 0 ; i < input.length() ; i++)
    {
        if (input[i] == '\\')
        {
            cout << "You have canceled the operation" << endl << endl;
            return true;
        }
    }

    return false;

}

bool check_for_cancel(char input)
{

    if (input == '\\')
    {
        cout << "You have canceled the operation" << endl << endl;
        return true;
    }

    return false;
}

bool check_for_cancel(int input)
{
    if (input == -1)
    {
        cout << "You have canceled the operation" << endl << endl;
        return true;
    }

    return false;
}

char incase_fail(int input)
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore();
        char returnval = '\\';
        return returnval;
    }

    return '1';
}



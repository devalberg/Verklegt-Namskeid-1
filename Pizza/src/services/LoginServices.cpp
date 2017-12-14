#include "LoginServices.h"

LoginServices::LoginServices()
{
    //ctor
}


bool LoginServices::login(User& user)
{
    vector<User> usersList = _repository.get_users();

    for (unsigned int i = 0 ; i < usersList.size() ; i++)
    {
        if ( ! usersList[i].get_username().compare(user.get_username())
                && ! usersList[i].get_password().compare(user.get_password()) )
        {
            user = usersList[i];
            return true;
        }
    }

    return false;

}

vector<User> LoginServices::view_users()
{
    return _repository.get_users();
}

////////////////////// Manipulate users ///////////////////////////
void LoginServices::add_user(const User& user)
{
    vector<User> usersList = _repository.get_users();

    for (unsigned int i = 0 ; i < usersList.size() ; i++)
    {
        if ( ! usersList[i].get_username().compare(user.get_username()) )
        {
            throw InvalidUsernameException(user.get_username(), true);
        }
    }

    _repository.newUser(user);
}

User LoginServices::get_info_of_editing_user(string username)
{
    vector<User> usersList = _repository.get_users();

    bool found = false;
    unsigned int i = 0;
    for (; i < usersList.size() ; i++)
    {
        if (! usersList[i].get_username().compare(username))
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        throw InvalidUsernameException(username, false);
    }

    return usersList[i];

}
void LoginServices::edit_user(const User& user)
{
    vector<User> usersList = _repository.get_users();

    bool found = false;

    for (unsigned int i = 0; i < usersList.size() ; i++)
    {
        if (! usersList[i].get_username().compare(user.get_username()) )
        {
            usersList[i] = user;
            found = true;
            break;
        }
    }

    if (!found)
    {
        throw InvalidUsernameException(user.get_username(), false);
    }

    _repository.editUser(usersList);
}

void LoginServices::delete_user(string username)
{
    vector<User> usersList = _repository.get_users();

    bool found = false;
    for (unsigned int i = 0 ; i < usersList.size() ; i++)
    {
        if (! usersList[i].get_username().compare(username) )
        {
            usersList.erase(usersList.begin() + i);
            found = true;
            break;
        }
    }

    if (!found)
    {
        throw InvalidUsernameException(username, false);
    }

    _repository.editUser(usersList);
}




//////////////////////////////// validations //////////////////////////////////
bool LoginServices::validate_username(string username)
{
    if (username.length() < 1 || username.length() > MAXUSERNAME )
    {
        throw InvalidUsernameException();
    }
    return true;
}

bool LoginServices::validate_password(string password)
{
    if (password.length() < 3 || password.length() > MAXPASSWORD )
    {
        throw InvalidPasswordException();
    }
    return true;
}

bool LoginServices::validate_userType(char userType)
{
    if (userType != 'a' && userType != 's' && userType != 'b' && userType!= 'd')
    {
        throw InvalidUserTypeException();
    }
    return true;
}

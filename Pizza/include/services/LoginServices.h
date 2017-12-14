#ifndef LOGINSERVICES_H
#define LOGINSERVICES_H

#include "LoginRepository.h"
#include "User.h"

#include "InvalidUsernameException.h"
#include "InvalidPasswordException.h"
#include "InvalidLoginException.h"
#include "InvalidUserTypeException.h"

class LoginServices
{
    public:
        LoginServices();
        bool login(User& user);
        vector<User> view_users();

        /// User manipulations
        void add_user(const User& user);
        User get_info_of_editing_user(string username); // return to UI to show what user is editing, sent to edit_user()
        void edit_user(const User& user);
        void delete_user(string username);

        /// Validations
        bool validate_username(string username);
        bool validate_password(string password);
        bool validate_userType(char userType);

    private:
        LoginRepository _repository;



};

#endif // LOGINSERVICES_H

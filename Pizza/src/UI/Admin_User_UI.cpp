#include "Admin_User_UI.h"

#include <iomanip>
#include <iostream>
#include <cstdlib>
using namespace std;

Admin_User_UI::Admin_User_UI()
{
    //ctor
}

void Admin_User_UI::run()
{
    bool cont = true;
    while (cont)
    {
        system("CLS");
        cout << "============================================" << endl;
        cout << "               USERS MANAGEMENT" << endl;
        cout << "============================================\n" << endl;

        vector<User> users = _service.view_users();
        cout << "List of all users in the database" << endl;
        for (unsigned int i = 0 ; i < users.size(); i++)
        {
            cout << left << "\tUsername: " << setw(22) << users[i]  << "Password: " << setw(22)  << users[i].get_password() << "User type: ";
            char type = users[i].get_userType();
            if (type == 'a')
            {
                cout << "Administrator (a)" << endl;
            }
            else if (type == 's')
            {
                cout << "Sales (s)" << endl;
            }
            else if (type == 'b')
            {
                cout << "Baker (b)" << endl;
            }
            else if (type == 'd')
            {
                cout << "Delivery (d)" << endl;
            }
            else
            {
                cout << "Undefined" << endl;
            }
        }
        cout << endl;

        cout << "Select commands:" << endl;
        cout << "\t1. Add new user" << endl;
        cout << "\t2. Edit a user" << endl;
        cout << "\t3. Delete a user" << endl;

        cout << "Type 'back' to go back to main admin menu" << endl;

        cont = get_command();

    }
}

bool Admin_User_UI::get_command()
{
START:
    string input;
    cin >> input;

    if (input == "1")
    {
        add_user();
    }
    else if (input == "2")
    {
        edit_user();
    }
    else if (input == "3")
    {
        delete_user();
    }
    else if (input == "back")
    {
        return false;
    }
    else
    {
        cout << "Invalid input, please try again" << endl;
        goto START;
    }

    return true;
}

void Admin_User_UI::add_user()
{
    bool cont = true;
    while (cont)
    {
        system("CLS");
        string username, password;
        char userType;
        cout << "Adding new user" << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        cout << "User type: ";
        cin >> userType;

        try
        {
            _service.validate_username(username);
            _service.validate_password(password);
            _service.validate_userType(userType);
            _service.add_user(User(username, password, userType));

            char input;
            while (true)
            {
                cout << "\nAdd another user? (y/n): ";
                cin >> input;
                if (input == 'y')
                {
                    cont = true;
                    break;
                }
                else if (input == 'n')
                {
                    cont = false;
                    break;
                }
            }
        }
        catch (InvalidUsernameException e)
        {
            cout << e.get_error() << endl;
            system("pause");
        }
        catch (InvalidPasswordException e)
        {
            cout << e.get_error() << endl;
            system("pause");
        }
        catch (InvalidUserTypeException e)
        {
            cout << e.get_error() << endl;
            system("pause");
        }
    }

}

void Admin_User_UI::edit_user()
{
    bool cont = true;
    while (cont)
    {
        string username_to_edit;
        cout << "***********************************************************" << endl;
        cout << "Editing a user: " << endl;
        cout << "Enter the username of user you would like to edit:" << endl;
        cin >> username_to_edit;
        bool cancel = false;
        cancel = check_for_cancel(username_to_edit);
        if (cancel)
        {
            goto CANCELEDIT;
        }
        else
        {
            try
            {

                _service.validate_username(username_to_edit);

                User editing = _service.get_info_of_editing_user(username_to_edit);

                cout << "Current information of the account:" << endl;
                cout << "Username: " << editing.get_username() << endl;
                cout << "Password: " << editing.get_password() << endl;
                cout << "User type:" << editing.get_userType() << endl << endl;

                string password;
                char type;
                string temp;
                cout << "Enter the updated information of the account: (type '\\' any where to cancel)" << endl;
                cout << "Password: ";
                cin >> password;
                cancel = check_for_cancel(password);
                if (cancel) goto CANCELEDIT;
                cout << "User type: ";
                cin >> type;
                temp = type;
                cancel = check_for_cancel(temp);

                if (!cancel)
                {
                    _service.validate_password(password);
                    _service.validate_userType(type);
                    User updated_user(editing.get_username(), password, type);
                    _service.edit_user(updated_user);

                    cout << "User has been updated!" << endl;
                }
            }
            catch (InvalidUsernameException e)
            {
                cout << e.get_error() << endl;
                system("pause");
            }
            catch (InvalidPasswordException e)
            {
                cout << e.get_error() << endl;
                system("pause");
            }
            catch (InvalidUserTypeException e)
            {
                cout << e.get_error() << endl;
                system("pause");
            }

CANCELEDIT:
            char input;
            while (true)
            {
                cout << "\nEdit another user? (y/n): ";
                cin >> input;
                if (input == 'y')
                {
                    cont = true;
                    break;
                }
                else if (input == 'n')
                {
                    cont = false;
                    break;
                }
            }
        }
    }
}

bool Admin_User_UI::check_for_cancel(string input)
{
    for (unsigned int i = 0 ; i < input.length() ; i++)
    {
        if (input[i] == '\\')
        {
            cout << "You have canceled editing the user" << endl << endl;
            return true;
        }
    }

    return false;

}


void Admin_User_UI::delete_user()
{
    bool cont = true;
    while (cont)
    {
        string user_to_delete;
        string confirm;
        cout << "Deleting a user:" << endl;
        cout << "Type in the user you would like to delete (type '\\' anywhere to cancel)" << endl;
        cin >> user_to_delete;

        try
        {
            if (check_for_cancel(user_to_delete)) goto CANCELDELETE;
            _service.validate_username(user_to_delete);

            cout << "Are you sure you would like to delete the user: " << user_to_delete << "(type 'yes' to confirm)" << endl;
            cin >> confirm;

            if (confirm == "yes")
            {
                _service.delete_user(user_to_delete);
                cout << "User deleted successfully" << endl;
            }
            else
            {
                cout << "User has not been deleted" << endl;
            }

CANCELDELETE:
            char input;
            while (true)
            {
                cout << "\nDelete another user? (y/n): ";
                cin >> input;
                if (input == 'y')
                {
                    cont = true;
                    break;
                }
                else if (input == 'n')
                {
                    cont = false;
                    break;
                }
            }
        }
        catch (InvalidUsernameException e)
        {
            cout << e.get_error() << endl;
            system("pause");
        }

    }


}

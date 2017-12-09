#ifndef EMPLOYEEUI_H
#define EMPLOYEEUI_H

#include "Employee.h"
#include "EmployeeService.h"

class EmployeeUI
{
    public:
        EmployeeUI();
        void run();

    private:
        EmployeeService _service;
        /// Create instance of _service class

        Employee create_new_record();
        /// Take in user input and creates Employee class instance
        void verify_user_input(char input);
        /// this function verifies user input in the main menu

        string get_SSN_input();
        int get_year_input();
        /// These 2 functions used to print out and receive user input for SSN and year, just so that we don't need to write the same codes often



        void get_all_records_of_SSN();
        void get_year_total_of_SSN();
        void get_highest_total_of_year();
        void tryCreateRecord();
        /// These functions are called when user inputs a corresponding command in the main menu
        /// Each prints gets user input and sends them to the service layer

        void incaseFail(int& input);
        /// Stop loop incase user inserts an alphabet where int is input

};

#endif // EMPLOYEEUI_H

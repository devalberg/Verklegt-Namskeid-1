#include "EmployeeUI.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include "InvalidMainMenuInput.h"
using namespace std;

EmployeeUI::EmployeeUI()
{
    //ctor
}

void EmployeeUI::run()
{

    while (true)
    {
        cout << endl;
        cout << "================================================" << endl;
        cout << "            Employee monthly salary" << endl;
        cout << "================================================" << endl << endl;

        cout << "Select the following commands" << endl;
        cout << "1. Add record" << endl;
        cout << "2. Get all salary for given SSN" << endl;
        cout << "3. Get total for year of SSN" << endl;
        cout << "4. Get name for highest salary of year" << endl << endl;
        cout << "0. Exit program" << endl << endl;

        char input;
        cin >> input;
        try
        {
            verify_user_input(input);
        }
        catch (InvalidMainMenuInput)
        {
            system("CLS");
            cout << "Invalid input, please enter only the numbers corresponding to the options!" << endl;
        }
    }

}

void EmployeeUI::verify_user_input(char input)
{
    if (input == '1')
    {
        tryCreateRecord();
    }
    else if (input == '2')
    {
        get_all_records_of_SSN();
    }
    else if (input == '3')
    {
        get_year_total_of_SSN();
    }
    else if (input == '4')
    {
        get_highest_total_of_year();
    }
    else if (input == '0')
    {
        cout << "Thank you come again!" << endl;
        exit(0);
    }
    else
    {
        throw InvalidMainMenuInput();
    }


}

string EmployeeUI::get_SSN_input()
{
    string SSN;
    cout << "Enter the SSN of the employee you would like to view: ";
    cin >> SSN;
    return SSN;
}

int EmployeeUI::get_year_input()
{
    int year;
    cout << "Enter year you would like to view: ";
    cin >> year;
    return year;
}

void EmployeeUI::get_year_total_of_SSN()
{
    try
    {
        string SSN = get_SSN_input();
        int year = get_year_input();
        Employee employee = _service.yearSalaryOfSSN(SSN, year);
        system("CLS");
        cout << "\n\nHere is the sum of all records of " << employee.get_name() << " - '" << SSN << "' in the year " << year << ": " << endl;
        cout << "\tTotal: " << employee.get_salary() << endl;
        cout << endl << endl;
        system("pause");
        system("CLS");
    }
    catch (InvalidSSNException e)
    {
        system("CLS");
        cout << e.get_error() << endl << endl;
    }
    catch (InvalidYearException e)
    {
        system("CLS");
        cout << e.get_error() << endl << endl;
    }
    catch (InvalidFileException e)
    {
        system("CLS");
        cout << e.get_error() << endl << endl;
    }
}

void EmployeeUI::get_all_records_of_SSN()
{
    try
    {
        string SSN = get_SSN_input();
        vector<Employee> employee = _service.allSalaryOfSSN(SSN);
        system("CLS");
        cout << "Here is the list of all records of SSN: " << SSN << " (" << employee[0].get_name() << ")\n" << endl;
        for (unsigned int i = 0 ; i < employee.size() ; i++)
        {
            cout << employee[i].get_month() << "/" << employee[i].get_year() << ":\t" << employee[i].get_salary() << " Kr." << endl;
        }
        cout << endl << endl;
        system("pause");
        system("CLS");
    }
    catch (InvalidSSNException e)
    {
        system("CLS");
        cout << e.get_error() << endl << endl;
    }
    catch (InvalidFileException e)
    {
        system("CLS");
        cout << e.get_error() << endl << endl;
    }
}

Employee EmployeeUI::create_new_record ()
{

    string name;
    string SSN;
    int salary, month, year;
    cout << "Fill in the following fields to enter a new record" << endl;
    cout << "Name: ";
    cin.ignore();
    getline (cin, name);
    cout << "SSN: ";
    cin >> SSN;
    cout << "Salary (in Kr.): ";
    cin >> salary;
    incaseFail(salary);
    cout << "Month (1-12): ";
    cin >> month;
    incaseFail(month);
    cout << "Year: ";
    cin >> year;
    incaseFail(year);

    Employee employee(name, SSN, salary, month, year);

    return employee;

}


void EmployeeUI::tryCreateRecord()
{
    try
    {
        system("CLS");
        _service.add_record(create_new_record());
        system("CLS");
        cout << "Record successfully added!" << endl;
    }
    catch (InvalidNameException)
    {
        system ("CLS");
        cout << "Invalid name! Please only enter letters!" << endl << endl;
    }
    catch (InvalidSSNException e)
    {
        system ("CLS");
        cout << e.get_error() << endl << endl;
    }
    catch (InvalidSalaryException)
    {
        system ("CLS");
        cout << "Invalid salary entered!" << endl << endl;
    }
    catch (InvalidMonthException)
    {
        system ("CLS");
        cout << "Invalid Month entered! Please enter only 1 - 12" << endl << endl;
    }
    catch (InvalidYearException e)
    {
        system ("CLS");
        cout << e.get_error() << endl << endl;
    }
}

void EmployeeUI::incaseFail(int& input)
{
    if (cin.fail())
    {
        input = -1;
        cin.clear();
        cin.ignore(100, '\n');
    }
}


void EmployeeUI::get_highest_total_of_year()
{
    try
    {
        int year = get_year_input();
        vector<Employee> highest = _service.highestOfYear(year);

        system("CLS");
        cout << endl;
        cout << "The highest earner(s) of the year " << year << " goes to..." << endl;
        for (unsigned int i = 0 ; i < highest.size() ; i++)
        {
            cout << highest[i].get_name() << " - " << highest[i].get_SSN() << endl;
            cout << "With the total of: " << highest[i].get_salary() << " Kr.!" << endl << endl;
        }
        system("pause");
        system("CLS");

    }
    catch (InvalidYearException e)
    {
        system ("CLS");
        cout << e.get_error() << endl << endl;
    }
    catch (InvalidFileException e)
    {
        system("CLS");
        cout << e.get_error() << endl << endl;
    }


}


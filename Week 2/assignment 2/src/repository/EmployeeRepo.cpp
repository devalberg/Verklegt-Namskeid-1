#include "EmployeeRepo.h"
#include <fstream>
#include <cstdlib>
#include <string>


EmployeeRepo::EmployeeRepo()
{
    //ctor
}

vector<Employee> EmployeeRepo::get_employees()
{
    readDB(false);
    return employees;
}
void EmployeeRepo::writeToDB(const Employee& employee)
{
    ofstream fout;

    readDB(true);

    bool _override = false;

    string SSN = employee.get_SSN();
    int month = employee.get_month();
    int year = employee.get_year();

    unsigned int i = 0;
    if (employees.size() > 0)
    {
        for (; i < employees.size() ; i++)
        {
            if (!SSN.compare(employees[i].get_SSN()) && month == employees[i].get_month() && year == employees[i].get_year())
            {
                _override = true;
                break;
            }
        }
    }

    if (_override)
    {
        employees[i] = employee;
        fout.open("employees.txt");
        if (fout.is_open())
        {
            for (i = 0 ; i < employees.size() ; i++)
            {
                fout << employees[i];
            }
        }
        else
        {
            //TODO: what to do if not opened;
        }

    }
    else
    {
        fout.open("employees.txt", ios::app);
        if (fout.is_open())
        {
            fout << employee;
        }
        else
        {
            //TODO: what to do if not opened;
        }
    }
    fout.close();
}


void EmployeeRepo::readDB(bool writing) throw (InvalidFileException)
{
    ifstream fin;
    employees.clear();

    fin.open("employees.txt");

    if (fin.is_open())
    {
        string name;
        string SSN;
        string salary;
        string month;
        string year;

        while (!fin.eof())
        {
            getline(fin, name, ';');
            getline(fin, SSN, ';');
            getline(fin, salary, ';');
            getline(fin, month, ';');
            getline(fin, year);
            Employee employee(name, SSN, atoi(salary.c_str()), atoi(month.c_str()), atoi(year.c_str()));
            if (fin.eof())
            {
                break;
            }
            employees.push_back(employee);

        }

        fin.close();

    }
    else
    {
        if (!writing)
        {
            throw InvalidFileException();
        }
    }

}

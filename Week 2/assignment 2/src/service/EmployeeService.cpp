#include "EmployeeService.h"

EmployeeService::EmployeeService()
{
    //ctor
}

void EmployeeService::add_record(const Employee& employee) throw (InvalidNameException, InvalidSSNException, InvalidSalaryException, InvalidMonthException, InvalidYearException)
{
    if (validate_new_record(employee))
    {
        _repo.writeToDB(employee);
    }
}

bool EmployeeService::validate_new_record(const Employee& employee)
{

    validate_name(employee.get_name());
    validate_SSN(employee.get_SSN());
    validate_salary(employee.get_salary());
    validate_month(employee.get_month());
    validate_year(employee.get_year());

    return true;
}

bool EmployeeService::validate_name(string name)
{
    for (unsigned int i = 0 ; i < name.size() ; i++)
    {
        if (!isalpha(name[i]) && name[i] !=' ')
        {
            throw InvalidNameException();
        }
    }

    return true;
}

bool EmployeeService::validate_salary(int salary)
{
    if (salary < 0)
    {
        throw InvalidSalaryException();
    }

    return true;
}

bool EmployeeService::validate_month(int month)
{
    if (month < 1 || month > 12)
    {
        throw InvalidMonthException();
    }

    return true;
}

bool EmployeeService::validate_SSN(string SSN)
{
    if (SSN.length() != 10)
    {
        throw InvalidSSNException();
    }

    for (unsigned int i = 0 ; i < SSN.length() ; i++)
    {
        if (!isdigit(SSN[i]))
        {
            throw InvalidSSNException();
        }
    }


    return true;
}

bool EmployeeService::validate_year(int year)
{
    if (year < 1900 || year > 2017)
    {
        throw InvalidYearException();
    }

    return true;
}

vector<Employee> EmployeeService::allSalaryOfSSN (string SSN) throw (InvalidSSNException, InvalidFileException)
{
    validate_SSN(SSN);
    vector<Employee> temp = _repo.get_employees();
    vector<Employee> employee;

    for (unsigned int i = 0 ; i < temp.size() ; i++)
    {
        if (SSN.compare(temp[i].get_SSN()) == 0)
        {
            employee.push_back(temp[i]);
        }
    }

    if (employee.size() == 0)
    {
        throw InvalidSSNException(SSN);
    }

    return employee;
}

Employee EmployeeService::yearSalaryOfSSN (string SSN, int year) throw (InvalidSSNException, InvalidYearException, InvalidFileException)
{
    validate_SSN(SSN);
    validate_year(year);
    vector<Employee> temp = _repo.get_employees();
    int sum = 0;

    bool SSNfound = false;

    string name;

    unsigned int i = 0;
    for (; i < temp.size() ; i++)
    {
        if (!SSN.compare(temp[i].get_SSN()))
        {
            SSNfound = true;
            if (year == temp[i].get_year())
            {
                sum+= temp[i].get_salary();
                name = temp[i].get_name();
            }
        }
    }

    Employee employee(name, SSN, sum, 12, year);  // Just giving name of record, month to 12 just as placeholder, won't be using it

    if (employee.get_salary() == -1 && SSNfound)
    {
        throw InvalidYearException(year);
    }
    else if (employee.get_salary() == -1 && !SSNfound)
    {
        throw InvalidSSNException(SSN);
    }

    return employee;
}

vector<Employee> EmployeeService::highestOfYear(int year) throw (InvalidYearException, InvalidFileException)
{
    validate_year(year);
    vector<Employee> allEmployees = _repo.get_employees();
    vector<Employee> highest;
    vector<Employee> summedEmployees;

    for (unsigned int i = 0 ; i < allEmployees.size() ; i++)
    {
        summedEmployees.push_back(yearSalaryOfSSN(allEmployees[i].get_SSN(), year));
    }

    bool matchExisting;
    highest.push_back(summedEmployees[0]);
    for (unsigned int i = 0 ; i < summedEmployees.size() ; i++)
    {
        matchExisting = false;
        if (summedEmployees[i].get_salary() > highest[0].get_salary())
        {
            highest.clear();
            highest.push_back(summedEmployees[i]);
        }
        else if (summedEmployees[i].get_salary() == highest[0].get_salary())
        {
            for (unsigned int j = 0 ; j < highest.size() ; j++)
            {
                if (! summedEmployees[i].get_SSN().compare(highest[j].get_SSN()) )
                {
                    matchExisting = true;
                    break;
                }
            }

            if (!matchExisting)
            {
                highest.push_back(summedEmployees[i]);
            }
        }
    }

    return highest;
}


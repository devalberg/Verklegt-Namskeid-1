#include "Employee.h"

#include <cstring>

Employee::Employee()
{

}

Employee::Employee(string name, string SSN, int salary, int month, int year)
{
    this->name = name;
    this->SSN = SSN;
    this->salary = salary;
    this->month = month;
    this->year = year;

}

string Employee::get_name() const
{
    return name;
}

string Employee::get_SSN() const
{
    return SSN;
}
int Employee::get_salary() const
{
    return salary;
}
int Employee::get_month() const
{
    return month;
}
int Employee::get_year() const
{
    return year;
}

void Employee::set_salary(int salary)
{
    this->salary = salary;
}

ostream& operator << (ostream& out, const Employee& employee)
{
    out << employee.get_name() << ";" << employee.get_SSN() << ";" << employee.get_salary() << ";" << employee.get_month() << ";" << employee.get_year() << endl;
}


#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;


class Employee
{
    public:
        Employee();
        Employee(string name, string SSN, int salary, int month, int year);
        string get_name() const;
        string get_SSN() const;
        int get_salary() const;
        int get_month() const;
        int get_year() const;
        void set_salary(int salary);
        friend ostream& operator << (ostream& out, const Employee& employee);

    private:
        string name;
        string SSN;
        int salary;
        int month;
        int year;


};

#endif // EMPLOYEE_H

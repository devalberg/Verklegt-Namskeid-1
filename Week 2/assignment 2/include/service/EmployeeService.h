#ifndef EMPLOYEESERVICE_H
#define EMPLOYEESERVICE_H

#include "Employee.h"
#include "EmployeeRepo.h"
#include "InvalidNameException.h"
#include "InvalidSSNException.h"
#include "InvalidSalaryException.h"
#include "InvalidMonthException.h"
#include "InvalidYearException.h"

#include <vector>
#include <string>

class EmployeeService
{
public:
    EmployeeService();
    void add_record(const Employee& employee) throw (InvalidNameException, InvalidSSNException, InvalidSalaryException, InvalidMonthException, InvalidYearException);
    vector<Employee> allSalaryOfSSN(string SSN) throw (InvalidSSNException, InvalidFileException);
    Employee yearSalaryOfSSN(string SSN, int year) throw (InvalidSSNException, InvalidYearException, InvalidFileException);
    vector<Employee> highestOfYear(int year) throw (InvalidYearException, InvalidFileException);

private:
    EmployeeRepo _repo;
    bool validate_new_record(const Employee& employee);
    bool validate_name(string name);
    bool validate_SSN(string SSN);
    bool validate_salary(int month);
    bool validate_month(int month);
    bool validate_year(int year);

};

#endif // EMPLOYEESERVICE_H

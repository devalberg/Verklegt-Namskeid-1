#ifndef EMPLOYEEREPO_H
#define EMPLOYEEREPO_H

#include "Employee.h"
#include <vector>
#include "InvalidFileException.h"

class EmployeeRepo
{
    public:
        EmployeeRepo();
        void writeToDB(const Employee& employee);
        vector<Employee> get_employees();

    private:
        void readDB(bool writing) throw (InvalidFileException);
        vector<Employee> employees;
};

#endif // EMPLOYEEREPO_H

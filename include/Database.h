#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include "Employee.h"

namespace Records
{

    class Database
    {
    public:
        Employee &addEmployee(const std::string &firstName, const std::string &lastName);
        Employee &getEmployee(int employeeNumber);
        Employee &getEmployee(const std::string &firstName, const std::string &lastName);

        void displayAll() const;
        void displayCurrent() const;
        void displayFormer() const;

    private:
        std::vector<Employee> m_employees;
        int m_nextEmployeeNumber{1'000};
    };
}

#endif // DATABASE_H
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

namespace Records
{

    const int DefaultRaiseAndDemeritAmount{1'000};

    class Employee
    {
    public:
        Employee(const std::string &firstName, const std::string &lastName);

        void promote(int raiseAmount = DefaultRaiseAndDemeritAmount);
        void demote(int demeritAmount = DefaultRaiseAndDemeritAmount);
        void hire();          // Hires or rehires the employee
        void fire();          // Dismisses the employee
        void display() const; // Outputs employee info to console

        // Getters and setters
        void setFirstName(const std::string &firstName);
        const std::string &getFirstName() const;

        void setLastName(const std::string &lastName);
        const std::string &getLastName() const;

        void setEmployeeNumber(int employeeNumber);
        int getEmployeeNumber() const;

        void setSalary(int newSalary);
        int getSalary() const;

        bool isHired() const;

    private:
        std::string m_firstName;
        std::string m_lastName;
        int m_employeeNumber{-1};
        int m_salary{30'000}; // Using global default
        bool m_hired{false};
    };
}

#endif // EMPLOYEE_H
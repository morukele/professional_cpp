#include <iostream>
#include <stdexcept>
#include <exception>
#include <format>
#include <string>
#include "include/Employee.h"
#include "include/Database.h"

using namespace Records;

int displayMenu();
void doHire(Database &db);
void doFire(Database &db);
void doPromote(Database &db);

int main()
{
    Database employeeDB;
    bool done{false};
    while (!done)
    {
        int selection{displayMenu()};
        switch (selection)
        {
        case 0:
            done = true;
            break;
        case 1:
            doHire(employeeDB);
            break;
        case 2:
            doFire(employeeDB);
            break;
        case 3:
            doPromote(employeeDB);
            break;
        case 4:
            employeeDB.displayAll();
            break;
        case 5:
            employeeDB.displayCurrent();
            break;
        case 6:
            employeeDB.displayFormer();
            break;
        default:
            std::cerr << "Unknown command." << std::endl;
            break;
        }
    }
}

int displayMenu()
{
    int selection;
    std::cout << std::endl;
    std::cout << "Employee Database" << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "1) Hire a new employee" << std::endl;
    std::cout << "2) Fire an employee" << std::endl;
    std::cout << "3) Promote an employee" << std::endl;
    std::cout << "4) List all employees" << std::endl;
    std::cout << "5) List all current employees" << std::endl;
    std::cout << "6) List all former employees" << std::endl;
    std::cout << "0) Quit" << std::endl;
    std::cout << std::endl;
    std::cout << "--->";
    std::cin >> selection;
    return selection;
}

void doHire(Database &db)
{
    std::string firstName;
    std::string lastName;

    std::cout << "First name? ";
    std::cin >> firstName;

    std::cout << "Last name? ";
    std::cin >> lastName;

    auto &employee{db.addEmployee(firstName, lastName)};
    std::cout << std::format("Hire employee {} {} with employee number {}.", firstName, lastName, employee.getEmployeeNumber())
              << std::endl;
}

void doFire(Database &db)
{
    int employeeNumber;
    std::cout << "Employee number? ";
    std::cin >> employeeNumber;

    try
    {
        auto &emp{db.getEmployee(employeeNumber)};
        emp.fire();
        std::cout << std::format("Employee {} terminated.", employeeNumber) << std::endl;
    }
    catch (const std::logic_error &e)
    {
        std::cerr << std::format("Unable to terminate employee: {}", e.what()) << std::endl;
    }
}

void doPromote(Database &db)
{
    int employeeNumber;
    std::cout << "Employee number? ";
    std::cin >> employeeNumber;

    int raiseAmount;
    std::cout << "How much of a raise? ";
    std::cin >> raiseAmount;

    try
    {
        auto &emp{db.getEmployee(employeeNumber)};
        emp.promote(raiseAmount);
    }
    catch (const std::exception &e)
    {
        std::cerr << std::format("Unable to promote employee: {}", e.what()) << std::endl;
    }
}
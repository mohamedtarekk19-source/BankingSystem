#include "AdminManager.h"
#include "FileManager.h"
#include "Employee.h"
#include <vector>
#include "EmployeeManager.h"
#include <iostream>
#include <limits>
using namespace std;

void AdminManager::printAdminMenu() {
    EmployeeManager::printEmployeeMenu();
    cout << "6. Add Employee\n";
    cout << "7. Search Employee\n";
    cout << "8. Edit Employee\n";
    cout << "9. List Employees\n";
    cout << "10. Logout\n";
}

Admin* AdminManager::login(int id, string password) {
    FileManager fm;                  // كل مرة جديد
    vector<Admin> admins = fm.getAllAdmins();  // اقرأ الملف الآن


    for (auto& a : admins) {
        cout << "ID: " << a.getId() << " PASS: " << a.getPassword() << endl;

        if (a.getId() == id && a.getPassword() == password) {
            return &a;
        }
    }
    return nullptr;
}

bool AdminManager::adminOptions(Admin* admin) {
    if (!admin) return false;

    int choice;
    printAdminMenu();

    cout << "Enter Choice: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {
    case 1:
        EmployeeManager::newClient(admin);
        break;
    case 2:
        EmployeeManager::listAllClients(admin);
        break;
    case 3:
        EmployeeManager::searchForClient(admin);
        break;
    case 4:
        EmployeeManager::editClientInfo(admin);
        break;
    case 5:
        return false;

    case 6: {
        int id;
        string name, password;
        double salary;

        cout << "Enter ID: ";
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Password: ";
        getline(cin, password);

        cout << "Enter Salary: ";
        cin >> salary;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        Employee e(id, name, password, salary);
        admin->addEmployee(e);
        break;
    }

    case 7: {
        int id;
        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        Employee* emp = admin->searchEmployee(id);
        if (!emp)
            cout << "Employee not found\n";
        else
            emp->display();
        break;
    }

    case 8: {
        int id;
        string name, password;
        double salary;

        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter New Name: ";
        getline(cin, name);

        cout << "Enter New Password: ";
        getline(cin, password);

        cout << "Enter New Salary: ";
        cin >> salary;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        admin->editEmployee(id, name, password, salary);

        break;
    }

    case 9:
        admin->listEmployees();
        break;

    case 10:
        return false;

    default:
        cout << "Invalid choice\n";
    }

    return true;
}
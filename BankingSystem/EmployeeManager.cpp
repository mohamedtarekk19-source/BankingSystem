#include "EmployeeManager.h"
#include "FileManager.h"
#include "Client.h"
#include <vector>
#include <limits>
#include <iostream>
using namespace std;

void EmployeeManager::printEmployeeMenu() {
    cout << "\nEmployee Menu\n";
    cout << "1. Add New Client\n";
    cout << "2. List All Clients\n";
    cout << "3. Search For Client\n";
    cout << "4. Edit Client\n";
    cout << "5. Logout\n";
}

void EmployeeManager::newClient(Employee* employee) {
    if (!employee) return;

    int id;
    string name, password;
    double balance;

    cout << "Enter Client ID: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Password: ";
    getline(cin, password);

    cout << "Enter Balance: ";
    cin >> balance;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Client c(id, name, password, balance);
    employee->addClient(c);
}

void EmployeeManager::listAllClients(Employee* employee) {
    if (!employee) return;
    employee->listClients();
}

void EmployeeManager::searchForClient(Employee* employee) {
    if (!employee) return;

    int id;
    cout << "Enter Client ID: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Client* client = employee->SearchClient(id);
    if (!client) {
        cout << "Client not found\n";
    }
    else {
        client->display();
    }
}

void EmployeeManager::editClientInfo(Employee* employee) {
    if (!employee) return;

    int id;
    string name, password;
    double balance;

    cout << "Enter Client ID: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter New Name: ";
    getline(cin, name);

    cout << "Enter New Password: ";
    getline(cin, password);

    cout << "Enter New Balance: ";
    cin >> balance;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // تحديث العميل في الذاكرة
    employee->editClient(id, name, password, balance);

    // تحديث Clients.txt مباشرة بعد التعديل
    FileManager fm;
    vector<Client> allClients = fm.getAllClients();
    for (auto& c : allClients) {
        if (c.getId() == id) {
            c.setName(name);
            c.setPassword(password);
            c.setBalance(balance);
            break;
        }
    }
    fm.removeAllClients();
    for (auto& c : allClients) {
        fm.addClient(c);
    }

    cout << "Client updated successfully.\n";
}

Employee* EmployeeManager::login(int id, string password) {
    static FileManager fm;
    static vector<Employee> employees = fm.getAllEmployees();

    for (auto& e : employees) {
        if (e.getId() == id && e.getPassword() == password) {
            return &e; // pointer على النسخة في الذاكرة
        }
    }
    return nullptr;
}

bool EmployeeManager::employeeOptions(Employee* employee) {
    if (!employee) return false;

    int choice;
    printEmployeeMenu();

    cout << "Enter Choice: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {
    case 1:
        newClient(employee);
        break;
    case 2:
        listAllClients(employee);
        break;
    case 3:
        searchForClient(employee);
        break;
    case 4:
        editClientInfo(employee);
        break;
    case 5:
        return false;
    default:
        cout << "Invalid Choice\n";
    }

    return true;
}
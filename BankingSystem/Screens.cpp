#include "Screens.h"
#include "Screens.h"
#include "ClientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include <limits>
#include <string>

void Screens::bankName() {
    cout << "====================================\n";
    cout << "   Welcome to Route Academy Bank \n";
    cout << "====================================\n";
}

void Screens::welcome() {
    cout << "\nWelcome! Please choose an option:\n";
    cout << "1. Login\n";
    cout << "2. Exit\n";
}

void Screens::loginOptions() {
    cout << "\nLogin As:\n";
    cout << "1. Client\n";
    cout << "2. Employee\n";
    cout << "3. Admin\n";
}

int Screens::loginAs() {
    int choice;
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

void Screens::invalid(int c) {
    cout << "Invalid choice: " << c << "\nPlease try again.\n";
}

void Screens::logout() {
    cout << "Logging out...\n";
}

void Screens::loginScreen(int c) {
    int id;
    string password;

    cout << "\nEnter ID: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Password: ";
    getline(cin, password);

    if (c == 1) { // Client
        Client* client = ClientManager::login(id, password);
        if (!client) {
            cout << "Login failed!\n";
            return;
        }
        cout << "Login successful!\n";
        while (ClientManager::clientOptions(client));
    }
    else if (c == 2) { // Employee
        Employee* emp = EmployeeManager::login(id, password);
        if (!emp) {
            cout << "Login failed!\n";
            return;
        }
        cout << "Login successful!\n";
        while (EmployeeManager::employeeOptions(emp));
    }
    else if (c == 3) { // Admin
        Admin* admin = AdminManager::login(id, password);
        if (!admin) {
            cout << "Login failed!\n";
            return;
        }
        cout << "Login successful!\n";
        while (AdminManager::adminOptions(admin));
    }
}

void Screens::runApp() {
    bankName();
    while (true) {
        welcome();
        int option;
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (option == 2) {
            cout << "Exiting app. Goodbye!\n";
            break;
        }
        else if (option == 1) {
            loginOptions();
            int loginType = loginAs();
            if (loginType < 1 || loginType > 3) {
                invalid(loginType);
                continue;
            }
            loginScreen(loginType);
        }
        else {
            invalid(option);
        }
    }
}
#include <iostream>
#include <string>
#include "Person.h"
#include "Employee.h"
#include "Client.h"

using namespace std;

int main() {
    int choice;
    cout << "================== Welcome To +Route+ Banking System ==================\n";
    cout << "Select User Type:\n";
    cout << "1 - Client\n";
    cout << "2 - Employee\n";
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore(); 

    if (choice == 1) {
        // ---------- Client ----------
        int id;
        string name, password;
        double balance;

        cout << "Enter Your Name: ";
        getline(cin, name);

        cout << "Enter Your ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Your Password: ";
        getline(cin, password);

        cout << "Enter Your Balance: ";
        cin >> balance;
        cin.ignore();

        try {
            Client c1(id, name, password, balance);
            c1.display();

            // مثال على العمليات
            Client c2; // second client for transfer
            c1.deposit(10000);
            c1.withdraw(5000);
            c1.transferTo(2000, c2);

            cout << "c1 Balance: " << c1.checkBalance() << endl;
            cout << "c2 Balance: " << c2.checkBalance() << endl;

        }
        catch (const char* msg) {
            cout << "Error: " << msg << endl;
        }

    }
    else if (choice == 2) {
        // ---------- Employee ----------
        int id;
        string name, password;
        double salary;

        cout << "Enter Employee Name: ";
        getline(cin, name);

        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Employee Password: ";
        getline(cin, password);

        cout << "Enter Employee Salary: ";
        cin >> salary;
        cin.ignore();

        try {
            Employee emp(id, name, password, salary);
            emp.display();

           
        }
        catch (const char* msg) {
            cout << "Error: " << msg << endl;
        }

    }
    else {
        cout << "Invalid choice! Exiting program.\n";
    }

    return 0;
}
// hn3ml Login method for admin with authentication user and password (will be fixed ) 
// 3lshan lma ndkhol 3la employee ykun 3n tre2 admin ,, 
// lma n3ml l userinterface fl main mhtaga ttzbt 
#include <iostream>
#include <vector>
#include <limits>
#include "ClientManager.h"
#include "Client.h"
#include "Person.h"
#include "FileManager.h"
#include"Validation.h"
#include"Employee.h"
using namespace std;

void ClientManager::printClientMenu() {
    cout << "\nClient Menu\n";
    cout << "1. View Balance\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Update Password\n";
    cout << "5. Logout\n";
}

void ClientManager::updatePassword(Person* person) {

    if (!person) {
        cout << "No client logged in!\n";
        return;
    }

    string newPassword;
    cout << "Enter New Password:\n";
    getline(cin, newPassword);

    if (!Validation::checkPassword(newPassword)) {
        cout << "Invalid password! Password not updated.\n";
        return;
    }

    person->setPassword(newPassword);
    cout << "Password Updated Successfully\n";

    Client* client = dynamic_cast<Client*>(person);

    if (client) {
        Employee e1;
        e1.editClient(
            client->getId(),
            client->getName(),
            client->getPassword(),
            client->checkBalance()
        );
    }
}

Client* ClientManager::login(int id, string password) {
    static FileManager fm;
    static vector<Client> allClients = fm.getAllClients();

    for (auto& c : allClients) {
        if (c.getId() == id && c.getPassword() == password) {
            return &c;
        }
    }
    return nullptr;
}

bool ClientManager::clientOptions(Client* client) {
    if (!client) {
        cout << "You must login first!\n";
        return false;
    }

    int choice;
    printClientMenu();
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    FileManager fm;
    vector<Client> allClients = fm.getAllClients(); // نسخة من كل العملاء

    switch (choice) {
    case 1:
        cout << "Balance: " << client->checkBalance() << endl;
        break;

    case 2: {
        double amount;
        cout << "Enter amount: ";
        cin >> amount;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        client->deposit(amount);

        cout << "Deposit Successful. New Balance: "
            << client->checkBalance() << endl;

        Employee e1;
        e1.editClient(
            client->getId(),
            client->getName(),
            client->getPassword(),
            client->checkBalance()
        );

        break;
    }

    case 3: {
        double amount;
        cout << "Enter amount: ";
        cin >> amount;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        client->withdraw(amount);
        cout << "Withdraw Successful. New Balance: " << client->checkBalance() << endl;

        Employee e1;
        e1.editClient(
            client->getId(),
            client->getName(),
            client->getPassword(),
            client->checkBalance()
        );

        break;
    }

    case 4:
        updatePassword(client);
        break;

    case 5:
        return false;

    default:
        cout << "Invalid choice\n";
    }

    return true;
}
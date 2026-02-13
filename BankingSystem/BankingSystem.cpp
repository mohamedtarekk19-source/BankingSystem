#include <iostream>
#include <string>
#include<sstream>
#include<fstream>
#include "Person.h"
#include "Employee.h"
#include "Client.h"
#include "Admin.h"
#include"Validation.h"

using namespace std;

int main() {
    Client c1(50, "Mohamed", "Password156", 3000);
  
    fstream f1("Clients.txt", ios::out);
    f1 << c1.getId() << "-"
        << c1.getName() << "-"
        << c1.getPassword() << "-"
        << c1.checkBalance() << endl;
    f1.close();

    return 0;
}

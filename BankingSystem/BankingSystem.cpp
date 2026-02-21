#include <iostream>
#include <string>
#include<sstream>
#include<fstream>
#include "Person.h"
#include "Employee.h"
#include "Client.h"
#include "Admin.h"
#include"Validation.h"
#include<vector>
#include"FilesHelper.h"
#include<fstream>
#include"FileManager.h"
using namespace std;
const string Clients = "Clients.txt";
const string ClientsId = "ClientsLastId.txt";
const string Employees = "Employees.txt";
const string EmployeesId = "EmployeesLastId.txt";
const string Admins = "Admins.txt";
const string AdminsId = "AdminsLastId.txt";
int main() {
    Client c(50, "Mohamed", "Password", 20000);
    FileManager f;
    f.removeAllClients();
   
    
    return 0;
}

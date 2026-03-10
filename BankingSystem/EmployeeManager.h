#pragma once

#include <iostream>
#include "Employee.h"

using namespace std;

class EmployeeManager {
public:

    static void printEmployeeMenu();

    static void newClient(Employee* employee);

    static void listAllClients(Employee* employee);

    static void searchForClient(Employee* employee);

    static void editClientInfo(Employee* employee);

    static Employee* login(int id, string password);

    static bool employeeOptions(Employee* employee);

};
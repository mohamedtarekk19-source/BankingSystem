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

int main() {

    Employee e1(100, "MohamedEldeeb", "Password1789", 5000);
    Admin a;
    FileManager fm;
    //fm.removeAllEmployees();
    //a.addEmployee(e1);
    //a.searchEmployee(105);
    a.listEmployees();
    return 0;
}


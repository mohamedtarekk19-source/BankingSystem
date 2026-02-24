#pragma once
#include "Employee.h"

class Admin :public Employee
{
public:
	Admin();
	Admin(int id, string name, string password, double salary);
	void addEmployee(Employee& employee);
	Employee* searchEmployee(int id);
	void editEmployee(int id, string name, string password, double salary);
	void listEmployees();

};


#include "Admin.h"


Admin::Admin() : Employee(){}
Admin::Admin(int id, string name, string password, double salary) : Employee(id, name, password,salary) {};
void Admin::addEmployee(Employee& employee) {
	FileManager fm;
	fm.addEmployee(employee);
	cout << "Employee Added Successfully \n";

}
Employee* Admin::searchEmployee(int id) {
	FileManager fm;
	bool found = false;
	vector<Employee> allEmployees = fm.getAllEmployees();
	for (auto& element : allEmployees) {
		if (element.getId() == id) {
			found = true;
			cout << "Employee with id :" << id << " IS FOUND \n";
			return &element;
		}
	}
	cout << " Employee isnot Found \n";
	return nullptr;
}
void Admin::editEmployee(int id, string name, string password, double salary) {
	FileManager fm;
	vector<Employee> allEmployees = fm.getAllEmployees();
	bool found = false;

	for (auto& e : allEmployees) {
		if (e.getId() == id) {
			e.setName(name);
			e.setPassword(password);
			e.setSalary(salary);
			found = true;
			break;
		}
		
	}
	if (!found) {
		cout << "Employee isnot Found \n";
		return;
	}
	if (rename("Employees.txt", "EmployeesBackup.txt") != 0) {
		cout << "Error creating backup!\n";
		return;
	}
	for (auto& e : allEmployees) {
		fm.addEmployee(e);
	}
	remove("EmployeesBackup.txt");
	cout << "Employee updated successfully.\n";
}
void Admin::listEmployees() {
	FileManager fm;
	vector<Employee> allEmployees = fm.getAllEmployees();
	for (auto& e : allEmployees) {
		e.display();
	}
}
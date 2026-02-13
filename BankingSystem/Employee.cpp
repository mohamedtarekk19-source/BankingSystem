#include "Employee.h"
#include <iostream>
#include <string>
#include <cctype>	
#include"Person.h"

using namespace std;
Employee::Employee() : salary(0.0) {}
Employee::Employee(int id, string name, string password, double salary) : Person(id, name, password)  {
	setSalary(salary);
};
void Employee::setSalary(double salary) {
	if (salary >= 5000) {
		this->salary = salary;
	}
	else  {
		cout << "Minimum Salary Should be 5000 \n";
	
	}
}
double Employee::getSalary() {
	return salary;
}
void Employee::display() {
	cout << "ID : " << id << "|"
		<< " Name : " << name << "|"
		<< " PassWord : " << password << "|"
		<< " Salary : " << salary;
	cout << endl;
}

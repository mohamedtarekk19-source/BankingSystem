#pragma once
#include"Person.h"


class Employee :public Person
{
protected:
	double salary;
public:
	Employee();
	Employee(int id, string name, string password, double salary);
	void setSalary(double salary);
	double getSalary();
	void display() override;
	~Employee() = default;
};
	

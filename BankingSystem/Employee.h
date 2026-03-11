#pragma once
#include"Person.h"
#include"Client.h"
#include"FileManager.h"
#include <iostream>



class Employee :public Person
{
protected:
	double salary;
	
public:
	Employee();
	Employee(int id, string name, string password, double salary);
	void setSalary(double salary);
	double getSalary() const;
	void display() override;
	~Employee() = default;
	void addClient(const Client& obj);
	Client* SearchClient(int id);
	void listClients();
	void editClient(int id, const string& name, const string &password, double balance);
};
	

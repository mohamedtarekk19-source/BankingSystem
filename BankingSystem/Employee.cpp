#include "Employee.h"
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
double Employee::getSalary()const {
	return salary;
}
void Employee::display() {
	cout << " ID : " << id << " -"
		<< " Name : " << name << " -"
		<< " PassWord : " << password << " -"
		<< " Salary : " << salary;
	cout << endl;
}
void Employee::addClient(const Client& obj) {
	FileManager File_Manager;
	File_Manager.addClient(obj);
	cout << "Client Added Successfully \n";

}
Client* Employee::SearchClient(int id) {
	FileManager File_Manager;
	bool found = false;
	vector<Client> Clients = File_Manager.getAllClients();
	for (auto& element : Clients) {
		if (element.getId() == id) {
			 found = true;
			 cout << "Client with id :" << id << " IS FOUND \n";
			 return &element;
		}
	}
	cout << " Client isnot Found \n";
	return nullptr;
}
void Employee::listClients() {

	FileManager File_Manager;
	vector<Client> allClients = File_Manager.getAllClients();
	for (auto& element : allClients) {
		element.display();
	}
}
void Employee::editClient(int id, string name, string password, double balance) {

	FileManager fileManager;
	vector<Client> allClients = fileManager.getAllClients();

	bool found = false;

	for (auto& c : allClients) {
		if (c.getId() == id) {
			c.setName(name);
			c.setPassword(password);
			c.setBalance(balance);
			found = true;
			break;
		}
	}

	if (!found) {
		cout << "Client not found!\n";
		return;
	}


	if (rename("Clients.txt", "ClientsBackup.txt") != 0) {
		cout << "Error creating backup!\n";
		return;
	}


	
	for (auto& c : allClients) {
		fileManager.addClient(c);
	}

	
	remove("ClientsBackup.txt");

	cout << "Client updated successfully.\n";
}

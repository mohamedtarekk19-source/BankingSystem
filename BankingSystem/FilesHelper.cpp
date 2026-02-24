#include "FilesHelper.h"
#include <fstream>
#include<sstream>
#include<iostream>
#include"Parser.h"
using namespace std;

const string Clients = "Clients.txt";
const string ClientsId = "ClientsLastId.txt";
const string Employees = "Employees.txt";
const string EmployeesId = "EmployeesLastId.txt";
const string Admins = "Admins.txt";
const string AdminsId = "AdminsLastId.txt";

void FilesHelper::saveLast(const string& fileName, int id) {
	ofstream file(fileName);
	if (!file.is_open()) {
		cerr << "Error Opening file : " << fileName << endl;
		return;
	}
	file << id;
	file.close();
}
int FilesHelper::getLast(const string& fileName) {
	ifstream file(fileName);
	int id = 0 ;
	if (!file.is_open()) {
		cerr << "Error Opening file : " << fileName << endl;
		return 0;
	}
	file >> id;
	file.close();
	return id;
}

void FilesHelper::saveClient(const string& fileName, const string& lastIdFile, const Client& c) {
	ofstream file(fileName , ios::app);
	if (!file.is_open()) {
		cerr << "error opening file " << Clients << endl;
		return;
	}
	file << c.getId() << "-"
		<< c.getName() << "-"
		<< c.getPassword() << "-"
		<< c.checkBalance() << endl;
	file.close();
	saveLast(lastIdFile, c.getId());
}
void FilesHelper::saveEmployee(const string& fileName, const string& lastIdFile, const Employee& e){
	ofstream file(fileName, ios::app);
	if (!file.is_open()) {
		cerr << "error opening file " << Employees << endl;
		return;
	}
	file << e.getId() << "-"
		<< e.getName() << "-"
		<< e.getPassword() << "-"
		<< e.getSalary() << endl;
	file.close();
	saveLast(lastIdFile, e.getId());

	}
vector<Client> FilesHelper::getClients() {
	vector<Client> AllClients;
	ifstream file(Clients);
	string line;
	if (!file.is_open()) {
		cerr << "error opening file " << Clients << endl;
		return vector<Client>();
	}
	while (getline(file, line)) {
		Client c = Parser::parseToClient(line);
		AllClients.push_back(c);
	}
	file.close();
	return AllClients;

}
vector<Employee> FilesHelper::getEmployees() {
	vector<Employee> AllEmployees;
	ifstream file(Employees);
	string line;
	if (!file.is_open()) {
		cerr << "error opening file " << Employees << endl;
		return vector<Employee>();
	}
	while (getline(file, line)) {
		Employee e = Parser::parseToEmployee(line);
		AllEmployees.push_back(e);
	}
	file.close();
	return AllEmployees;
}
vector<Admin> FilesHelper::getAdmins() {
	vector<Admin> AllAdmins;
	ifstream file(Admins);
	string line;
	if (!file.is_open()) {
		cerr << "error opening file " << Admins << endl;
		return vector<Admin>();
	}
	while (getline(file, line)) {
		Admin a = Parser::parseToAdmin(line);
		AllAdmins.push_back(a);

	}
	file.close();
	return AllAdmins;
 }
void FilesHelper::clearFile(const string& fileName, const string& lastIdFile) {
	ofstream file(fileName,ios::trunc);
	if (!file.is_open()) {
		cerr << "error opening file " << fileName << endl;
		return;
	}
	file.close();  
	ofstream idfile(lastIdFile);
	if (!idfile.is_open()) {
		cerr << "error opening file " << fileName << endl;
		return;
	}
	idfile << 0;
	idfile.close();
	
 }
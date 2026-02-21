#include "FileManager.h"
#include"FilesHelper.h"
const string Clients = "Clients.txt";
const string ClientsId = "ClientsLastId.txt";
const string Employees = "Employees.txt";
const string EmployeesId = "EmployeesLastId.txt";
const string Admins = "Admins.txt";
const string AdminsId = "AdminsLastId.txt";


void FileManager::addClient(const Client& obj) {
	FilesHelper::saveClient(Clients, ClientsId, obj);
}
void FileManager::addEmployee(const Employee& obj) {
	FilesHelper::saveEmployee(Employees, EmployeesId, obj);
}
void FileManager::addAdmin(const Admin& obj) {
	FilesHelper::saveEmployee(Admins, AdminsId, obj);
}
vector<Client> FileManager::getAllClients() {
	return FilesHelper::getClients();
}
vector<Employee> FileManager::getAllEmployees() {
	return FilesHelper::getEmployees();
}
vector<Admin>FileManager::getAllAdmins() {
	return FilesHelper::getAdmins();
}
void FileManager::removeAllClients() {
	FilesHelper::clearFile(Clients, ClientsId);
}
void FileManager::removeAllEmployees() {
	FilesHelper::clearFile(Employees, EmployeesId);
}
void FileManager::removeAllAdmins() {
	FilesHelper::clearFile(Admins, AdminsId);
}
#pragma once
#include<fstream>
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
#include<string>
#include<iostream>
#include<vector>
using namespace std;
class FilesHelper {
public:
	static void saveLast(const string&fileName, int id);
	static int getLast(const string& fileName);
	static void saveClient(const string& fileName, const string& lastIdFile, const Client& c);
	static void saveEmployee(const string&  fileName,const string& lastIdFile,const Employee& e);
	static vector<Client> getClients();
	static vector<Employee> getEmployees();
	static vector<Admin> getAdmins();
	static void clearFile(const string& fileName, const string& lastIdFile);

};
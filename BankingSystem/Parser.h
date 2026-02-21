#pragma once
#include<vector>
#include<string>
#include<sstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"


using namespace std;

class Parser
{  
public:
	static vector<string> Split(string line) {
		vector<string> result; 
		stringstream ss(line); 
		string Readable;						  
		while (getline(ss, Readable, '-')) {	  
			result.push_back(Readable);			  
			
		}
		return result;
	} 
	static Client parseToClient(string line) {// 0      1       2        3
		vector<string> Parts = Split(line); /// (1000 mohaemd password 5000 )
		int id = stoi(Parts[0]); 
		string name = Parts[1]; 
		string password = Parts[2]; 
		double balance = stod(Parts[3]); 
		Client c(id, name, password, balance);
		return c; 
	}
	static Employee parseToEmployee(string line) {
		vector<string> Parts = Split(line);
		int id = stoi(Parts[0]);
		string name = Parts[1];
		string password = Parts[2];
		double salary = stod(Parts[3]);
		Employee e (id, name, password, salary);
		return e;
	}
	static Admin parseToAdmin(string line) {
		vector<string> Parts = Split(line);
		int id = stoi(Parts[0]);
		string name = Parts[1];
		string password = Parts[2];
		double salary = stod(Parts[3]);
		Admin a (id, name, password, salary);
		return a ;
	}
};


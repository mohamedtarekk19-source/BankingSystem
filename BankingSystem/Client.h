#pragma once
#include <iostream>
#include <string>
#include <cctype>	
#include"Person.h"
class Client :public Person
{
protected:
	double balance;
public:
	Client();
	Client(int id, string name, string password, double balance);
	void setBalance(double balance);
	double checkBalance();
	void display() override;
	void deposit(double amount);
	void withdraw(double amount);
	void transferTo(double amount, Client& R);

};


#include "Client.h"
Client::Client() : balance (0.0) {};
Client::Client(int id, string name, string password, double balance) : Person(id, name, password)  {
	setBalance(balance);
}
void Client:: setBalance(double balance) {
	if (balance >= 1500) {
		this->balance = balance;
	}
	else {
		throw "Minimum Balance Should be 1500 ";
	}
		
}
double Client::checkBalance() {
	return balance;
}
void Client::display() {
	cout << "ID : " << id <<"||"
		<< " Name : " << name << "||"
		<< " Balance : " << balance;
	cout << endl;
}
void Client::deposit(double amount) {
	balance += amount;
}
void Client::withdraw(double amount) {
	if (balance >= amount) {
		balance -= amount;
	}
	else {
		throw " Amount Can't Exceed The Balance";
	}
}
void Client::transferTo(double amount , Client &R) {
	if (amount <= balance) {
		balance -= amount;
		R.balance += amount;
	}
	else {
		throw "Amount Exceeds Balance ";
	}
	
}
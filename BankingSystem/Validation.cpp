#include <iostream>
#include <string>
#include <cctype>	
#include"Validation.h"
using namespace std;



	 bool Validation::checkName(string s) {
		if (s.size() >= 3 && s.size() <= 20) {
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == ' ') {
					continue;
				}
				if (!isalpha(s[i])) {
					
					return false;
				}
			}
			return true;
		}
		else {
			return false;
		}

		
	}

	 bool Validation::checkPassword(string p) {
		 if (p.size() >= 8 && p.size() <= 20) {
			 for (int i = 0; i < p.size(); i++) {
				 if (p[i] == ' ') {
					 return false;
				 }
			 }
			 return true;
		 }
		 else {
			 return false;
		 }
	
	 }
	 string Validation::enterName() {
		 string name;
		 cout << "Please Enter Your Name \n";
		 cin >> name;
		 while (!checkName(name)) {
			 cout << " Invalid Name !\n";
			 cout << " Name must be 3 to 20 Alphabetic Characters . \n ";
			 cout << "Enter your Name : \n";
			 cin >> name;
		 }
		 return name;
	 }
	 string Validation::enterPassword() {
		 string password;
		 cout << "Please Enter You Password : \n";
			 cin >> password;
			 while (!checkPassword(password)) {
				 cout << " Invalid Password !\n";
				 cout << " Password Must Be 8 to 20 Alphanumeric Characters And don't Contain any Spaces . \n ";
				 cout << "Enter your Password : \n";
				 cin >> password;
			 }
			 return password;
	 }

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
		 return false;
	 }

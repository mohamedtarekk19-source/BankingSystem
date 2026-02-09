#include "Person.h"
#include "Validation.h"
#include <iostream>
#include <string>

using namespace std;

Person::Person() {
}

Person::Person(int id, string name, string password)
{
    this->id = id;
    setName(name);
    setPassword(password);
}
void Person::setId(int id) {
    this->id = id;
}

void Person::setName(string name) {
    if (Validation::checkName(name)) {
        this->name = name;
    }
    else {
       throw "Invalid name!\n";
    }
}

void Person::setPassword(string password) {
    if (Validation::checkPassword(password)) {
        this->password = password;
    }
    else {
        throw "Invalid password!\n";
    }
}

int Person::getId() const {
    return id;
}

string Person::getName() const {
    return name;
}

string Person::getPassword() const {
    return password;
}

Person::~Person() {
}

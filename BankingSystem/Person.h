#pragma once
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int id;
    string password;

public:
    Person();
    Person(int id, string name, string password);
    void setName(string name);
    void setId(int id);
    void setPassword(string password);

    string getName()const;
    int getId()const;
    string getPassword()const;

    virtual void display() = 0;

    virtual ~Person();
};



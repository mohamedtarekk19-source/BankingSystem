#pragma once
#include <vector>

class Client;
class Employee;
class Admin;

class DataSourceInterface {
public:

    virtual void addClient(const Client& obj) = 0;
    virtual void addEmployee(const Employee& obj) = 0;
    virtual void addAdmin(const Admin& obj) = 0;

    virtual std::vector<Client> getAllClients() = 0;
    virtual std::vector<Employee> getAllEmployees() = 0;
    virtual std::vector<Admin> getAllAdmins() = 0;

    virtual void removeAllClients() = 0;
    virtual void removeAllEmployees() = 0;
    virtual void removeAllAdmins() = 0;

    virtual ~DataSourceInterface() = default;
};
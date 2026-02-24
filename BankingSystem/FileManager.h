#pragma once
#include "DataSourceInterface.h"
#include <vector>

class Client;
class Employee;
class Admin;

class FileManager : public DataSourceInterface
{
public:
    void addClient(const Client& obj) override;
    void addEmployee(const Employee& obj) override;
    void addAdmin(const Admin& obj) override;

    std::vector<Client> getAllClients() override;
    std::vector<Employee> getAllEmployees() override;
    std::vector<Admin> getAllAdmins() override;

    void removeAllClients() override;
    void removeAllEmployees() override;
    void removeAllAdmins() override;
};
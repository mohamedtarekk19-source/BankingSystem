#pragma once
#include"DataSourceInterface.h"
#include"FilesHelper.h"
#include<vector>;
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
class FileManager : public DataSourceInterface
{
public:
    void addClient (const Client& obj)override;
    void addEmployee (const Employee& obj)override;
    void addAdmin (const Admin& obj)override;

    // Get All
    vector<Client> getAllClients()override;
    vector<Employee> getAllEmployees()override;
    vector<Admin> getAllAdmins()override;

    // Remove All
    void removeAllClients() override;
    void removeAllEmployees() override;
    void removeAllAdmins() override;

};


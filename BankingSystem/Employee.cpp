#include "Employee.h"
#include <string>
#include <cctype>	
#include"Person.h"


using namespace std;
Employee::Employee() : salary(0.0) {}
Employee::Employee(int id, string name, string password, double salary) : Person(id, name, password)  {
	setSalary(salary);
};
void Employee::setSalary(double salary) {
	if (salary >= 5000) {
		this->salary = salary;
	}
	else  {
		cout << "Minimum Salary Should be 5000 \n";
	
	}
}
double Employee::getSalary()const {
	return salary;
}
void Employee::display() {
	cout << " ID : " << id << " -"
		<< " Name : " << name << " -"
		<< " PassWord : " << password << " -"
		<< " Salary : " << salary;
	cout << endl;
}
void Employee::addClient(const Client& obj) {
	FileManager File_Manager;
	File_Manager.addClient(obj);
	cout << "Client Added Successfully \n";

}
Client* Employee::SearchClient(int id) {
    static FileManager fileManager;
    static vector<Client> clients;

    clients = fileManager.getAllClients();  // تحدث كل مرة قبل البحث

    for (auto& c : clients) {
        if (c.getId() == id) {
            return &c;  // pointer صالح فقط داخل الدالة / مباشرة بعد الاستخدام
        }
    }

    cout << "Client is not Found\n";
    return nullptr;
}
void Employee::listClients() {

	FileManager File_Manager;
	vector<Client> allClients = File_Manager.getAllClients();
	for (auto& element : allClients) {
		element.display();
	}
}
void Employee::editClient(int id,const string& name, const string& password, double balance) {
    FileManager fileManager;
    vector<Client> allClients = fileManager.getAllClients(); 

    bool found = false;

    for (auto& client : allClients) {
        if (client.getId() == id) {
         
            client.setName(name);
            client.setPassword(password);
            client.setBalance(balance);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Client not found!\n";
        return;
    }

   
    fileManager.removeAllClients();
    for (const auto& client : allClients) {
        fileManager.addClient(client);
    }

        cout << "Client updated successfully.\n";
}
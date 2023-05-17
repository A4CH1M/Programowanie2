#include <iostream>
#include <string>
#include <cstdlib>
#include <locale>
#include "client_c.h"
#include "employee_c.h"

using namespace std;

void createClient(Client**& client);
void createClient(Client**& client, const size_t size);
void insertClientData(Client* client);
void insertClientData(Client** clients, const size_t size);
void printClientData(Client* client);
void printClientData(Client** client, const size_t size);
void deleteClients(Client**& client, size_t& size);
void deleteClient(Client**& file, size_t& size, size_t index);
void addClient(Client**& file, size_t& size);
void printAverageContractValue(Client** client, size_t size);
void printContractorWithHighestContractValue(Client** client, size_t size);
void printContractorWithLowestContractValue(Client** client, size_t size);

string generateRandomNip();
string generateRandomPhoneNumber();
string generateRandomPESEL();

void canCreateClientDatabase(Client**& clientDb, size_t size);

void addTicket(Client**& client, size_t size, size_t index);
void deleteTicket(Client**& client, size_t size, size_t clientIndex, size_t ticketIndex);
void printTickets(Client**& client, size_t size);
void printTickets(Client**& client, size_t size, size_t index);

void createEmployee(Employee**& employee);
void createEmployee(Employee**& employee, const size_t size);
void insertEmployeeData(Employee** employee, const size_t size);
void printEmployeeData(Employee* employee);
void printEmployeeData(Employee** employee, const size_t size);
void deleteEmployees(Employee**& file, size_t& size);
void deleteEmployee(Employee**& file, size_t& size, size_t index);
void addEmployee(Employee**& file, size_t& size);

void evaluateEmployees(Employee**& file, size_t size);

void canCreateEmployeeDatabase(Employee**& employeeDb, size_t size);

void menu();
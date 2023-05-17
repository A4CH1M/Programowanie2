#include <iostream>
#include <locale>
#include <vector>
#include <memory>
#include "functions.h"
#include "client_c.h"
#include "employee_c.h"

void clientMenu(const std::vector<std::shared_ptr<Client>>&);
void ticketMenu(const std::vector<std::shared_ptr<Client>>&, std::vector<std::shared_ptr<Employee>>&);
void clientStatsMenu(const std::vector<std::shared_ptr<Client>>&);
void employeeMenu(const std::vector<std::shared_ptr<Employee>>&);
void menu() {
	setlocale(LC_CTYPE, "Polish");
	std::vector<std::shared_ptr<Employee>> employeesVector;
	std::vector<std::shared_ptr<Client>> clientsVector;
	size_t choice;
	bool _exit = false;
	do {
		std::cout << "======================Menu======================" << std::endl;
		std::cout << "1. Zarz¹dzanie Klientami" << std::endl;
		std::cout << "2. Zarz¹dzanie Zg³oszeniami" << std::endl;
		std::cout << "3. Dane statystyczne klientów" << std::endl;
		std::cout << "4. Zarz¹dzanie Pracownikami" << std::endl;
		std::cout << "5. WyjdŸ" << std::endl;
		std::cout << "================================================" << std::endl;
		std::cout << "Wybierz opcjê: ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			clientMenu(clientsVector);
			break;
		case 2:
			ticketMenu(clientsVector,employeesVector);
			break;
		case 3:
			clientStatsMenu(clientsVector);
			break;
		case 4:
			employeeMenu(employeesVector);
			break;
		case 5:
			deleteAllFromTemplate(clientsVector);
			deleteAllFromTemplate(employeesVector);
			_exit = true;
			break;
		default:
			std::cout << "Wybrana opcja nie istnieje." << std::endl;
			break;
		}
		system("pause");
		system("cls");
	} while (_exit == false);
}
void clientMenu(std::vector<std::shared_ptr<Client>>& clients) {
	system("cls");
	size_t choice;
	bool _exit = false;
	do {
		std::cout << "======================Menu======================" << std::endl;
		std::cout << "1. Wygeneruj bazê klientów" << std::endl;
		std::cout << "2. Dodaj nowego klienta" << std::endl;
		std::cout << "3. Dodaj kilku klientów" << std::endl;
		std::cout << "4. Wyœwietl klientów" << std::endl;
		std::cout << "5. Usuñ klienta" << std::endl;
		std::cout << "6. Wróæ" << std::endl;
		std::cout << "================================================" << std::endl;
		std::cout << "Wybierz opcjê: ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			canCreateDatabase(clients);
			break;
		case 2:
			addClient(clients);
			break;
		case 3:
			insertMultipleUsingQueue(clients);
			break;
		case 4:
			printFromTemplate(clients);
			break;
		case 5:
			deleteFromTemplate(clients);
			break;
		case 6:
			_exit = true;
			break;
		default:
			std::cout << "Wybrana opcja nie istnieje." << std::endl;
			break;
		}
		system("pause");
		system("cls");
	} while (_exit == false);
}
void ticketMenu(const std::vector<std::shared_ptr<Client>>& clients, std::vector<std::shared_ptr<Employee>>& employees) {
	system("cls");
	size_t choice;
	bool _exit = false;
	do {
		std::cout << "======================Menu======================" << std::endl;
		std::cout << "1. Dodaj nowe zg³oszenie" << std::endl;
		std::cout << "2. Wyœwietl wszystkie zg³oszenia" << std::endl;
		std::cout << "3. Wyœwietl zg³oszenia klienta" << std::endl;
		std::cout << "4. Zamknij zg³oszenie klienta" << std::endl;
		std::cout << "5. Usuñ zg³oszenie" << std::endl;
		std::cout << "6. Wróæ" << std::endl;
		std::cout << "================================================" << std::endl;
		std::cout << "Wybierz opcjê: ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			addTicket(clients);
			break;
		case 2:
			printTickets(clients);
			break;
		case 3:
			printSpecificClientsTickets(clients);
			break;
		case 4:
			closeTicket(clients, employees);
			break;
		case 5:
			deleteTicket(clients);
			break;
		case 6:
			_exit = true;
			break;
		default:
			std::cout << "Wybrana opcja nie istnieje." << std::endl;
			break;
		}
		system("pause");
		system("cls");
	} while (_exit == false);
}
void clientStatsMenu(const std::vector<std::shared_ptr<Client>>& clients) {
	system("cls");
	size_t choice;
	bool _exit = false;
	do {
		std::cout << "======================Menu======================" << std::endl;
		std::cout << "1. Wyœwietl œredni¹ wartoœæ umowy" << std::endl;
		std::cout << "2. Wyœwietl klienta z najwy¿sz¹ wartoœci¹ umowy" << std::endl;
		std::cout << "3. Wyœwietl klienta z najni¿sz¹ wartoœci¹ umowy" << std::endl;
		std::cout << "4. Wróæ" << std::endl;
		std::cout << "================================================" << std::endl;
		std::cout << "Wybierz opcjê: ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			printAverageContractValue(clients);
			break;
		case 2:
			printContractorWithHighestContractValue(clients);
			break;
		case 3:
			printContractorWithLowestContractValue(clients);
			break;
		case 4:
			_exit = true;
			break;
		default:
			std::cout << "Wybrana opcja nie istnieje." << std::endl;
			break;
		}
		system("pause");
		system("cls");
	} while (_exit == false);
}
void employeeMenu(const std::vector<std::shared_ptr<Employee>>& employees) {
	system("cls");
	size_t choice;
	bool _exit = false;
	do {
		std::cout << "======================Menu======================" << std::endl;
		std::cout << "1. Wygeneruj bazê pracowników" << std::endl;
		std::cout << "2. Dodaj nowego pracownika" << std::endl;
		std::cout << "3. Wyœwietl pracowników" << std::endl;
		std::cout << "4. Usuñ pracownika" << std::endl;
		std::cout << "5. Kalkuluj rzeczy pracowników" << std::endl;
		std::cout << "6. Wróæ" << std::endl;
		std::cout << "================================================" << std::endl;
		std::cout << "Wybierz opcjê: ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			canCreateDatabase(employees);
			break;
		case 2:
			addEmployee(employees);
			break;
		case 3:
			printFromTemplate(employees);
			break;
		case 4:
			deleteFromTemplate(employees);
			break;
		case 5:
			evaluateEmployees(employees);
			break;
		case 6:
			_exit = true;
			break;
		default:
			std::cout << "Wybrana opcja nie istnieje." << std::endl;
			break;
		}
		system("pause");
		system("cls");
	} while (_exit == false);
}
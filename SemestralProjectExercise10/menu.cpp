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
		std::cout << "1. Zarz�dzanie Klientami" << std::endl;
		std::cout << "2. Zarz�dzanie Zg�oszeniami" << std::endl;
		std::cout << "3. Dane statystyczne klient�w" << std::endl;
		std::cout << "4. Zarz�dzanie Pracownikami" << std::endl;
		std::cout << "5. Wyjd�" << std::endl;
		std::cout << "================================================" << std::endl;
		std::cout << "Wybierz opcj�: ";
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
		std::cout << "1. Wygeneruj baz� klient�w" << std::endl;
		std::cout << "2. Dodaj nowego klienta" << std::endl;
		std::cout << "3. Dodaj kilku klient�w" << std::endl;
		std::cout << "4. Wy�wietl klient�w" << std::endl;
		std::cout << "5. Usu� klienta" << std::endl;
		std::cout << "6. Wr��" << std::endl;
		std::cout << "================================================" << std::endl;
		std::cout << "Wybierz opcj�: ";
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
		std::cout << "1. Dodaj nowe zg�oszenie" << std::endl;
		std::cout << "2. Wy�wietl wszystkie zg�oszenia" << std::endl;
		std::cout << "3. Wy�wietl zg�oszenia klienta" << std::endl;
		std::cout << "4. Zamknij zg�oszenie klienta" << std::endl;
		std::cout << "5. Usu� zg�oszenie" << std::endl;
		std::cout << "6. Wr��" << std::endl;
		std::cout << "================================================" << std::endl;
		std::cout << "Wybierz opcj�: ";
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
		std::cout << "1. Wy�wietl �redni� warto�� umowy" << std::endl;
		std::cout << "2. Wy�wietl klienta z najwy�sz� warto�ci� umowy" << std::endl;
		std::cout << "3. Wy�wietl klienta z najni�sz� warto�ci� umowy" << std::endl;
		std::cout << "4. Wr��" << std::endl;
		std::cout << "================================================" << std::endl;
		std::cout << "Wybierz opcj�: ";
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
		std::cout << "1. Wygeneruj baz� pracownik�w" << std::endl;
		std::cout << "2. Dodaj nowego pracownika" << std::endl;
		std::cout << "3. Wy�wietl pracownik�w" << std::endl;
		std::cout << "4. Usu� pracownika" << std::endl;
		std::cout << "5. Kalkuluj rzeczy pracownik�w" << std::endl;
		std::cout << "6. Wr��" << std::endl;
		std::cout << "================================================" << std::endl;
		std::cout << "Wybierz opcj�: ";
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
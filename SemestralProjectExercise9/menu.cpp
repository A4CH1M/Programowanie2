#include <iostream>
#include <locale>
#include <vector>
#include "functions.h"
#include "client_c.h"
#include "employee_c.h"
using namespace std;

void clientMenu(vector<Client*>&);
void ticketMenu(vector<Client*>&, vector<Employee*>&);
void clientStatsMenu(vector<Client*>&);
void employeeMenu(vector<Employee*>&);
void menu() {
	setlocale(LC_CTYPE, "Polish");
	vector<Employee*> employeesVector;
	vector<Client*> clientsVector;
	size_t choice;
	bool _exit = false;
	do {
		cout << "======================Menu======================" << endl;
		cout << "1. Zarz�dzanie Klientami" << endl;
		cout << "2. Zarz�dzanie Zg�oszeniami" << endl;
		cout << "3. Dane statystyczne klient�w" << endl;
		cout << "4. Zarz�dzanie Pracownikami" << endl;
		cout << "5. Wyjd�" << endl;
		cout << "================================================" << endl;
		cout << "Wybierz opcj�: ";
		cin >> choice;
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
			cout << "Wybrana opcja nie istnieje." << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (_exit == false);
}
void clientMenu(vector<Client*>& clients) {
	system("cls");
	size_t choice;
	bool _exit = false;
	do {
		cout << "======================Menu======================" << endl;
		cout << "1. Wygeneruj baz� klient�w" << endl;
		cout << "2. Dodaj nowego klienta" << endl;
		cout << "3. Wy�wietl klient�w" << endl;
		cout << "4. Usu� klienta" << endl;
		cout << "5. Wr��" << endl;
		cout << "================================================" << endl;
		cout << "Wybierz opcj�: ";
		cin >> choice;
		switch (choice) {
		case 1:
			canCreateDatabase(clients);
			break;
		case 2:
			addClient(clients);
			break;
		case 3:
			printFromTemplate(clients);
			break;
		case 4:
			deleteFromTemplate(clients);
			break;
		case 5:
			_exit = true;
			break;
		default:
			cout << "Wybrana opcja nie istnieje." << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (_exit == false);
}
void ticketMenu(vector<Client*>& clients, vector<Employee*>& employees) {
	system("cls");
	size_t choice;
	bool _exit = false;
	do {
		cout << "======================Menu======================" << endl;
		cout << "1. Dodaj nowe zg�oszenie" << endl;
		cout << "2. Wy�wietl wszystkie zg�oszenia" << endl;
		cout << "3. Wy�wietl zg�oszenia klienta" << endl;
		cout << "4. Zamknij zg�oszenie klienta" << endl;
		cout << "5. Usu� zg�oszenie" << endl;
		cout << "6. Wr��" << endl;
		cout << "================================================" << endl;
		cout << "Wybierz opcj�: ";
		cin >> choice;
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
			cout << "Wybrana opcja nie istnieje." << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (_exit == false);
}
void clientStatsMenu(vector<Client*>& clients) {
	system("cls");
	size_t choice;
	bool _exit = false;
	do {
		cout << "======================Menu======================" << endl;
		cout << "1. Wy�wietl �redni� warto�� umowy" << endl;
		cout << "2. Wy�wietl klienta z najwy�sz� warto�ci� umowy" << endl;
		cout << "3. Wy�wietl klienta z najni�sz� warto�ci� umowy" << endl;
		cout << "4. Wr��" << endl;
		cout << "================================================" << endl;
		cout << "Wybierz opcj�: ";
		cin >> choice;
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
			cout << "Wybrana opcja nie istnieje." << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (_exit == false);
}
void employeeMenu(vector<Employee*>& employees) {
	system("cls");
	size_t choice;
	bool _exit = false;
	do {
		cout << "======================Menu======================" << endl;
		cout << "1. Wygeneruj baz� pracownik�w" << endl;
		cout << "2. Dodaj nowego pracownika" << endl;
		cout << "3. Wy�wietl pracownik�w" << endl;
		cout << "4. Usu� pracownika" << endl;
		cout << "5. Kalkuluj rzeczy pracownik�w" << endl;
		cout << "6. Wr��" << endl;
		cout << "================================================" << endl;
		cout << "Wybierz opcj�: ";
		cin >> choice;
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
			cout << "Wybrana opcja nie istnieje." << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (_exit == false);
}
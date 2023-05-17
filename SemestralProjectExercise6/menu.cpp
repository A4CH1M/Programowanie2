#include <iostream>
#include <locale>
#include "functions.h"
#include "client_c.h"
#include "employee_c.h"
using namespace std;
void menu() {
	setlocale(LC_CTYPE, "Polish");
	Client** clientsPtr = nullptr;
	Employee** employeesPtr = nullptr;
	size_t choice, clientDatabaseSize = 0, employeeDatabaseSize = 0, clientIndex, ticketIndex, employeeIndex;
	bool _exit = false;
	do {
		cout << "====================Menu====================" << endl;
		cout << "1. Stw�rz baz� klient�w" << endl;
		cout << "2. Dodaj nowego klienta" << endl;
		cout << "3. Wy�wietl klient�w" << endl;
		cout << "4. Usu� klienta" << endl;
		cout << "5. Dodaj nowe zg�oszenie" << endl;
		cout << "6. Wy�wietl zg�oszenia" << endl;
		cout << "7. Wy�wietl zg�oszenia konkretnego klienta" << endl;
		cout << "8. Usu� zg�oszenie" << endl;
		cout << "9. �rednia umowy" << endl;
		cout << "10. Najwy�sza umowa" << endl;
		cout << "11. Najni�sza umowa" << endl;
		cout << "12. Stw�rz baz� pracownik�w" << endl;
		cout << "13. Dodaj nowego pracownika" << endl;
		cout << "14. Wy�wietl pracownik�w" << endl;
		cout << "15. Usu� pracownika" << endl;
		cout << "16. Kalkuluj rzeczy pracownik�w" << endl;
		cout << "17. Wyjd�" << endl;
		cout << "============================================" << endl;
		cout << "Wybierz opcj�: ";
		cin >> choice;
		switch (choice) {
		case 1:
			if (clientsPtr == nullptr) {
				cout << "Ilu klient�w chcesz doda�: ";
				cin >> clientDatabaseSize;
			}
			canCreateClientDatabase(clientsPtr, clientDatabaseSize);
			break;
		case 2:
			addClient(clientsPtr, clientDatabaseSize);
			break;
		case 3:
			if (clientDatabaseSize > 0)
				printClientData(clientsPtr, clientDatabaseSize);
			break;
		case 4:
			if (clientDatabaseSize > 0) {
				cout << "Podaj numer indeksu klienta, kt�rego chcesz usun��: ";
				cin >> clientIndex;
				if (clientIndex >= 0)
					deleteClient(clientsPtr, clientDatabaseSize, clientIndex);
			}
			break;
		case 5:
			cout << "Podaj numer indeksu klienta, kt�remu chcesz doda� zg�oszenie: ";
			cin >> clientIndex;
			if (clientIndex < clientDatabaseSize)
				addTicket(clientsPtr, clientDatabaseSize, clientIndex);
			break;
		case 6:
			if (clientDatabaseSize > 0)
				printTickets(clientsPtr, clientDatabaseSize);
			break;
		case 7:
			cout << "Podaj numer indeksu klienta, kt�rego zg�oszenia chcesz wy�wietli�: ";
			cin >> clientIndex;
			if (clientDatabaseSize > 0)
				printTickets(clientsPtr, clientDatabaseSize, clientIndex);
			break;
		case 8:
			if (clientDatabaseSize > 0) {
				cout << "Podaj numer indeksu klienta, kt�rego zg�oszenie chcesz usun��: ";
				cin >> clientIndex;
				cout << "Podaj numer indeksu zg�oszenia, kt�re chcesz usun��: ";
				cin >> ticketIndex;
				deleteTicket(clientsPtr, clientDatabaseSize, clientIndex, ticketIndex);
			}
			break;
		case 9:
			if (clientDatabaseSize > 0)
				printAverageContractValue(clientsPtr, clientDatabaseSize);
			break;
		case 10:
			if (clientDatabaseSize > 0)
				printContractorWithHighestContractValue(clientsPtr, clientDatabaseSize);
			break;
		case 11:
			if (clientDatabaseSize > 0)
				printContractorWithLowestContractValue(clientsPtr, clientDatabaseSize);
			break;
		case 12:
			if (employeesPtr == nullptr) {
				cout << "Ilu pracownik�w chcesz doda�: ";
				cin >> employeeDatabaseSize;
			}
			canCreateEmployeeDatabase(employeesPtr, employeeDatabaseSize);
			break;
		case 13:
			addEmployee(employeesPtr, employeeDatabaseSize);
			if (employeeDatabaseSize > 0) evaluateEmployees(employeesPtr, employeeDatabaseSize);
			break;
		case 14:
			if (employeeDatabaseSize > 0)
				printEmployeeData(employeesPtr, employeeDatabaseSize);
			break;
		case 15:
			if (employeeDatabaseSize > 0) {
				cout << "Podaj numer indeksu pracownika, kt�rego chcesz usun��: ";
				cin >> employeeIndex;
				if (employeeIndex >= 0)
					deleteEmployee(employeesPtr, employeeDatabaseSize, employeeIndex);
			}
			break;
		case 16:
			if (employeeDatabaseSize > 0) {
				evaluateEmployees(employeesPtr, employeeDatabaseSize);
			}
			break;
		case 17:
			deleteClients(clientsPtr, clientDatabaseSize);
			deleteEmployees(employeesPtr, employeeDatabaseSize);
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
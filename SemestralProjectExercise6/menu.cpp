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
		cout << "1. Stwórz bazê klientów" << endl;
		cout << "2. Dodaj nowego klienta" << endl;
		cout << "3. Wyœwietl klientów" << endl;
		cout << "4. Usuñ klienta" << endl;
		cout << "5. Dodaj nowe zg³oszenie" << endl;
		cout << "6. Wyœwietl zg³oszenia" << endl;
		cout << "7. Wyœwietl zg³oszenia konkretnego klienta" << endl;
		cout << "8. Usuñ zg³oszenie" << endl;
		cout << "9. Œrednia umowy" << endl;
		cout << "10. Najwy¿sza umowa" << endl;
		cout << "11. Najni¿sza umowa" << endl;
		cout << "12. Stwórz bazê pracowników" << endl;
		cout << "13. Dodaj nowego pracownika" << endl;
		cout << "14. Wyœwietl pracowników" << endl;
		cout << "15. Usuñ pracownika" << endl;
		cout << "16. Kalkuluj rzeczy pracowników" << endl;
		cout << "17. WyjdŸ" << endl;
		cout << "============================================" << endl;
		cout << "Wybierz opcjê: ";
		cin >> choice;
		switch (choice) {
		case 1:
			if (clientsPtr == nullptr) {
				cout << "Ilu klientów chcesz dodaæ: ";
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
				cout << "Podaj numer indeksu klienta, którego chcesz usun¹æ: ";
				cin >> clientIndex;
				if (clientIndex >= 0)
					deleteClient(clientsPtr, clientDatabaseSize, clientIndex);
			}
			break;
		case 5:
			cout << "Podaj numer indeksu klienta, któremu chcesz dodaæ zg³oszenie: ";
			cin >> clientIndex;
			if (clientIndex < clientDatabaseSize)
				addTicket(clientsPtr, clientDatabaseSize, clientIndex);
			break;
		case 6:
			if (clientDatabaseSize > 0)
				printTickets(clientsPtr, clientDatabaseSize);
			break;
		case 7:
			cout << "Podaj numer indeksu klienta, którego zg³oszenia chcesz wyœwietliæ: ";
			cin >> clientIndex;
			if (clientDatabaseSize > 0)
				printTickets(clientsPtr, clientDatabaseSize, clientIndex);
			break;
		case 8:
			if (clientDatabaseSize > 0) {
				cout << "Podaj numer indeksu klienta, którego zg³oszenie chcesz usun¹æ: ";
				cin >> clientIndex;
				cout << "Podaj numer indeksu zg³oszenia, które chcesz usun¹æ: ";
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
				cout << "Ilu pracowników chcesz dodaæ: ";
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
				cout << "Podaj numer indeksu pracownika, którego chcesz usun¹æ: ";
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
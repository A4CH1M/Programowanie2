#include <iostream>
#include <locale>
#include <vector>
#include "functions.h"
#include "client_c.h"
#include "employee_c.h"
using namespace std;
void menu() {
	setlocale(LC_CTYPE, "Polish");
	vector<Employee*> employeesVector;
	vector<Client*> clientsVector;
	size_t choice;
	bool _exit = false;
	do {
		cout << "====================Menu====================" << endl;
		cout << "1. Wygeneruj bazê klientów" << endl;
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
		cout << "12. Wygeneruj bazê pracowników" << endl;
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
			canCreateDatabase(clientsVector);
			break;
		case 2:
			addClient(clientsVector);
			break;
		case 3:
			printFromTemplate(clientsVector);
			break;
		case 4:
			deleteFromTemplate(clientsVector);
			break;
		case 5:
			addTicket(clientsVector);
			break;
		case 6:
			printTickets(clientsVector);
			break;
		case 7:
			printSpecificClientsTickets(clientsVector);
			break;
		case 8:
			deleteTicket(clientsVector);
			break;
		case 9:
			printAverageContractValue(clientsVector);
			break;
		case 10:
			printContractorWithHighestContractValue(clientsVector);
			break;
		case 11:
			printContractorWithLowestContractValue(clientsVector);
			break;
		case 12:
			//To generate number of records:
			canCreateDatabase(employeesVector);
			//To simply add a new employee without generating any:
			//addEmployee(employeesVector);
			break;
		case 13:
			addEmployee(employeesVector);
			break;
		case 14:
			printFromTemplate(employeesVector);
			break;
		case 15:
			deleteFromTemplate(employeesVector);
			break;
		case 16:
			evaluateEmployees(employeesVector);
			break;
		case 17:
			deleteAllFromTemplate(clientsVector);
			deleteAllFromTemplate(employeesVector);
			_exit = true;
			break;
		default:
			cout << "Wybrana opcja nie istnieje." << endl;
			//cout << clientsVector.size() << " " << clientsVector.capacity() << endl;
			//cout << employeesVector.size() << " " << employeesVector.capacity() << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (_exit == false);
}
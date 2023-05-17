#include <iostream>
#include <locale>
#include "functions.h"
using namespace std;

void menu() {
	setlocale(LC_CTYPE, "Polish");
	Client** clientsPtr = nullptr;
	Ticket* ticketsPtr = nullptr;
	size_t choice, clientDatabaseSize = 0, delIndex, ticketsDatabaseSize = 0;
	bool _exit = false;
	do {
		cout << "Menu:" << endl;
		cout << "1. Stwórz bazê klientów" << endl;
		cout << "2. Dodaj nowego klienta" << endl;
		cout << "3. Wyœwietl klientów" << endl;
		cout << "4. Usuñ klienta" << endl;
		cout << "5. Dodaj nowe zg³oszenie" << endl;
		cout << "6. Usuñ zg³oszenie" << endl;
		cout << "7. Wyœwietl zg³oszenia" << endl;
		cout << "8. Œrednia umowy" << endl;
		cout << "9. Najwy¿sza umowa" << endl;
		cout << "10. Najni¿sza umowa" << endl;
		cout << "11. WyjdŸ" << endl;
		cout << "Wybierz numer: ";
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
				cout << "Podaj numer indeksu, który chcesz usun¹æ: ";
				cin >> delIndex;
				if (delIndex >= 0 && delIndex <= clientDatabaseSize)
					deleteClient(clientsPtr, clientDatabaseSize, delIndex);
			}
			break;
		case 5:
			createTicket(ticketsPtr, ticketsDatabaseSize);
			break;
		case 6:
			if (ticketsDatabaseSize > 0) {
				cout << "Podaj numer indeksu, który chcesz usun¹æ: ";
				cin >> delIndex;
				if (delIndex >= 0 && delIndex <= ticketsDatabaseSize)
					deleteTicket(ticketsPtr, ticketsDatabaseSize, delIndex);
			}
			break;
		case 7:
			if (ticketsDatabaseSize > 0)
				printTickets(ticketsPtr, ticketsDatabaseSize);
			break;
		case 8:
			if (clientDatabaseSize > 0)
				printAverageContractValue(clientsPtr, clientDatabaseSize);
			break;
		case 9:
			if (clientDatabaseSize > 0)
				printContractorWithHighestContractValue(clientsPtr, clientDatabaseSize);
			break;
		case 10:
			if (clientDatabaseSize > 0)
				printContractorWithLowestContractValue(clientsPtr, clientDatabaseSize);
			break;
		case 11:
			deleteClients(clientsPtr, clientDatabaseSize);
			deleteTickets(ticketsPtr, ticketsDatabaseSize);
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
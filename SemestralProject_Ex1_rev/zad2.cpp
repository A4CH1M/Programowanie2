#include <iostream>
#include <string>
#include <cstdlib>
#include <locale>
using namespace std;

struct Client {
	size_t id;
	string nip;
	string companyName;
	string companyLocation;
	size_t contractValue;
	string contactPersonName;
	string contactPersonSurname;
	string contactPersonPhoneNumber;
	string contactPersonMail;
};

struct Ticket {
	size_t id;
	string shortCompanyName;
	string topic;
	string ticketContent;
};

void createClient(Client*& client);
void createClient(Client**& client);
void createClient(Client*& client, const size_t size);
void createClient(Client**& client, const size_t size);

void insertClientData(Client client);
void insertClientData(Client* client);
void insertClientData(Client* clients, const size_t size);
void insertClientData(Client** clients, const size_t size);

void printClientData(Client* client);
void printClientData(Client* client, const size_t size);
void printClientData(Client** client, const size_t size);

void deleteClient(Client*& client);
void deleteClients(Client*& client, size_t& size);
void deleteClients(Client**& client, size_t& size);
void deleteClient(Client*& file, size_t& size, size_t index);
void deleteClient(Client**& file, size_t& size, size_t index);

void addClient(Client*& file, size_t& size); 
void addClient(Client**& file, size_t& size);

void printAverageContractValue(Client* client, size_t size);
void printAverageContractValue(Client** client, size_t size);
void printContractorWithHighestContractValue(Client* client, size_t size);
void printContractorWithHighestContractValue(Client** client, size_t size);
void printContractorWithLowestContractValue(Client* client, size_t size);
void printContractorWithLowestContractValue(Client** client, size_t size);

string generateRandomNip();
string generateRandomPhoneNumber();

void canCreateClientDatabase(Client*& clientDb, size_t size);
void canCreateClientDatabase(Client**& clientDb, size_t size);

void createTicket(Ticket*& tickets, size_t& size);
void createTicket(Ticket**& tickets, size_t& size);

void insertTicketContent(Ticket ticket);
void insertTicketContent(Ticket* ticket);

void deleteTicket(Ticket*& tickets, size_t& size, size_t index);
void deleteTicket(Ticket**& tickets, size_t& size, size_t index);
void deleteTickets(Ticket*& tickets, size_t size);
void deleteTickets(Ticket**& tickets, size_t& size);

void menu();

int main() {
	menu();
	return 0;
}

void createClient(Client*& client) {
	client = new Client;
}
void createClient(Client**& client) {
	client = new Client*;
}
void createClient(Client*& client, const size_t size) {
	client = new Client[size];
}
void createClient(Client**& client, const size_t size) {
	client = new Client *[size];
	for (size_t i = 0; i < size; i++) {
		client[i] = new Client;
	}
}
void insertClientData(Client client) {
	setlocale(LC_CTYPE, "Polish");
	cout << "NIP: ";
	cin >> client.nip;
	cout << "Nazwa firmy: ";
	cin.ignore();
	getline(cin, client.companyName);
	cout << "Miasto: ";
	cin.ignore();
	getline(cin, client.companyLocation);
	cout << "Wartoœæ umowy: ";
	cin >> client.contractValue;
	cout << "Imiê osoby kontaktowej: ";
	cin >> client.contactPersonName;
	cout << "Nazwisko osoby kontaktowej: ";
	cin >> client.contactPersonSurname;
	cout << "Numer telefonu osoby kontaktowej: ";
	cin >> client.contactPersonPhoneNumber;
	cout << "Adres email osoby kontaktowej: ";
	cin >> client.contactPersonMail;
}
void insertClientData(Client* client) {
	setlocale(LC_CTYPE, "Polish");
	cout << "NIP: ";
	cin >> client->nip;
	cout << "Nazwa firmy: ";
	cin.ignore();
	getline(cin, client->companyLocation);
	cin >> client->companyName;
	cout << "Miasto: ";
	cin.ignore();
	getline(cin, client->companyLocation);
	cout << "Wartoœæ umowy: ";
	cin >> client->contractValue;
	cout << "Imiê osoby kontaktowej: ";
	cin >> client->contactPersonName;
	cout << "Nazwisko osoby kontaktowej: ";
	cin >> client->contactPersonSurname;
	cout << "Numer telefonu osoby kontaktowej: ";
	cin >> client->contactPersonPhoneNumber;
	cout << "Adres email osoby kontaktowej: ";
	cin >> client->contactPersonMail;
}
void insertClientData(Client* clients, const size_t size) {
	for (size_t i = 0; i < size; i++) {
		clients[i].nip = generateRandomNip();
		clients[i].companyName = "Test";
		clients[i].companyLocation = "Szczecin";
		clients[i].contractValue = (rand() % 100 + 1) * 100;
		clients[i].contactPersonName = "Kontakt";
		clients[i].contactPersonSurname = "Kontaktowy";
		clients[i].contactPersonPhoneNumber = generateRandomPhoneNumber();
		clients[i].contactPersonMail = "test@test.test";
	}
}
void insertClientData(Client** clients, const size_t size) {
	for (size_t i = 0; i < size; i++) {
		clients[i]->nip = generateRandomNip();
		clients[i]->companyName = "Test";
		clients[i]->companyLocation = "Szczecin";
		clients[i]->contractValue = (rand() % 100 + 1) * 100;
		clients[i]->contactPersonName = "Kontakt";
		clients[i]->contactPersonSurname = "Kontaktowy";
		clients[i]->contactPersonPhoneNumber = generateRandomPhoneNumber();
		clients[i]->contactPersonMail = "test@test.test";
	}
}
void printClientData(Client* client) {
	if (client == nullptr)
		return;
	cout << "------------------------------------------------------------" << endl;
	cout << "NIP:                              " << client->nip << endl;
	cout << "Nazwa firmy:                      " << client->companyName << endl;
	cout << "Miasto:                           " << client->companyLocation << endl;
	cout << "Wartoœæ umowy                     " << client->contractValue << endl;
	cout << "Imiê osoby kontaktowej:           " << client->contactPersonName << endl;
	cout << "Nazwisko osoby kontaktowej:       " << client->contactPersonSurname << endl;
	cout << "Numer telefonu osoby kontaktowej: " << client->contactPersonPhoneNumber << endl;
	cout << "Adres email osoby kontaktowej:    " << client->contactPersonMail << endl;
	cout << "------------------------------------------------------------" << endl;
}
void printClientData(Client* client, const size_t size) {
	if (client == nullptr)
		return;
	cout << "------------------------------------------------------------" << endl;
	for (size_t i = 0; i < size; i++) {
		cout << "NIP:                              " << client[i].nip << endl;
		cout << "Nazwa firmy:                      " << client[i].companyName << endl;
		cout << "Miasto:                           " << client[i].companyLocation << endl;
		cout << "Wartoœæ umowy                     " << client[i].contractValue << endl;
		cout << "Imiê osoby kontaktowej:           " << client[i].contactPersonName << endl;
		cout << "Nazwisko osoby kontaktowej:       " << client[i].contactPersonSurname << endl;
		cout << "Numer telefonu osoby kontaktowej: " << client[i].contactPersonPhoneNumber << endl;
		cout << "Adres email osoby kontaktowej:    " << client[i].contactPersonMail << endl;
		cout << "------------------------------------------------------------" << endl;
	}
}
void printClientData(Client** client, size_t size) {
	if (client == nullptr)
		return;
	//cout << "------------------------------------------------------------" << endl;
	for (size_t i = 0; i < size; i++) {
		cout << "NIP:                              " << client[i]->nip << endl;
		cout << "Nazwa firmy:                      " << client[i]->companyName << endl;
		cout << "Miasto:                           " << client[i]->companyLocation << endl;
		cout << "Wartoœæ umowy                     " << client[i]->contractValue << endl;
		cout << "Imiê osoby kontaktowej:           " << client[i]->contactPersonName << endl;
		cout << "Nazwisko osoby kontaktowej:	   " << client[i]->contactPersonSurname << endl;
		cout << "Numer telefonu osoby kontaktowej: " << client[i]->contactPersonPhoneNumber << endl;
		cout << "Adres email osoby kontaktowej:    " << client[i]->contactPersonMail << endl;
		cout << "------------------------------------------------------------" << endl;
	}
}
void deleteClient(Client*& client) {
	delete client;
	client = nullptr;
}
void deleteClients(Client*& client, size_t& size) {
	delete[] client;
	client = nullptr;
}
void deleteClients(Client**& client, size_t& size) {
	for (size_t i = 0; i < size; i++)
		delete client[i];
	delete client;
	client = nullptr;
	size = 0;
}
void deleteClient(Client*& file, size_t& size, size_t index) {
	if (index < size) {
		Client* tmp = new Client[size - 1];
		short j = -1;
		for (size_t i = 0; i < size; ++i)
			if (i != index) {
				j++;
				tmp[j] = file[i];
			}
		delete[] file;
		file = tmp;
		size--;
	}
	else cout << "Nieprawid³owy indeks" << endl;
}
void deleteClient(Client**& file, size_t& size, size_t index) {
	if (index < size) {
		Client** tmp = new Client *[size - 1];
		short j = -1;
		for (size_t i = 0; i < size; i++)
			if (i != index) {
				j++;
				tmp[j] = file[i];
			}
		delete[] file;
		file = tmp;
		size--;
	}
	else cout << "Nieprawid³owy indeks" << endl;
}
void addClient(Client*& file, size_t& size) {
	Client* tmp = new Client[size + 1];
	for (size_t i = 0; i < size; ++i)
		tmp[i] = file[i];
	delete[] file;
	file = tmp;
	insertClientData(&file[size]);
	size++;
}
void addClient(Client**& file, size_t& size) {
	Client** tmp = new Client *[size + 1];
	if (size == 0) { tmp[size] = new Client; }
	else {
		for (size_t i = 0; i < size; ++i)
			tmp[i] = file[i];
		tmp[size] = new Client;
		delete[] file;
	}
	file = tmp;
	insertClientData(file[size]);
	size++;
}
void printAverageContractValue(Client* client, size_t size) {
	setlocale(LC_CTYPE, "Polish");
	if (client == nullptr) {
		cout << "Brak klientów";
		return;
	}
	float avg = 0;
	for (size_t i = 0; i < size; i++) {
		avg = avg + client[i].contractValue;
	}
	avg = avg / size;
	cout << "Œrednia wartoœæ umowy wynosi: " << avg << endl;
}
void printAverageContractValue(Client** client, size_t size) {
	setlocale(LC_CTYPE, "Polish");
	if (client == nullptr) {
		cout << "Brak klientów";
		return;
	}
	float avg = 0;
	for (size_t i = 0; i < size; i++)
		avg = avg + client[i]->contractValue;
	avg = avg / size;
	cout << "Œrednia wartoœæ umowy wynosi: " << avg << endl;
}
void printContractorWithHighestContractValue(Client* client, size_t size) {
	setlocale(LC_CTYPE, "Polish");
	if (client == nullptr) {
		cout << "Brak klientów";
		return;
	}
	size_t max = 0;
	size_t index;
	for (size_t i = 0; i < size; i++) {
		if (max < client[i].contractValue) {
			max = client[i].contractValue;
			index = i;
		}
	}
	cout << "Klient z umow¹ o najwiêkszej wartoœci: " << client[index].companyName << " : " << client[index].contractValue << endl;
}
void printContractorWithHighestContractValue(Client** client, size_t size) {
	setlocale(LC_CTYPE, "Polish");
	if (client == nullptr) {
		cout << "Brak klientów";
		return;
	}
	size_t max = 0;
	size_t index;
	for (size_t i = 0; i < size; i++) {
		if (max < client[i]->contractValue) {
			max = client[i]->contractValue;
			index = i;
		}
	}
	cout << "Klient z umow¹ o najwiêkszej wartoœci: " << client[index]->companyName << " : " << client[index]->contractValue << endl;
}
void printContractorWithLowestContractValue(Client* client, size_t size) {
	setlocale(LC_CTYPE, "Polish");
	if (client == nullptr) {
		cout << "Brak klientów";
		return;
	}
	size_t min = 1000000;
	size_t index;
	for (size_t i = 0; i < size; i++) {
		if (min > client[i].contractValue) {
			min = client[i].contractValue;
			index = i;
		}
	}
	cout << "Klient z umow¹ o najmniejszej wartoœci: " << client[index].companyName << " : " << client[index].contractValue << endl;
}
void printContractorWithLowestContractValue(Client** client, size_t size) {
	setlocale(LC_CTYPE, "Polish");
	if (client == nullptr) {
		cout << "Brak klientów";
		return;
	}
	setlocale(LC_CTYPE, "Polish");
	if (client == nullptr) {
		cout << "Brak klientów";
		return;
	}
	size_t min = 1000000;
	size_t index;
	for (size_t i = 0; i < size; i++) {
		if (min > client[i]->contractValue) {
			min = client[i]->contractValue;
			index = i;
		}
	}
	cout << "Klient z umow¹ o najmniejszej wartoœci: " << client[index]->companyName << " : " << client[index]->contractValue << endl;
}
string generateRandomNip() {
	string nip;
	size_t r;
	for (size_t i = 0; i < 10; i++) {
		r = rand() % 10;
		nip = nip + to_string(r);
	}
	return nip;
}
string generateRandomPhoneNumber() {
	string pn;
	size_t r;
	for (size_t i = 0; i < 10; i++) {
		r = rand() % 10;
		pn = pn + to_string(r);
	}
	return pn;
}

void canCreateClientDatabase(Client*& clientDb, size_t size) {
	if (clientDb != nullptr) {
		cout << "Uwaga! Baza klientów istnieje, nie mo¿na stworzyæ nowej." << endl;
		return;
	}
	if (size < 1) {
		cout << "Uwaga! Podstawowy rozmiar bazy klientów nie mo¿e byæ mniejszy od 1." << endl;
		return;
	}
	createClient(clientDb, size);
	insertClientData(clientDb, size);
}
void canCreateClientDatabase(Client**& clientDb, size_t size) {
	if (clientDb != nullptr) {
		cout << "Uwaga! Baza klientów istnieje, nie mo¿na stworzyæ nowej." << endl;
		return;
	}
	if (size < 1) {
		cout << "Uwaga! Podstawowy rozmiar bazy klientów nie mo¿e byæ mniejszy od 1." << endl;
		return;
	}
	createClient(clientDb, size);
	insertClientData(clientDb, size);
}

void createTicket(Ticket*& tickets, size_t& size) {
	Ticket* tmp = new Ticket[size + 1];
	for (size_t i = 0; i < size; ++i)
		tmp[i] = tickets[i];
	delete[] tickets;
	tickets = tmp;
	insertTicketContent(&tickets[size]);
	size++;
}
void createTicket(Ticket**& tickets, size_t& size) {
	Ticket** tmp = new Ticket *[size + 1];
	if (size == 0) { tmp[size] = new Ticket; }
	else {
		for (size_t i = 0; i < size; ++i)
			tmp[i] = tickets[i];
		tmp[size] = new Ticket;
		delete[] tickets;
	}
	tickets = tmp;
	insertTicketContent(tickets[size]);
	size++;
}

void insertTicketContent(Ticket ticket) {
	setlocale(LC_CTYPE, "Polish");
	ticket.id = 1;
	cout << "Nazwa skrócona firmy: ";
	cin.ignore();
	getline(cin, ticket.shortCompanyName);
	cout << "Tytu³ zg³oszenia: ";
	cin.ignore();
	getline(cin, ticket.topic);
	cout << "Treœæ: ";
	cin.ignore();
	getline(cin, ticket.ticketContent);
}
void insertTicketContent(Ticket* ticket) {
	setlocale(LC_CTYPE, "Polish");
	ticket->id = 1;
	cout << "Nazwa skrócona firmy: ";
	cin.ignore();
	getline(cin, ticket->shortCompanyName);
	cout << "Tytu³ zg³oszenia: ";
	cin.ignore();
	getline(cin, ticket->topic);
	cout << "Treœæ: ";
	cin.ignore();
	getline(cin, ticket->ticketContent);
}

void deleteTicket(Ticket*& tickets, size_t& size, size_t index) {
	if (index < size) {
		Ticket* tmp = new Ticket[size - 1];
		short j = -1;
		for (size_t i = 0; i < size; ++i)
			if (i != index) {
				j++;
				tmp[j] = tickets[i];
			}
		delete[] tickets;
		tickets = tmp;
		size--;
	}
	else cout << "Nieprawid³owy indeks" << endl;
}
void deleteTicket(Ticket**& tickets, size_t& size, size_t index) {
	if (index < size) {
		Ticket** tmp = new Ticket *[size - 1];
		short j = -1;
		for (size_t i = 0; i < size; ++i)
			if (i != index) {
				j++;
				tmp[j] = tickets[i];
			}
		delete[] tickets;
		tickets = tmp;
		size--;
	}
	else cout << "Nieprawid³owy indeks" << endl;
}
void deleteTickets(Ticket*& tickets, size_t size) {
	delete[] tickets;
	tickets = nullptr;
}
void deleteTickets(Ticket**& tickets, size_t& size) {
	for (size_t i = 0; i < size; i++)
		delete tickets[i];
	delete tickets;
	tickets = nullptr;
	size = 0;
}

void printTickets(Ticket* tickets, const size_t size) {
	if (tickets == nullptr)
		return;
	cout << "------------------------------------------------------------" << endl;
	for (size_t i = 0; i < size; i++) {
		cout << "Numer zg³oszenia: " << tickets[i].id << endl;
		cout << "Nazwa firmy:      " << tickets[i].shortCompanyName << endl;
		cout << "Temat:            " << tickets[i].topic << endl;
		cout << "Treœæ:            " << tickets[i].ticketContent << endl;
		cout << "------------------------------------------------------------" << endl;
	}
}
void printTickets(Ticket** tickets, size_t size) {
	if (tickets == nullptr)
		return;
	cout << "------------------------------------------------------------" << endl;
	for (size_t i = 0; i < size; i++) {
		cout << "Numer zg³oszenia: " << tickets[i]->id << endl;
		cout << "Nazwa firmy:      " << tickets[i]->shortCompanyName << endl;
		cout << "Temat:            " << tickets[i]->topic << endl;
		cout << "Treœæ:            " << tickets[i]->ticketContent << endl;
		cout << "------------------------------------------------------------" << endl;
	}
}
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
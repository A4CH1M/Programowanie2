#include <iostream>
#include <locale>
#include <string>
#include "functions.h"
using namespace std;


void createClient(Client**& client) {
	client = new Client*;
}
void createClient(Client**& client, const size_t size) {
	client = new Client *[size];
	for (size_t i = 0; i < size; i++) {
		client[i] = new Client;
	}
}
void insertClientData(Client* client) {
	setlocale(LC_CTYPE, "Polish");
	string tmps; int tmp;
	cout << "NIP: ";
	cin.ignore();
	getline(cin, tmps);
	client->setNip(tmps);
	cout << "Nazwa firmy: ";
	cin.ignore();
	getline(cin, tmps);
	client->setCompanyName(tmps);
	cout << "Miasto: ";
	getline(cin, tmps);
	client->setCompanyLocation(tmps);
	cout << "Warto�� umowy: ";
	cin >> tmp; client->setContractValue(tmp);
	cout << "Imi� osoby kontaktowej: ";
	cin >> tmps; client->setContactPersonName(tmps);
	cout << "Nazwisko osoby kontaktowej: ";
	cin >> tmps; client->setContactPersonSurname(tmps);
	cout << "Numer telefonu osoby kontaktowej: ";
	cin >> tmps; client->setContactPersonPhoneNumber(tmps);
	cout << "Adres email osoby kontaktowej: ";
	cin >> tmps; client->setContactPersonMail(tmps);
}
void insertClientData(Client** clients, const size_t size) {
	for (size_t i = 0; i < size; i++) {
		clients[i]->setNip(generateRandomNip());
		clients[i]->setCompanyName("Test" + to_string(i));
		clients[i]->setCompanyLocation("Szczecin");
		clients[i]->setContractValue((rand() % 100 + 1) * 100);
		clients[i]->setContactPersonName("Kontakt" + to_string(i));
		clients[i]->setContactPersonSurname("Kontaktowy" + to_string(i));
		clients[i]->setContactPersonPhoneNumber(generateRandomPhoneNumber());
		clients[i]->setContactPersonMail("test" + to_string(i) + "@test.test");
	}
}
void printClientData(Client* client) {
	if (client == nullptr)
		return;
	cout << "------------------------------------------------------------" << endl;
	cout << "NIP:                              " << client->getNip() << endl;
	cout << "Nazwa firmy:                      " << client->getCompanyName() << endl;
	cout << "Miasto:                           " << client->getCompanyLocation() << endl;
	cout << "Warto�� umowy                     " << client->getContractValue() << endl;
	cout << "Imi� osoby kontaktowej:           " << client->getContactPersonName() << endl;
	cout << "Nazwisko osoby kontaktowej:       " << client->getContactPersonSurname() << endl;
	cout << "Numer telefonu osoby kontaktowej: " << client->getContactPersonPhoneNumber() << endl;
	cout << "Adres email osoby kontaktowej:    " << client->getContactPersonMail() << endl;
	cout << "------------------------------------------------------------" << endl;
}
void printClientData(Client** client, size_t size) {
	if (client == nullptr)
		return;
	cout << "------------------------------------------------------------" << endl;
	for (size_t i = 0; i < size; i++) {
		cout << "NIP:                              " << client[i]->getNip() << endl;
		cout << "Nazwa firmy:                      " << client[i]->getCompanyName() << endl;
		cout << "Miasto:                           " << client[i]->getCompanyLocation() << endl;
		cout << "Warto�� umowy                     " << client[i]->getContractValue() << endl;
		cout << "Imi� osoby kontaktowej:           " << client[i]->getContactPersonName() << endl;
		cout << "Nazwisko osoby kontaktowej:       " << client[i]->getContactPersonSurname() << endl;
		cout << "Numer telefonu osoby kontaktowej: " << client[i]->getContactPersonPhoneNumber() << endl;
		cout << "Adres email osoby kontaktowej:    " << client[i]->getContactPersonMail() << endl;
		cout << "------------------------------------------------------------" << endl;
	}
}
void deleteClients(Client**& client, size_t& size) {
	for (int i = 0; i < size; i++)
		delete client[i];
	delete client;
	client = nullptr;
	size = 0;
}
void deleteClient(Client**& file, size_t& size, size_t index) {
	if (index < size) {
		Client** tmp = new Client *[size - 1];
		short int j = -1;
		for (size_t i = 0; i < size; ++i)
			if (i != index) {
				j++;
				tmp[j] = file[i];
			}
		delete[] file;
		file = tmp;
		size--;
	}
	else cout << "Nieprawid�owy indeks" << endl;
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
void printAverageContractValue(Client** client, size_t size) {
	setlocale(LC_CTYPE, "Polish");
	if (client == nullptr) {
		cout << "Brak klient�w";
		return;
	}
	float avg = 0;
	for (size_t i = 0; i < size; i++)
		avg = avg + client[i]->getContractValue();
	avg = avg / size;
	cout << "�rednia warto�� umowy wynosi: " << avg << endl;
}
void printContractorWithHighestContractValue(Client** client, size_t size) {
	setlocale(LC_CTYPE, "Polish");
	if (client == nullptr) {
		cout << "Brak klient�w";
		return;
	}
	size_t max = 0;
	size_t index;
	for (int i = 0; i < size; i++) {
		if (max < client[i]->getContractValue()) {
			max = client[i]->getContractValue();
			index = i;
		}
	}
	cout << "Klient z umow� o najwi�kszej warto�ci: " << client[index]->getCompanyName() << " : " << client[index]->getContractValue() << endl;
}
void printContractorWithLowestContractValue(Client** client, size_t size) {
	setlocale(LC_CTYPE, "Polish");
	if (client == nullptr) {
		cout << "Brak klient�w";
		return;
	}
	size_t min = 1000000;
	size_t index;
	for (int i = 0; i < size; i++) {
		if (min > client[i]->getContractValue()) {
			min = client[i]->getContractValue();
			index = i;
		}
	}
	cout << "Klient z umow� o najmniejszej warto�ci: " << client[index]->getCompanyName() << " : " << client[index]->getContractValue() << endl;
}
string generateRandomNip() {
	string nip;
	int r;
	for (int i = 0; i < 10; i++) {
		r = rand() % 10;
		nip = nip + to_string(r);
	}
	return nip;
}
string generateRandomPhoneNumber() {
	string pn;
	int r;
	for (int i = 0; i < 10; i++) {
		r = rand() % 10;
		pn = pn + to_string(r);
	}
	return pn;
}
void canCreateClientDatabase(Client**& clientDb, size_t size) {
	if (clientDb != nullptr) {
		cout << "Uwaga! Baza klient�w istnieje, nie mo�na stworzy� nowej." << endl;
		return;
	}
	if (size < 1) {
		cout << "Uwaga! Podstawowy rozmiar baszy klient�w nie mo�e by� mniejszy od 1." << endl;
		return;
	}
	createClient(clientDb, size);
	insertClientData(clientDb, size);
}
void addTicket(Client**& client, size_t size, size_t index) {
	if (index < 0 || index > size) {
		cout << "Nieprawid�owy indeks klienta" << endl;
		return;
	}
	client[index]->addTicket();
	client[index]->increaseNumberOfTasks();
}
void deleteTicket(Client**& client, size_t size, size_t clientIndex, size_t ticketIndex) {
	if (clientIndex < 0 || clientIndex > size) {
		cout << "Nieprawid�owy indeks klienta" << endl;
		return;
	}
	if (ticketIndex < 0 || clientIndex > size) {
		cout << "Nieprawid�owy indeks zg�oszenia" << endl;
		return;
	}
	client[clientIndex]->deleteTicket(ticketIndex);
	client[clientIndex]->decreaseNumberOfTasks();
}
void printTickets(Client**& client, size_t size) {
	if (client != nullptr) {
		for (size_t i = 0; i < size; i++) {
			cout << "============================================================" << endl;
			cout << client[i]->getCompanyName() << endl;
			client[i]->printTickets();
		}
		cout << "============================================================" << endl;
	}
}
void printTickets(Client**& client, size_t size, size_t index) {
	if (client != nullptr) {
		cout << client[index]->getCompanyName() << endl;
		client[index]->printTickets();
	}
}
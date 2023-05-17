#include <iostream>
#include <locale>
#include <string>
#include "functions.h"
using namespace std;

//void createClient(Client**& client) {
//	client = new Client*;
//}
//void createClient(Client**& client, const size_t size) {
//	client = new Client *[size];
//	for (size_t i = 0; i < size; i++) {
//		client[i] = new Client;
//	}
//}
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
	cout << "Wartoœæ umowy: ";
	cin >> tmp; client->setContractValue(tmp);
	cout << "Imiê osoby kontaktowej: ";
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
//void printClientData(Client* client) {
//	if (client == nullptr)
//		return;
//	cout << "------------------------------------------------------------" << endl;
//	cout << *client << endl;
//}
//void printClientData(Client** client, size_t size) {
//	if (client == nullptr)
//		return;
//	cout << "------------------------------------------------------------" << endl;
//	for (size_t i = 0; i < size; i++) {
//		cout << *client[i] << endl;
//	}
//}
//void deleteClients(Client**& client, size_t& size) {
//	for (int i = 0; i < size; i++)
//		delete client[i];
//	delete client;
//	client = nullptr;
//	size = 0;
//}
//void deleteClient(Client**& file, size_t& size, size_t index) {
//	if (index < size) {
//		Client** tmp = new Client *[size - 1];
//		short int j = -1;
//		for (size_t i = 0; i < size; ++i)
//			if (i != index) {
//				j++;
//				tmp[j] = file[i];
//			}
//		delete[] file;
//		file = tmp;
//		size--;
//	}
//	else cout << "Nieprawid³owy indeks" << endl;
//}
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
		cout << "Brak klientów";
		return;
	}
	float avg = 0;
	for (size_t i = 0; i < size; i++)
		avg = avg + client[i]->getContractValue();
	avg = avg / size;
	cout << "Œrednia wartoœæ umowy wynosi: " << avg << endl;
}
void printContractorWithHighestContractValue(Client** client, size_t size) {
	setlocale(LC_CTYPE, "Polish");
	if (client == nullptr) {
		cout << "Brak klientów";
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
	cout << "Klient z umow¹ o najwiêkszej wartoœci: " << client[index]->getCompanyName() << " : " << client[index]->getContractValue() << endl;
}
void printContractorWithLowestContractValue(Client** client, size_t size) {
	setlocale(LC_CTYPE, "Polish");
	if (client == nullptr) {
		cout << "Brak klientów";
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
	cout << "Klient z umow¹ o najmniejszej wartoœci: " << client[index]->getCompanyName() << " : " << client[index]->getContractValue() << endl;
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
string generateRandomPESEL() {
	string nip;
	int r;
	for (int i = 0; i < 11; i++) {
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
		cout << "Uwaga! Baza klientów istnieje, nie mo¿na stworzyæ nowej." << endl;
		return;
	}
	if (size < 1) {
		cout << "Uwaga! Podstawowy rozmiar baszy klientów nie mo¿e byæ mniejszy od 1." << endl;
		return;
	}
	//createClient(clientDb, size);
	createFromTemplate(clientDb, size);
	insertClientData(clientDb, size);
}
void addTicket(Client**& client, size_t size, size_t index) {
	if (index < 0 || index > size) {
		cout << "Nieprawid³owy indeks klienta" << endl;
		return;
	}
	client[index]->addTicket();
	client[index]->increaseNumberOfTasks();
}
void deleteTicket(Client**& client, size_t size, size_t clientIndex, size_t ticketIndex) {
	if (clientIndex < 0 || clientIndex > size) {
		cout << "Nieprawid³owy indeks klienta" << endl;
		return;
	}
	if (ticketIndex < 0 || clientIndex > size) {
		cout << "Nieprawid³owy indeks zg³oszenia" << endl;
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
void createEmployee(Employee**& employee) {
	employee = new Employee*;
}
void createEmployee(Employee**& employee, const size_t size) {
	employee = new Employee *[size];
	for (size_t i = 0; i < size; i++) {
		if (rand()%3 == 0) employee[i] = new DepartmentManager;
		else employee[i] = new ServiceTechnician;
	}
}
void insertEmployeeData(Employee** employee, const size_t size) {
	setlocale(LC_CTYPE, "Polish");
	for (size_t i = 0; i < size; i++) {
		employee[i]->setEmployeePesel(generateRandomPESEL());
		employee[i]->setEmployeeName("Jan");
		employee[i]->setEmployeeSurname("Kowalski");
		if (i % 3 == 0) employee[i]->setEmployeeDateOfEmployment("25.03.2019");
		else employee[i]->setEmployeeDateOfEmployment("25.06.2021");
	}
}
//void printEmployeeData(Employee* employee) {
//	if (employee == nullptr)
//		return;	
//	cout << *employee << endl;
//}
//void printEmployeeData(Employee** employee, const size_t size) {
//	if (employee == nullptr)
//		return;
//	cout << "------------------------------------------------------------" << endl;
//	for (size_t i = 0; i < size; i++) {
//		cout << *employee[i] << endl;
//	}
//}
//void deleteEmployees(Employee**& file, size_t& size) {
//	for (int i = 0; i < size; i++)
//		delete file[i];
//	delete file;
//	file = nullptr;
//	size = 0;
//}
//void deleteEmployee(Employee**& file, size_t& size, size_t index) {
//	if (index < size) {
//		Employee** tmp = new Employee *[size - 1];
//		short int j = -1;
//		for (size_t i = 0; i < size; ++i)
//			if (i != index) {
//				j++;
//				tmp[j] = file[i];
//			}
//		delete[] file;
//		file = tmp;
//		size--;
//	}
//	else cout << "Nieprawid³owy indeks" << endl;
//}
void addEmployee(Employee**& file, size_t& size) {
	setlocale(LC_CTYPE, "Polish");
	string tmpstr[5];
	float tmpf;
	cout << "PESEL: ";
	cin >> tmpstr[0];
	cout << "Imiê: ";
	cin >> tmpstr[1];
	cout << "Nazwisko: ";
	cin >> tmpstr[2];
	cout << "Data zatrudnienia: "; //dd.mm.rrrr inaczej siê sypie
	cin >> tmpstr[3];
	cout << "Pozycja: ";
	cin >> tmpstr[4];
	cout << "Sta¿ pracy: ";
	cin >> tmpf;
	if (tmpf < 8) tmpf = 8;

	Employee** tmp = new Employee *[size + 1];
	if (size == 0) {
		if (tmpstr[4] == "Kierownik" || tmpstr[4] == "kierownik") tmp[size] = new DepartmentManager;
		else tmp[size] = new ServiceTechnician;
	} else {
		for (size_t i = 0; i < size; ++i)
			tmp[i] = file[i];
		if (tmpstr[4] == "Kierownik" || tmpstr[4] == "kierownik") tmp[size] = new DepartmentManager;
		else tmp[size] = new ServiceTechnician;

		delete[] file;
	}
	file = tmp;
	file[size]->setEmployeePesel(tmpstr[0]);
	file[size]->setEmployeeName(tmpstr[1]);
	file[size]->setEmployeeSurname(tmpstr[1]);
	file[size]->setEmployeeDateOfEmployment(tmpstr[3]);
	file[size]->setEmployeePreviousWorkPeriod(tmpf);
	
	size++;
}
void evaluateEmployees(Employee**& file, size_t size) {
	for (size_t i = 0; i < size; i++) {
		file[i]->calculateThings();
		file[i]->virtualFunction();
	}
}
void canCreateEmployeeDatabase(Employee**& employeeDb, size_t size) {
	if (employeeDb != nullptr) {
		cout << "Uwaga! Baza pracowników istnieje, nie mo¿na stworzyæ nowej." << endl;
		return;
	}
	if (size < 1) {
		cout << "Uwaga! Podstawowy rozmiar baszy pracowników nie mo¿e byæ mniejszy od 1." << endl;
		return;
	}
	createEmployee(employeeDb, size);
	insertEmployeeData(employeeDb, size);
	evaluateEmployees(employeeDb, size);
}
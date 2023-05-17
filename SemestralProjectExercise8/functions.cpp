#include <iostream>
#include <locale>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include "functions.h"
using namespace std;

void insertData(vector<Client*> client) {
	size_t i = 0;
	for (vector<Client*>::iterator it = client.begin(); it != client.end(); it++) {
		(*it)->setNip(generateRandomNip());
		(*it)->setCompanyName("Test" + to_string(i));
		(*it)->setCompanyLocation("Szczecin");
		(*it)->setContractValue((rand() % 100 + 1) * 100);
		(*it)->setContactPersonName("Kontakt" + to_string(i));
		(*it)->setContactPersonSurname("Kontaktowy" + to_string(i));
		(*it)->setContactPersonPhoneNumber(generateRandomPhoneNumber());
		(*it)->setContactPersonMail("test" + to_string(i) + "@test.test");
		i++;
	}
}
void addClient(vector<Client*>& file) {
	setlocale(LC_CTYPE, "Polish");
	array<string, 7> tmpstr;
	int tmpi;
	cout << "NIP: ";
	cin.ignore();
	getline(cin, tmpstr[0]);
	cout << "Nazwa firmy: ";
	getline(cin, tmpstr[1]);
	cout << "Miasto: ";
	getline(cin, tmpstr[2]);
	cout << "Wartoœæ umowy: ";
	cin >> tmpi;
	cout << "Imiê osoby kontaktowej: ";
	cin >> tmpstr[3];
	cout << "Nazwisko osoby kontaktowej: ";
	cin >> tmpstr[4];
	cout << "Numer telefonu osoby kontaktowej: ";
	cin >> tmpstr[5];
	cout << "Adres email osoby kontaktowej: ";
	cin >> tmpstr[6];
	file.push_back(new Client(tmpstr[0], tmpstr[1], tmpstr[2], tmpi, tmpstr[3], tmpstr[4], tmpstr[5], tmpstr[6]));
	file.shrink_to_fit();
}
void printAverageContractValue(vector<Client*> client) {
	setlocale(LC_CTYPE, "Polish");
	if (client.empty()) {
		cout << "Brak klientów";
		return;
	}
	float avg = 0;
	for (vector<Client*>::iterator it = client.begin(); it != client.end(); it++) {
		avg = avg + (*it)->getContractValue();
	}
	avg = avg / client.size() ;
	cout << "Œrednia wartoœæ umowy wynosi: " << avg << endl;
}
void printContractorWithHighestContractValue(vector<Client*> client) {
	setlocale(LC_CTYPE, "Polish");
	if (client.empty()) {
		cout << "Brak klientów";
		return;
	}
	size_t max = 0;
	Client* key;
	for (vector<Client*>::iterator it = client.begin(); it != client.end(); it++) {
		if (max < (*it)->getContractValue()) {
			max = (*it)->getContractValue();
			key = *it;
		}
	}
	vector<Client*>::iterator highest = find(client.begin(), client.end(), key);
	cout << "Klient z umow¹ o najwiêkszej wartoœci: " << (*highest)->getCompanyName() << " : " << (*highest)->getContractValue() << endl;
}
void printContractorWithLowestContractValue(vector<Client*> client) {
	setlocale(LC_CTYPE, "Polish");
	if (client.empty()) {
		cout << "Brak klientów";
		return;
	}
	size_t min = 1000000;
	Client* key;
	for (vector<Client*>::iterator it = client.begin(); it != client.end(); it++) {
		if (min > (*it)->getContractValue()) {
			min = (*it)->getContractValue();
			key = *it;
		}
	}
	vector<Client*>::iterator lowest = find(client.begin(), client.end(), key);
	cout << "Klient z umow¹ o najmniejszej wartoœci: " << (*lowest)->getCompanyName() << " : " << (*lowest)->getContractValue() << endl;
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
void addTicket(vector<Client*>& client) {
	setlocale(LC_CTYPE, "Polish");
	if (client.empty()) return;
	size_t index;
	cout << "Podaj numer indeksu klienta, któremu chcesz dodaæ zg³oszenie: ";
	cin >> index;
	if (index < 0 || index > client.size()) {
		cout << "Nieprawid³owy indeks" << endl;
		return;
	}
	vector<Client*>::iterator it = client.begin() + index;
	(*it)->addTicket();
}
void deleteTicket(vector<Client*>& client) {
	setlocale(LC_CTYPE, "Polish");
	if (client.empty()) return;
	size_t index;
	cout << "Podaj numer indeksu klienta, któremu chcesz usun¹æ zg³oszenie: ";
	cin >> index;
	if (index < 0 || index > client.size()) {
		cout << "Nieprawid³owy indeks klienta" << endl;
		return;
	}
	vector<Client*>::iterator it = client.begin() + index;
	cout << "Podaj numer indeksu zg³oszenia, które chcesz usun¹æ: ";
	cin >> index;
	if (index < 0 || index > (*it)->getNumberOfTasks()) {
		cout << "Nieprawid³owy indeks zg³oszenia" << endl;
		return;
	}
	(*it)->deleteTicket(index);
}
void printTickets(vector<Client*>& client) {
	if (client.empty()) return;
	for (vector<Client*>::iterator it = client.begin(); it != client.end(); it++) {
		cout << "============================================================" << endl;
		cout << (*it)->getCompanyName() << endl;
		(*it)->printTickets();
	}
	cout << "============================================================" << endl;
}
void printSpecificClientsTickets(vector<Client*>& client) {
	setlocale(LC_CTYPE, "Polish");
	if (client.empty()) return;
	size_t index;
	cout << "Podaj numer indeksu klienta, którego zg³oszenia chcesz wyœwietliæ: ";
	cin >> index;
	vector<Client*>::iterator it = client.begin() + index;
	cout << (*it)->getCompanyName() << endl;
	(*it)->printTickets();
}
//-------------------------------------------------------------------------------------------------------------
void create(vector<Employee*>& employee, const size_t size) {
	for (size_t i = 0; i < size; i++) {
		if (rand() % 3 == 0) employee.push_back(new DepartmentManager());
		else employee.push_back(new ServiceTechnician());
	}
	employee.shrink_to_fit();
}
void insertData(vector<Employee*> employee) {
	setlocale(LC_CTYPE, "Polish");
	for (vector<Employee*>::iterator it = employee.begin(); it != employee.end(); it++) {
		size_t r = rand() % 3 + 1;

		(*it)->setEmployeePesel(generateRandomPESEL());
		(*it)->setEmployeeName("Jan");
		(*it)->setEmployeeSurname("Kowalski");
		if (r == 1) (*it)->setEmployeeDateOfEmployment("25.03.2019");
		else (*it)->setEmployeeDateOfEmployment("25.06.2021");
	}
}
void addEmployee(vector<Employee*>& file) {
	setlocale(LC_CTYPE, "Polish");
	array<string, 5> tmpstr;
	int tmpi;
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
	cin >> tmpi;
	if (tmpstr[4] == "Kierownik" || tmpstr[4] == "kierownik") {
		file.push_back(new DepartmentManager(tmpstr[0], tmpstr[1], tmpstr[2], tmpstr[3], tmpi));

	} else {
		file.push_back(new ServiceTechnician(tmpstr[0], tmpstr[1], tmpstr[2], tmpstr[3], tmpi));
	}
	evaluateEmployee(file, file.size() - 1);
	file.shrink_to_fit();
}
void evaluateEmployees(vector<Employee*>& file) {
	if (file.empty()) return;
	for (vector<Employee*>::iterator it = file.begin(); it != file.end(); it++) {
		(*it)->calculateThings();
		(*it)->virtualFunction();
	}
}
void evaluateEmployee(vector<Employee*>& file, size_t index) {
	if (file.empty()) return;
	vector<Employee*>::iterator it = file.begin() + index;
	(*it)->calculateThings();
	(*it)->virtualFunction();
}

#include <iostream>
#include <locale>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include "functions.h"
using namespace std;
using std::cout;


void insertData(vector<Client*> client) {
	size_t i = 0;
	for_each(client.begin(), client.end(), [&i](Client *client){
		client->setNip(generateRandomNip());
		client->setCompanyName("Test" + to_string(i));
		client->setCompanyLocation("Szczecin");
		client->setContractValue((rand() % 100 + 1) * 100);
		client->setContactPersonName("Kontakt" + to_string(i));
		client->setContactPersonSurname("Kontaktowy" + to_string(i));
		client->setContactPersonPhoneNumber(generateRandomPhoneNumber());
		client->setContactPersonMail("test" + to_string(i) + "@test.test");
		i++;
	});
}
void addClient(vector<Client*>& file) {
	setlocale(LC_CTYPE, "Polish");
	std::array<string, 7> tmpstr;
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
}
void printAverageContractValue(vector<Client*> client) {
	setlocale(LC_CTYPE, "Polish");
	if (client.empty()) {
		cout << "Brak klientów";
		return;
	}
	float avg = 0;
	for_each(client.begin(), client.end(), [&avg](Client *client) {
		avg = avg + client->getContractValue();
	});
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
	for_each(client.begin(), client.end(), [&max, &key](Client *client) {
		if (max < client->getContractValue()) {
			max = client->getContractValue();
			key = client;
		}
	});
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
	for_each(client.begin(), client.end(), [&min, &key](Client *client) {
		if (min > client->getContractValue()) {
			min = client->getContractValue();
			key = client;
		}
	});
	vector<Client*>::iterator lowest = find(client.begin(), client.end(), key);
	cout << "Klient z umow¹ o najmniejszej wartoœci: " << (*lowest)->getCompanyName() << " : " << (*lowest)->getContractValue() << endl;
}
void addTicket(vector<Client*>& client) {
	setlocale(LC_CTYPE, "Polish");
	if (client.empty()) return;
	size_t index, i = 0;
	bool flag = 0;
	cout << "Podaj numer indeksu klienta, któremu chcesz dodaæ zg³oszenie: ";
	cin >> index;

	vector<Client*>::iterator it = client.begin();
	for (it; it != client.end(); it++) {
		if (index == (*it)->getId()) {
			break;
		}
		if (i + 1 == index) {
			flag = 1;
			break;
		}
		i++;
	}
	if (i >= client.size() || flag == 1) {
		cout << "Nieprawid³owy indeks" << endl;
		return;
	}

	(*it)->addTicket();
}
void deleteTicket(vector<Client*>& client) {
	setlocale(LC_CTYPE, "Polish");
	if (client.empty()) return;
	size_t index, i = 0;
	bool flag = 0;
	cout << "Podaj numer indeksu klienta, któremu chcesz usun¹æ zg³oszenie: ";
	cin >> index;
	vector<Client*>::iterator it = client.begin();
	for (it; it != client.end(); it++) {
		if (index == (*it)->getId()) {
			break;
		}
		if (i + 1 == index) {
			flag = 1;
			break;
		}
		i++;
	}
	if (i >= client.size() || flag == 1) {
		cout << "Nieprawid³owy indeks klienta" << endl;
		return;
	}
	cout << "Podaj numer indeksu zg³oszenia, które chcesz usun¹æ: ";
	cin >> index;
	for (i = 0; i < (*it)->getNumberOfTasks(); i++) {
		if (i + 1 == index) {
			break;
		}
		if (i + 1 == index) {
			flag = 1;
			break;
		}
	}
	if (i >= (*it)->getNumberOfTasks() || flag == 1) {
		cout << "Nieprawid³owy indeks Zg³oszenia" << endl;
		return;
	}
	(*it)->deleteTicket(i);
}
void printTickets(vector<Client*>& client) {
	if (client.empty()) return;
	for (Client* i : client) {
		cout << "============================================================" << endl;
		cout << i->getCompanyName() << endl;
		i->printTickets();
	};
	cout << "============================================================" << endl;
}
//doesn't work FFS
void printSpecificClientsTickets(vector<Client*>& client) {
	setlocale(LC_CTYPE, "Polish");
	if (client.empty()) return;
	size_t index, i = 0;
	bool flag = 0;
	cout << "Podaj numer indeksu klienta, którego zg³oszenia chcesz wyœwietliæ: ";
	cin >> index;

	vector<Client*>::iterator it = client.begin();
	for (it; it != client.end(); it++) {
		if (index == (*it)->getId()) {
			break;
		}
		if (i + 1 == index) {
			flag = 1;
			break;
		}
		i++;
	}
	if (i >= client.size() || flag == 1) {
		cout << "Nieprawid³owy indeks" << endl;
		return;
	}
	cout << (*it)->getCompanyName() << endl;
	(*it)->printTickets();
}

//------------------------------------------------------------------------------------------------------------------------------------------

void create(vector<Employee*>& employee, const size_t size) {
	for (size_t i = 0; i < size; i++) {
		if (rand() % 3 == 0) employee.push_back(new DepartmentManager());
		else employee.push_back(new ServiceTechnician());
	}
}
void insertData(vector<Employee*> employee) {
	setlocale(LC_CTYPE, "Polish");
	for (Employee* i : employee) {
		size_t r = rand() % 3 + 1;

		i->setEmployeePesel(generateRandomPESEL());
		i->setEmployeeName("Jan");
		i->setEmployeeSurname("Kowalski");
		if (r == 1) i->setEmployeeDateOfEmployment("25.03.2019");
		else i->setEmployeeDateOfEmployment("25.06.2021");
	}
}
void addEmployee(vector<Employee*>& file) {
	setlocale(LC_CTYPE, "Polish");
	std::array<string, 5> tmpstr;
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
}
void evaluateEmployees(vector<Employee*>& file) {
	if (file.empty()) return;
	for (Employee* i : file) {
		i->calculateThings();
		i->virtualFunction();
	}
}
void evaluateEmployee(vector<Employee*>& file, size_t index) {
	if (file.empty()) return;
	vector<Employee*>::iterator it = file.begin() + index;
	(*it)->calculateThings();
	(*it)->virtualFunction();
}

//------------------------------------------------------------------------------------------------------------------------------------------

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
size_t assignTicketId() {
	static size_t id = 0;
	id++;
	return id;
}
size_t assignClientId() {
	static size_t id = 0;
	id++;
	return id;
}
size_t assignEmployeeId() {
	static size_t id = 0;
	id++;
	return id;
}

void closeTicket(vector<Client*> client, vector<Employee*> employee) {
	if (client.empty() || employee.empty())
		return;
	setlocale(LC_CTYPE, "Polish");
	size_t clientIndex, ticketIndex, employeeIndex, client_i = 0, ticket_i = 0, employee_i = 0;
	bool client_flag = 0, ticket_flag = 0, employee_flag = 0;
	cout << "Podaj indeks firmy, której zg³oszenie chcesz zamkn¹æ: ";
	cin >> clientIndex;
	cout << "Podaj indeks zg³oszenia, które chcesz zamkn¹æ: ";
	cin >> ticketIndex;
	cout << "Podaj indeks pracownika zamykaj¹cego zg³oszenie: ";
	cin >> employeeIndex;

	vector<Client*>::iterator itc = client.begin();
	for (itc; itc != client.end(); itc++) {
		if (clientIndex == (*itc)->getId()) {
			break;
		}
		if (client_i + 1 == clientIndex) {
			client_flag = 1;
			break;
		}
		client_i++;
	}
	if (client_i >= client.size() || client_flag == 1) {
		cout << "Nieprawid³owy indeks klienta" << endl;
		return;
	}

	for (size_t i = 0; i < (*itc)->getNumberOfTasks(); i++) {
		if (i + 1 == ticketIndex) {
			break;
		}
		if (ticket_i + 1 == employeeIndex) {
			ticket_flag = 1;
			break;
		}
		ticket_i = i;
	}
	if (ticket_i >= (*itc)->getNumberOfTasks() || ticket_flag == 1) {
		cout << "Nieprawid³owy indeks Zg³oszenia" << endl;
		return;
	}

	if ((*itc)->getTicketIsClosed(ticket_i) == 1) {
		cout << "Zg³oszenie zamkniête" << endl;
		return;
	}

	vector<Employee*>::iterator ite = employee.begin();
	for (ite; ite != employee.end(); ite++) {
		if (employeeIndex == (*ite)->getId()) {
			break;
		}
		if (employee_i + 1 == employeeIndex) {
			employee_flag = 1;
			break;
		}
		client_i++;
	}
	if (employee_i >= employee.size() || employee_flag == 1) {
		cout << "Nieprawid³owy indeks pracownika" << endl;
		return;
	}

	string serviceTechnician = (*ite)->getEmployeeName() + " " + (*ite)->getEmployeeSurname();
	(*itc)->changeTicketStatusToClosed(ticket_i, serviceTechnician);
}
#include <iostream>
#include <string>
#include <cstdlib>
#include <locale>
#include <vector>
#include "client_c.h"
#include "employee_c.h"
using namespace std;

template<class T>
void create(vector<T*>& t, size_t size) {
	for (size_t i = 0; i < size; i++)
		t.push_back(new T());
}
template<class T>
void deleteAllFromTemplate(vector<T*>& file) {
	for (auto it = file.begin(); it != file.end(); it++) {
		delete *it;
		*it = nullptr;
	}
	file.clear();
}
template<class T>
void deleteFromTemplate(vector<T*>& file) {
	setlocale(LC_CTYPE, "Polish");
	if (file.empty()) return;
	size_t index, i = 0;
	bool flag = 0;
	cout << "Podaj numer indeksu obiektu, który chcesz usun¹æ: ";
	cin >> index;
	auto it = file.begin();
	for (it; it != file.end(); it++) {
		if (index == (*it)->getId()) {
			break;
		}
		if (i + 1 == index) {
			flag = 1;
			break;
		}
		i++;
	}
	if (i >= file.size() || flag == 1) {
		cout << "Nieprawid³owy indeks" << endl;
		return;
	}
	delete *it;
	*it = nullptr;
	file.erase(file.begin() + i);
	shouldShrinkVector(file);
}
template<class T>
void printFromTemplate(vector<T*> file) {
	if (file.empty()) return;
	setlocale(LC_CTYPE, "Polish");
	cout << "------------------------------------------------------------" << endl;
	for (auto it = file.begin(); it != file.end(); it++) {
		cout << *(*it) << endl;
	}
}
template<class T>
void canCreateDatabase(vector<T*>& tDb) {
	setlocale(LC_CTYPE, "Polish");
	if (!tDb.empty()) {
		cout << "Uwaga! Baza danych ju¿ istnieje, nie mo¿na stworzyæ nowej." << endl;
		return;
	}
	size_t size;
	cout << "Ile elementów chcesz wygenerowaæ: ";
	cin >> size;
	if (size < 1) {
		cout << "Uwaga! Podstawowy rozmiar bazy danych nie mo¿e byæ mniejszy od 1." << endl;
		return;
	}
	create(tDb, size);
	insertData(tDb);
}
template<class T>
void shouldShrinkVector(vector<T*>& myVector) {
	if (myVector.capacity() - myVector.size() > 15) //to rethink
		myVector.shrink_to_fit();
}

void insertData(vector<Client*> file);
void addClient(vector<Client*>& file);
void printAverageContractValue(vector<Client*> client);
void printContractorWithHighestContractValue(vector<Client*> client);
void printContractorWithLowestContractValue(vector<Client*> client);
void addTicket(vector<Client*>& client);
void deleteTicket(vector<Client*>& client);
void printTickets(vector<Client*>& client);
void printSpecificClientsTickets(vector<Client*>& client);

void create(vector<Employee*>& employee, const size_t size);
void insertData(vector<Employee*> employee);
void addEmployee(vector<Employee*>& file);
void evaluateEmployees(vector<Employee*>& file);
void evaluateEmployee(vector<Employee*>& file, size_t index);

string generateRandomNip();
string generateRandomPhoneNumber();
string generateRandomPESEL();
size_t assignClientId();
size_t assignTicketId();
size_t assignEmployeeId();

void menu();

void closeTicket(vector<Client*> client, vector<Employee*> employee);
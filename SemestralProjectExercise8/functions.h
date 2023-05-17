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
	t.shrink_to_fit();
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
	size_t index;
	cout << "Podaj numer indeksu obiektu, który chcesz usun¹æ: ";
	cin >> index;
	if (index < file.size()) {
		auto it = (file.begin() + index);
		delete *it;
		*it = nullptr;
		file.erase(file.begin() + index);
		file.shrink_to_fit();
	}
	else cout << "B³êdny indeks" << endl;
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
	cout << "Ilu pracowników chcesz dodaæ: ";
	cin >> size;
	if (size < 1) {
		cout << "Uwaga! Podstawowy rozmiar bazy danych nie mo¿e byæ mniejszy od 1." << endl;
		return;
	}
	create(tDb, size);
	insertData(tDb);
}

void insertData(vector<Client*> file);
void addClient(vector<Client*>& file);
void printAverageContractValue(vector<Client*> client);
void printContractorWithHighestContractValue(vector<Client*> client);
void printContractorWithLowestContractValue(vector<Client*> client);

string generateRandomNip();
string generateRandomPhoneNumber();
string generateRandomPESEL();

void addTicket(vector<Client*>& client);
void deleteTicket(vector<Client*>& client);
void printTickets(vector<Client*>& client);
void printSpecificClientsTickets(vector<Client*>& client);

void create(vector<Employee*>& employee, const size_t size);
void insertData(vector<Employee*> employee);
void addEmployee(vector<Employee*>& file);
void evaluateEmployees(vector<Employee*>& file);
void evaluateEmployee(vector<Employee*>& file, size_t index);

void menu();
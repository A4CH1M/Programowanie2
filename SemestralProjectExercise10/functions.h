#include <iostream>
#include <string>
#include <cstdlib>
#include <locale>
#include <vector>
#include <array>
#include <memory>
#include <algorithm>
#include <queue>
#include "client_c.h"
#include "employee_c.h"

template<class T>
void create(std::vector<std::shared_ptr<T>>& t, size_t size) {
	t.reserve(size);
	for (size_t i = 0; i < size; i++) {
		std::shared_ptr<T> tmp = std::make_shared<T>();
		t.push_back(tmp);
	}
}
template<class T>
void deleteAllFromTemplate(std::vector<std::shared_ptr<T>>& file) {
	if (file.empty()) return;
	file.clear();
}
template<class T>
void deleteFromTemplate(std::vector<std::shared_ptr<T>>& file) {
	setlocale(LC_CTYPE, "Polish");
	if (file.empty()) return;
	size_t index, i = 0;
	bool flag = 0;
	std::cout << "Podaj numer indeksu obiektu, który chcesz usun¹æ: ";
	std::cin >> index;
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
		std::cout << "Nieprawid³owy indeks" << std::endl;
		return;
	}
	file.erase(file.begin() + i);
	shouldShrinkVector(file);
}
template<class T>
void printFromTemplate(std::vector<std::shared_ptr<T>> file) {
	if (file.empty()) return;
	setlocale(LC_CTYPE, "Polish");
	std::cout << "------------------------------------------------------------" << std::endl;
	for (auto i : file) {
		std::cout << *i << std::endl;
	};
}
template<class T>
void canCreateDatabase(std::vector<std::shared_ptr<T>>& tDb) {
	setlocale(LC_CTYPE, "Polish");
	if (!tDb.empty()) {
		std::cout << "Uwaga! Baza danych ju¿ istnieje, nie mo¿na stworzyæ nowej." << std::endl;
		return;
	}
	size_t size;
	std::cout << "Ile elementów chcesz wygenerowaæ: ";
	std::cin >> size;
	if (size < 1) {
		std::cout << "Uwaga! Podstawowy rozmiar bazy danych nie mo¿e byæ mniejszy od 1." << std::endl;
		return;
	}
	create(tDb, size);
	insertData(tDb);
}
template<class T>
void shouldShrinkVector(std::vector<std::shared_ptr<T>>& myVector) {
	if (myVector.capacity() - myVector.size() > 15)
		myVector.shrink_to_fit();
}
template<class T>
void insertMultipleUsingQueue(std::vector<std::shared_ptr<T>>& t) { // naprawiæ problem ID
	size_t size;
	std::cout << "Podaj, ilu klientów chcesz wprowadziæ: ";
	std::cin >> size;
	std::queue<T> myQueue;
	T tmp;
	std::cout << "------------------------------------------------------------" << std::endl;
	for (size_t i = 0; i < size; i++) {
		myQueue.push(insertIntoQueue(tmp));
		std::cout << "------------------------------------------------------------" << std::endl;
	}
	while (!myQueue.empty()) {
		std::shared_ptr<T> tmpShared = std::make_shared<T>(myQueue.front().getNip(), myQueue.front().getCompanyName(), myQueue.front().getCompanyLocation(), myQueue.front().getContractValue(), myQueue.front().getContactPersonName(), myQueue.front().getContactPersonSurname(), myQueue.front().getContactPersonPhoneNumber(), myQueue.front().getContactPersonMail());
		t.push_back(tmpShared);
		myQueue.pop();
	}
}

void insertData(std::vector<std::shared_ptr<Client>> file);
Client insertIntoQueue(Client& client);
void addClient(std::vector<std::shared_ptr<Client>>& file);
void printAverageContractValue(std::vector<std::shared_ptr<Client>> client);
void printContractorWithHighestContractValue(std::vector<std::shared_ptr<Client>> client);
void printContractorWithLowestContractValue(std::vector<std::shared_ptr<Client>> client);
void addTicket(std::vector<std::shared_ptr<Client>>& client);
void deleteTicket(std::vector<std::shared_ptr<Client>>& client);
void printTickets(std::vector<std::shared_ptr<Client>>& client);
void printSpecificClientsTickets(std::vector<std::shared_ptr<Client>>& client);

void create(std::vector<std::shared_ptr<Employee>>& employee, size_t size);
void insertData(std::vector<std::shared_ptr<Employee>> employee);
void addEmployee(std::vector<std::shared_ptr<Employee>>& file);
void evaluateEmployees(std::vector<std::shared_ptr<Employee>>& file);
void evaluateEmployee(std::vector<std::shared_ptr<Employee>>& file, size_t index);

std::string generateRandomNip();
std::string generateRandomPhoneNumber();
std::string generateRandomPESEL();
size_t assignClientId();
size_t assignTicketId();
size_t assignMapKey();
size_t assignEmployeeId();

void menu();

void closeTicket(std::vector<std::shared_ptr<Client>> client, std::vector<std::shared_ptr<Employee>> employee);
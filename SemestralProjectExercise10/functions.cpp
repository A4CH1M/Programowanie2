#include "functions.h"
#include <map>

void insertData(std::vector<std::shared_ptr<Client>> client) {
	size_t i = 0;
	for_each(client.begin(), client.end(), [&i](std::shared_ptr<Client>client){
		client->setNip(generateRandomNip());
		client->setCompanyName("Test" + std::to_string(i));
		client->setCompanyLocation("Szczecin");
		client->setContractValue((rand() % 100 + 1) * 100);
		client->setContactPersonName("Kontakt" + std::to_string(i));
		client->setContactPersonSurname("Kontaktowy" + std::to_string(i));
		client->setContactPersonPhoneNumber(generateRandomPhoneNumber());
		client->setContactPersonMail("test" + std::to_string(i) + "@test.test");
		i++;
	});
}
Client insertIntoQueue(Client& client) {
	setlocale(LC_CTYPE, "Polish");
	std::string tmpstr;
	int tmpi;
	std::cout << "NIP: ";
	std::cin.ignore();
	getline(std::cin, tmpstr);
	client.setNip(tmpstr);
	std::cout << "Nazwa firmy: ";
	getline(std::cin, tmpstr);
	client.setCompanyName(tmpstr);
	std::cout << "Miasto: ";
	getline(std::cin, tmpstr);
	client.setCompanyLocation(tmpstr);
	std::cout << "Wartoœæ umowy: ";
	std::cin >> tmpi;
	client.setContractValue(tmpi);
	std::cout << "Imiê osoby kontaktowej: ";
	std::cin >> tmpstr;
	client.setContactPersonName(tmpstr);
	std::cout << "Nazwisko osoby kontaktowej: ";
	std::cin >> tmpstr;
	client.setContactPersonSurname(tmpstr);
	std::cout << "Numer telefonu osoby kontaktowej: ";
	std::cin >> tmpstr;
	client.setContactPersonPhoneNumber(tmpstr);
	std::cout << "Adres email osoby kontaktowej: ";
	std::cin >> tmpstr;
	client.setContactPersonMail(tmpstr);
	return client;
}
void addClient(std::vector<std::shared_ptr<Client>>& file) {
	setlocale(LC_CTYPE, "Polish");
	std::array<std::string, 7> tmpstr;
	int tmpi;
	std::cout << "NIP: ";
	std::cin.ignore();
	getline(std::cin, tmpstr[0]);
	std::cout << "Nazwa firmy: ";
	getline(std::cin, tmpstr[1]);
	std::cout << "Miasto: ";
	getline(std::cin, tmpstr[2]);
	std::cout << "Wartoœæ umowy: ";
	std::cin >> tmpi;
	std::cout << "Imiê osoby kontaktowej: ";
	std::cin >> tmpstr[3];
	std::cout << "Nazwisko osoby kontaktowej: ";
	std::cin >> tmpstr[4];
	std::cout << "Numer telefonu osoby kontaktowej: ";
	std::cin >> tmpstr[5];
	std::cout << "Adres email osoby kontaktowej: ";
	std::cin >> tmpstr[6];
	std::shared_ptr<Client> tmp = std::make_shared<Client>(tmpstr[0], tmpstr[1], tmpstr[2], tmpi, tmpstr[3], tmpstr[4], tmpstr[5], tmpstr[6]);
	file.push_back(tmp);
}
void printAverageContractValue(std::vector<std::shared_ptr<Client>> client) {
	setlocale(LC_CTYPE, "Polish");
	if (client.empty()) {
		std::cout << "Brak klientów";
		return;
	}
	float avg = 0;
	for_each(client.begin(), client.end(), [&avg](std::shared_ptr<Client> client) {
		avg = avg + client->getContractValue();
	});
	avg = avg / client.size() ;
	std::cout << "Œrednia wartoœæ umowy wynosi: " << avg << std::endl;
}
void printContractorWithHighestContractValue(std::vector<std::shared_ptr<Client>> client) {
	setlocale(LC_CTYPE, "Polish");
	if (client.empty()) {
		std::cout << "Brak klientów";
		return;
	}
	size_t max = 0;
	std::shared_ptr<Client> key = std::make_shared<Client>();
	for_each(client.begin(), client.end(), [&max, &key](std::shared_ptr<Client> client) {
		if (max < client->getContractValue()) {
			max = client->getContractValue();
			key = client;
		}
	});
	std::vector<std::shared_ptr<Client>>::iterator highest = find(client.begin(), client.end(), key);
	std::cout << "Klient z umow¹ o najwiêkszej wartoœci: " << (*highest)->getCompanyName() << " : " << (*highest)->getContractValue() << std::endl;
}
void printContractorWithLowestContractValue(std::vector<std::shared_ptr<Client>> client) {
	setlocale(LC_CTYPE, "Polish");
	if (client.empty()) {
		std::cout << "Brak klientów";
		return;
	}
	size_t min = 1000000;
	std::shared_ptr<Client> key = std::make_shared<Client>();
	for_each(client.begin(), client.end(), [&min, &key](std::shared_ptr<Client> client) {
		if (min > client->getContractValue()) {
			min = client->getContractValue();
			key = client;
		}
	});
	std::vector<std::shared_ptr<Client>>::iterator lowest = find(client.begin(), client.end(), key);
	std::cout << "Klient z umow¹ o najmniejszej wartoœci: " << (*lowest)->getCompanyName() << " : " << (*lowest)->getContractValue() << std::endl;
}
void addTicket(std::vector<std::shared_ptr<Client>>& client) {
	setlocale(LC_CTYPE, "Polish");
	if (client.empty()) return;
	size_t index, i = 0;
	bool flag = 0;
	std::cout << "Podaj numer indeksu klienta, któremu chcesz dodaæ zg³oszenie: ";
	std::cin >> index;

	std::vector<std::shared_ptr<Client>>::iterator it = client.begin();
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
		std::cout << "Nieprawid³owy indeks" << std::endl;
		return;
	}

	(*it)->addTicket();
}
void deleteTicket(std::vector<std::shared_ptr<Client>>& client) {
	setlocale(LC_CTYPE, "Polish");
	if (client.empty()) return;
	size_t index, i = 0;
	bool flag = 0;
	std::cout << "Podaj numer indeksu klienta, któremu chcesz usun¹æ zg³oszenie: ";
	std::cin >> index;
	std::vector<std::shared_ptr<Client>>::iterator it = client.begin();
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
		std::cout << "Nieprawid³owy indeks klienta" << std::endl;
		return;
	}
	std::cout << "Podaj numer indeksu zg³oszenia, które chcesz usun¹æ: ";
	std::cin >> index;
	if ((*it)->checkIfTaskIndexIsValid(index) == false) {
		std::cout << "Nieprawid³owy indeks zg³oszenia" << std::endl;
		return;
	}
	(*it)->deleteTicket(index);
}
void printTickets(std::vector<std::shared_ptr<Client>>& client) {
	if (client.empty()) return;
	for (std::shared_ptr<Client> i : client) {
		std::cout << "============================================================" << std::endl;
		std::cout << i->getCompanyName() << std::endl;
		i->printTickets();
	};
	std::cout << "============================================================" << std::endl;
}

void printSpecificClientsTickets(std::vector<std::shared_ptr<Client>>& client) {
	setlocale(LC_CTYPE, "Polish");
	if (client.empty()) return;
	size_t index, i = 0;
	bool flag = 0;
	std::cout << "Podaj numer indeksu klienta, którego zg³oszenia chcesz wyœwietliæ: ";
	std::cin >> index;

	std::vector<std::shared_ptr<Client>>::iterator it = client.begin();
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
		std::cout << "Nieprawid³owy indeks" << std::endl;
		return;
	}
	std::cout << (*it)->getCompanyName() << std::endl;
	(*it)->printTickets();
}

//------------------------------------------------------------------------------------------------------------------------------------------

void create(std::vector<std::shared_ptr<Employee>>& employee, const size_t size) {
	for (size_t i = 0; i < size; i++) {	
		if (rand() % 3 == 0) {
			std::shared_ptr<DepartmentManager> tmp = std::make_shared<DepartmentManager>();
			employee.push_back(tmp);
		} else {
			std::shared_ptr<ServiceTechnician> tmp = std::make_shared<ServiceTechnician>();
			employee.push_back(tmp);
		}
	}
}
void insertData(std::vector<std::shared_ptr<Employee>> employee) {
	setlocale(LC_CTYPE, "Polish");
	for (std::shared_ptr<Employee> i : employee) {
		size_t r = rand() % 3 + 1;
		i->setEmployeePesel(generateRandomPESEL());
		i->setEmployeeName("Jan");
		i->setEmployeeSurname("Kowalski");
		if (r == 1) i->setEmployeeDateOfEmployment("25.03.2019");
		else i->setEmployeeDateOfEmployment("25.06.2021");
	}
}
void addEmployee(std::vector<std::shared_ptr<Employee>>& file) {
	setlocale(LC_CTYPE, "Polish");
	std::array<std::string, 5> tmpstr;
	int tmpi;
	std::cout << "PESEL: ";
	std::cin >> tmpstr[0];
	std::cout << "Imiê: ";
	std::cin >> tmpstr[1];
	std::cout << "Nazwisko: ";
	std::cin >> tmpstr[2];
	std::cout << "Data zatrudnienia: "; //dd.mm.rrrr inaczej siê sypie
	std::cin >> tmpstr[3];
	std::cout << "Pozycja: ";
	std::cin >> tmpstr[4];
	std::cout << "Sta¿ pracy: ";
	std::cin >> tmpi;
	if (tmpstr[4] == "Kierownik" || tmpstr[4] == "kierownik") {
		std::shared_ptr<DepartmentManager> tmp = std::make_shared<DepartmentManager>(tmpstr[0], tmpstr[1], tmpstr[2], tmpstr[3], tmpi);
		file.push_back(tmp);
	} else {
		std::shared_ptr<ServiceTechnician> tmp = std::make_shared<ServiceTechnician>(tmpstr[0], tmpstr[1], tmpstr[2], tmpstr[3], tmpi);
		file.push_back(tmp);
	}
	evaluateEmployee(file, file.size() - 1);
}
void evaluateEmployees(std::vector<std::shared_ptr<Employee>>& file) {
	if (file.empty()) return;
	for (std::shared_ptr<Employee> i : file) {
		i->calculateThings();
		i->virtualFunction();
	}
}
void evaluateEmployee(std::vector<std::shared_ptr<Employee>>& file, size_t index) {
	if (file.empty()) return;
	std::vector<std::shared_ptr<Employee>>::iterator it = file.begin() + index;
	(*it)->calculateThings();
	(*it)->virtualFunction();
}

//------------------------------------------------------------------------------------------------------------------------------------------

std::string generateRandomNip() {
	std::string nip;
	int r;
	for (int i = 0; i < 10; i++) {
		r = rand() % 10;
		nip = nip + std::to_string(r);
	}
	return nip;
}
std::string generateRandomPESEL() {
	std::string nip;
	int r;
	for (int i = 0; i < 11; i++) {
		r = rand() % 10;
		nip = nip + std::to_string(r);
	}
	return nip;
}
std::string generateRandomPhoneNumber() {
	std::string pn;
	int r;
	for (int i = 0; i < 10; i++) {
		r = rand() % 10;
		pn = pn + std::to_string(r);
	}
	return pn;
}
size_t assignTicketId() {
	static size_t id = 0;
	id++;
	return id;
}
size_t assignMapKey() {
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

void closeTicket(std::vector<std::shared_ptr<Client>> client, std::vector<std::shared_ptr<Employee>> employee) {
	if (client.empty() || employee.empty())
		return;
	setlocale(LC_CTYPE, "Polish");
	size_t clientIndex, ticketIndex, employeeIndex, client_i = 0, ticket_i = 0, employee_i = 0;
	bool client_flag = 0, ticket_flag = 0, employee_flag = 0;
	std::cout << "Podaj indeks klienta, którego zg³oszenie chcesz zamkn¹æ: ";
	std::cin >> clientIndex;
	std::cout << "Podaj indeks zg³oszenia, które chcesz zamkn¹æ: ";
	std::cin >> ticketIndex;
	std::cout << "Podaj indeks pracownika zamykaj¹cego zg³oszenie: ";
	std::cin >> employeeIndex;

	std::vector<std::shared_ptr<Client>>::iterator itc = client.begin();
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
		std::cout << "Nieprawid³owy indeks klienta" << std::endl;
		return;
	}
	
	if ((*itc)->checkIfTaskIndexIsValid(ticketIndex) == false) {
		std::cout << "Nieprawid³owy indeks zg³oszenia" << std::endl;
		return;
	}

	if ((*itc)->getTicketIsClosed(ticketIndex) == true) {
		std::cout << "Zg³oszenie zamkniête" << std::endl;
		return;
	}

	std::vector<std::shared_ptr<Employee>>::iterator ite = employee.begin();
	for (ite; ite != employee.end(); ite++) {
		if (employeeIndex == (*ite)->getId()) {
			break;
		}
		if (employee_i + 1 == employeeIndex) {
			employee_flag = 1;
			break;
		}
		employee_i++;
	}
	if (employee_i >= employee.size() || employee_flag == 1) {
		std::cout << "Nieprawid³owy indeks pracownika" << std::endl;
		return;
	}

	std::string serviceTechnician = (*ite)->getEmployeeName() + " " + (*ite)->getEmployeeSurname();
	(*itc)->changeTicketStatusToClosed(ticketIndex, serviceTechnician);
}
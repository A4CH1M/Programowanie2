#include <iostream>
#include <locale>
#include <string>
#include "client.h"
//#include "functions.h"
using namespace std;

Client::Client() : id{ rand() % 100 + 1 } { createTickets(this->taskList, this->numberOfTasks); }
Client::Client(string nip, string companyName, size_t contractValue, string companyLocation, string contactPersonName, string contactPersonSurname, string contactPersonPhoneNumber, string contactPersonMail, Ticket** taskList, size_t numberOfTasks) : id{ rand() % 100 + 1 } {
	this->companyName = companyName;
	this->contractValue = contractValue;
	this->companyLocation = companyLocation;
	this->contactPersonName = contactPersonName;
	this->contactPersonSurname = contactPersonSurname;
	this->contactPersonPhoneNumber = contactPersonPhoneNumber;
	this->contactPersonMail = contactPersonMail;
	createTickets(taskList, numberOfTasks);
}

Client::~Client() {
	deleteTickets(taskList, numberOfTasks);
}

Client::Client(const Client& client) : id{ id } {
	nip = client.nip;
	companyName = companyName;
	companyName = client.companyName;
	companyLocation = client.companyLocation;
	contractValue = client.contractValue;
	contactPersonName = client.contactPersonName;
	contactPersonSurname = client.contactPersonSurname;
	contactPersonPhoneNumber = client.contactPersonPhoneNumber;
	contactPersonMail = client.contactPersonMail;
	numberOfTasks = client.numberOfTasks;
	createTickets(taskList, numberOfTasks);
	for (size_t i = 0; i < numberOfTasks; i++) {
		taskList[i]->setTopic(client.taskList[i]->getTopic());
		taskList[i]->setTicketContent(client.taskList[i]->getTicketContent());
		taskList[i]->setCategory(client.taskList[i]->getCategory());
		taskList[i]->setQueue(client.taskList[i]->getQueue());
		taskList[i]->setIsDone(client.taskList[i]->getIsDone());
	}
}

Client::Ticket::Ticket() : id{ rand() % 100 + 1 } {}
Client::Ticket::Ticket(string topic, string ticketContent, string category, string queue, bool isDone) : id{ rand() % 100 + 1 } {
	this->topic = topic;
	this->ticketContent = ticketContent;
	this->category = category;
	this->queue = queue;
}

void Client::setNip(string nip) { this->nip = nip; }
void Client::setCompanyName(string companyName) { this->companyName = companyName; }
void Client::setCompanyLocation(string CompanyLocation) { this->companyLocation = CompanyLocation; }
void Client::setContractValue(size_t contractValue) { this->contractValue = contractValue; }
void Client::setContactPersonName(string ContactPersonName) { this->contactPersonName = ContactPersonName; }
void Client::setContactPersonSurname(string ContactPersonSurname) { this->contactPersonSurname = ContactPersonSurname; }
void Client::setContactPersonPhoneNumber(string ContactPersonPhoneNumber) { this->contactPersonPhoneNumber = ContactPersonPhoneNumber; }
void Client::setContactPersonMail(string ContactPersonMail) { this->contactPersonMail = ContactPersonMail; }

int Client::getId() { return id; }
string Client::getNip() { return nip; }
string Client::getCompanyName() { return companyName; }
size_t Client::getContractValue() { return contractValue; }
string Client::getCompanyLocation() { return companyLocation; }
string Client::getContactPersonName() { return contactPersonName; }
string Client::getContactPersonSurname() { return contactPersonSurname; }
string Client::getContactPersonPhoneNumber() { return contactPersonPhoneNumber; }
string Client::getContactPersonMail() { return contactPersonMail; }
size_t Client::getNumberOfTasks() { return numberOfTasks; }

void Client::Ticket::setTopic(string topic) { this->topic = topic; }
void Client::Ticket::setTicketContent(string ticketContent) { this->ticketContent = ticketContent; }
void Client::Ticket::setCategory(string category) { this->category = category; }
void Client::Ticket::setQueue(string queue) { this->queue = queue; }
void Client::Ticket::setIsDone(size_t i) {
	if (i > 0) this->isDone = 1;
	else this->isDone = 0;
}

int Client::Ticket::getId() { return id; }
string Client::Ticket::getTopic() { return topic; }
string Client::Ticket::getTicketContent() { return ticketContent; }
string Client::Ticket::getCategory() { return category; }
string Client::Ticket::getQueue() { return queue; }
bool Client::Ticket::getIsDone() { return isDone; }

void Client::increaseNumberOfTasks() { numberOfTasks++; }
void Client::decreaseNumberOfTasks() { numberOfTasks--; }

Client& Client::operator=(const Client& client) {
	if (&client != this) {
		deleteTickets(taskList, numberOfTasks);
		createTickets(taskList, client.numberOfTasks);
		for (size_t i = 0; i < client.numberOfTasks; i++) {
			taskList[i]->setTicketContent(client.taskList[i]->getTicketContent());
			taskList[i]->setTopic(client.taskList[i]->getTopic());
			taskList[i]->setCategory(client.taskList[i]->getCategory());
			taskList[i]->setQueue(client.taskList[i]->getQueue());
			taskList[i]->setIsDone(client.taskList[i]->getIsDone());
		}
		return *this;
	}
}
void Client::createTickets(Ticket**& tickets, size_t size) {
	tickets = new Ticket *[size];
	for (size_t i = 0; i < size; i++) {
		tickets[i] = new Ticket;
	}
}
void Client::addTicket() {
	Ticket** tmp = new Ticket *[numberOfTasks + 1];
	if (numberOfTasks == 0) { tmp[numberOfTasks] = new Ticket; }
	else {
		for (size_t i = 0; i < numberOfTasks; i++)
			tmp[i] = taskList[i];
		tmp[numberOfTasks] = new Ticket;
		delete[] taskList;
	}
	taskList = tmp;
	insertTicketContent(taskList[numberOfTasks]);
}
void Client::insertTicketContent(Ticket* ticket) {
	setlocale(LC_CTYPE, "Polish");
	string tmp;
	cout << "Tytu³ zg³oszenia: ";
	cin.ignore();
	getline(cin, tmp);
	ticket->setTopic(tmp);
	cout << "Treœæ: ";
	cin.ignore();
	getline(cin, tmp);
	ticket->setTicketContent(tmp);
	cout << "Kategoria: ";
	cin.ignore();
	getline(cin, tmp);
	ticket->setCategory(tmp);
	cout << "Kolejka: ";
	cin >> tmp;
	ticket->setQueue(tmp);
}

void Client::deleteTicket(size_t index) {
	if (index < numberOfTasks) {
		Ticket** tmp = new Ticket *[numberOfTasks - 1];
		short j = -1;
		for (size_t i = 0; i < numberOfTasks; i++)
			if (i != index) {
				j++;
				tmp[j] = taskList[i];
			}
		delete[] taskList;
		taskList = tmp;
	}
	else cout << "Nieprawid³owy indeks" << endl;
}

void Client::deleteTickets(Ticket**& tickets, size_t size) {
	for (size_t i = 0; i < size; i++)
		delete tickets[i];
	delete tickets;
	tickets = nullptr;
}

void Client::printTickets() {
	setlocale(LC_CTYPE, "Polish");
	if (taskList == nullptr)
		return;
	cout << "------------------------------------------------------------" << endl;
	for (size_t i = 0; i < numberOfTasks; i++) {
		cout << "Numer zg³oszenia:  " << taskList[i]->getId() << endl;
		cout << "Temat:             " << taskList[i]->getTopic() << endl;
		cout << "Treœæ:             " << taskList[i]->getTicketContent() << endl;
		cout << "Kategoria:         " << taskList[i]->getCategory() << endl;
		cout << "Kolejka:           " << taskList[i]->getQueue() << endl;
		if (taskList[i]->getIsDone() == 1) {
			cout << "Status zg³oszenia: Zamkniête" << endl;
		} else {
			cout << "Status zg³oszenia: W trakcie realizacji" << endl;
		}
		cout << "------------------------------------------------------------" << endl;
	}
}



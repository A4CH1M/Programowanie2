#include <iostream>
#include <locale>
#include <string>
#include "client_c.h"
#include "employee_c.h"
#include "functions.h"
using namespace std;

Client::Client() : id{ assignClientId() } { createTickets(this->taskList, this->numberOfTasks); }
Client::Client(string nip, string companyName, string companyLocation, size_t contractValue, string contactPersonName, string contactPersonSurname, string contactPersonPhoneNumber, string contactPersonMail) : id{ assignClientId() } {
	this->nip = nip;
	this->companyName = companyName;
	this->companyLocation = companyLocation;
	this->contractValue = contractValue;
	this->contactPersonName = contactPersonName;
	this->contactPersonSurname = contactPersonSurname;
	this->contactPersonPhoneNumber = contactPersonPhoneNumber;
	this->contactPersonMail = contactPersonMail;
	createTickets(this->taskList, this->numberOfTasks);
}
Client::~Client() {
	deleteTickets(this->taskList, this->numberOfTasks);
}
Client::Client(const Client& client) : id{ id } {
	this->nip = client.nip;
	this->companyName = companyName;
	this->companyName = client.companyName;
	this->companyLocation = client.companyLocation;
	this->contractValue = client.contractValue;
	this->contactPersonName = client.contactPersonName;
	this->contactPersonSurname = client.contactPersonSurname;
	this->contactPersonPhoneNumber = client.contactPersonPhoneNumber;
	this->contactPersonMail = client.contactPersonMail;
	this->numberOfTasks = client.numberOfTasks;
	createTickets(this->taskList, this->numberOfTasks);
	for (size_t i = 0; i < numberOfTasks; i++) {
		taskList[i]->setTopic(client.taskList[i]->getTopic());
		taskList[i]->setTicketContent(client.taskList[i]->getTicketContent());
		taskList[i]->setCategory(client.taskList[i]->getCategory());
		taskList[i]->setQueue(client.taskList[i]->getQueue());
		taskList[i]->setIsClosed(client.taskList[i]->getIsClosed());
	}
}

void Client::setNip(string nip) { this->nip = nip; }
void Client::setCompanyName(string companyName) { this->companyName = companyName; }
void Client::setCompanyLocation(string CompanyLocation) { this->companyLocation = CompanyLocation; }
void Client::setContractValue(size_t contractValue) { this->contractValue = contractValue; }
void Client::setContactPersonName(string ContactPersonName) { this->contactPersonName = ContactPersonName; }
void Client::setContactPersonSurname(string ContactPersonSurname) { this->contactPersonSurname = ContactPersonSurname; }
void Client::setContactPersonPhoneNumber(string ContactPersonPhoneNumber) { this->contactPersonPhoneNumber = ContactPersonPhoneNumber; }
void Client::setContactPersonMail(string ContactPersonMail) { this->contactPersonMail = ContactPersonMail; }

size_t Client::getId() { return id; }
string Client::getNip() { return nip; }
string Client::getCompanyName() { return companyName; }
size_t Client::getContractValue() { return contractValue; }
string Client::getCompanyLocation() { return companyLocation; }
string Client::getContactPersonName() { return contactPersonName; }
string Client::getContactPersonSurname() { return contactPersonSurname; }
string Client::getContactPersonPhoneNumber() { return contactPersonPhoneNumber; }
string Client::getContactPersonMail() { return contactPersonMail; }
size_t Client::getNumberOfTasks() { return numberOfTasks; }
bool Client::getTicketIsClosed(size_t ticketIndex) { return taskList[ticketIndex]->getIsClosed(); }

void Client::increaseNumberOfTasks() { numberOfTasks++; }
void Client::decreaseNumberOfTasks() { numberOfTasks--; }

Client::Ticket::Ticket() : id{ assignTicketId() } {}
Client::Ticket::Ticket(string topic, string ticketContent, string category, string queue) : id{ assignTicketId() } {
	this->topic = topic;
	this->ticketContent = ticketContent;
	this->category = category;
	this->queue = queue;
}

void Client::Ticket::setTopic(string topic) { this->topic = topic; }
void Client::Ticket::setTicketContent(string ticketContent) { this->ticketContent = ticketContent; }
void Client::Ticket::setCategory(string category) { this->category = category; }
void Client::Ticket::setQueue(string queue) { this->queue = queue; }
void Client::Ticket::setIsClosed(bool i) {
	this->isClosed = i;
}
void Client::Ticket::setClosedBy(string closedBy) { this->closedBy = closedBy; }
void Client::Ticket::setComment(string comment) { this->comment = comment; }

int Client::Ticket::getId() { return id; }
string Client::Ticket::getTopic() { return topic; }
string Client::Ticket::getTicketContent() { return ticketContent; }
string Client::Ticket::getCategory() { return category; }
string Client::Ticket::getQueue() { return queue; }
bool Client::Ticket::getIsClosed() { return isClosed; }
string Client::Ticket::getClosedBy() { return closedBy; }
string Client::Ticket::getComment() { return comment; }

Client& Client::operator=(const Client& client) {
	if (&client != this) {
		deleteTickets(taskList, numberOfTasks);
		createTickets(taskList, client.numberOfTasks);
		for (size_t i = 0; i < client.numberOfTasks; i++) {
			taskList[i]->setTicketContent(client.taskList[i]->getTicketContent());
			taskList[i]->setTopic(client.taskList[i]->getTopic());
			taskList[i]->setCategory(client.taskList[i]->getCategory());
			taskList[i]->setQueue(client.taskList[i]->getQueue());
			taskList[i]->setIsClosed(client.taskList[i]->getIsClosed());
		}
		nip = client.nip;
		companyName = client.companyName;
		companyLocation = client.companyLocation;
		contractValue = client.contractValue;
		contactPersonName = client.contactPersonName;
		contactPersonSurname = client.contactPersonSurname;
		contactPersonPhoneNumber = contactPersonPhoneNumber;
		contactPersonMail = client.contactPersonMail;
		numberOfTasks = client.numberOfTasks;

		return *this;
	}
}

Client::Ticket Client::Ticket::operator=(const Ticket& ticket) {
	topic = ticket.topic;
	ticketContent = ticket.ticketContent;
	category = ticket.category;
	queue = ticket.queue;
	isClosed = ticket.isClosed;

	return *this;
}
ostream& operator<<(ostream& output, Client& client) {
	output << "ID:                               " << client.getId() << endl
		<< "NIP:                              " << client.getNip() << endl
		<< "Nazwa firmy:                      " << client.getCompanyName() << endl
		<< "Miasto:                           " << client.getCompanyLocation() << endl
		<< "Wartoœæ umowy                     " << client.getContractValue() << endl
		<< "Imiê osoby kontaktowej:           " << client.getContactPersonName() << endl
		<< "Nazwisko osoby kontaktowej:       " << client.getContactPersonSurname() << endl
		<< "Numer telefonu osoby kontaktowej: " << client.getContactPersonPhoneNumber() << endl
		<< "Adres email osoby kontaktowej:    " << client.getContactPersonMail() << endl
		<< "------------------------------------------------------------";
	return output;
}

ostream& operator<<(ostream& output, Client::Ticket& ticket) {
	string tmp;
	if (ticket.getIsClosed() == 1) {
		tmp = "Zamkniête";
	} else {
		tmp = "W trakcie realizacji";
	}
	output	<< "Numer zg³oszenia:  " << ticket.getId() << endl
		<< "Temat:             " << ticket.getTopic() << endl
		<< "Treœæ:             " << ticket.getTicketContent() << endl
		<< "Kategoria:         " << ticket.getCategory() << endl
		<< "Kolejka:           " << ticket.getQueue() << endl
		<< "Status zg³oszenia: " << tmp << endl
		<< "Komentarz:         " << ticket.getComment() << endl
		<< "------------------------------------------------------------";
	return output;
}
Client::Ticket& Client::operator[](size_t index) {
	if (index > numberOfTasks) {
		cout << "B³êdny indeks" << endl;
		exit(0);
	}
	return *taskList[index];
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
	increaseNumberOfTasks();
}
void Client::insertTicketContent(Ticket* ticket) {
	setlocale(LC_CTYPE, "Polish");
	string tmpStr;
	cin.ignore();
	cout << "Tytu³ zg³oszenia: ";
	getline(cin, tmpStr);
	ticket->setTopic(tmpStr);
	cout << "Treœæ: ";
	getline(cin, tmpStr);
	ticket->setTicketContent(tmpStr);
	cout << "Kategoria: ";
	getline(cin, tmpStr);
	ticket->setCategory(tmpStr);
	cout << "Kolejka: ";
	cin >> tmpStr;
	ticket->setQueue(tmpStr);
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
		decreaseNumberOfTasks();
	}
	else cout << "Nieprawid³owy indeks" << endl;
}

void Client::deleteTickets(Ticket**& tickets, size_t& size) {
	for (size_t i = 0; i < size; i++)
		delete tickets[i];
	delete [] tickets;
	tickets = nullptr;
	size = 0;
}

void Client::printTickets() {
	setlocale(LC_CTYPE, "Polish");
	if (taskList == nullptr)
		return;
	cout << "------------------------------------------------------------" << endl;
	for (size_t i = 0; i < numberOfTasks; i++) {
		cout << *taskList[i] << endl;
	}
}
void Client::changeTicketStatusToClosed(size_t index, string serviceTechnician) {
	if (index > numberOfTasks)
		return;
	string comment;
	cout << "Komentarz do zg³oszenia: ";
	cin.ignore();
	getline(cin, comment);
	taskList[index]->setIsClosed(true);
	taskList[index]->setClosedBy(serviceTechnician);
	taskList[index]->setComment(comment);
}
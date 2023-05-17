#include <iostream>
#include <locale>
#include <string>
#include "client_c.h"
#include "employee_c.h"
#include "functions.h"

Client::Client() : id{ assignClientId() } {}
Client::Client(std::string nip, std::string companyName, std::string companyLocation, size_t contractValue, std::string contactPersonName, std::string contactPersonSurname, std::string contactPersonPhoneNumber, std::string contactPersonMail) : id{ assignClientId() } {
	this->nip = nip;
	this->companyName = companyName;
	this->companyLocation = companyLocation;
	this->contractValue = contractValue;
	this->contactPersonName = contactPersonName;
	this->contactPersonSurname = contactPersonSurname;
	this->contactPersonPhoneNumber = contactPersonPhoneNumber;
	this->contactPersonMail = contactPersonMail;
}
Client::~Client() {}
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
	std::copy(client.taskList.begin(), client.taskList.end(), std::inserter(this->taskList, this->taskList.end()));
}

void Client::setNip(std::string nip) { this->nip = nip; }
void Client::setCompanyName(std::string companyName) { this->companyName = companyName; }
void Client::setCompanyLocation(std::string CompanyLocation) { this->companyLocation = CompanyLocation; }
void Client::setContractValue(size_t contractValue) { this->contractValue = contractValue; }
void Client::setContactPersonName(std::string ContactPersonName) { this->contactPersonName = ContactPersonName; }
void Client::setContactPersonSurname(std::string ContactPersonSurname) { this->contactPersonSurname = ContactPersonSurname; }
void Client::setContactPersonPhoneNumber(std::string ContactPersonPhoneNumber) { this->contactPersonPhoneNumber = ContactPersonPhoneNumber; }
void Client::setContactPersonMail(std::string ContactPersonMail) { this->contactPersonMail = ContactPersonMail; }

size_t Client::getId() { return id; }
std::string Client::getNip() { return nip; }
std::string Client::getCompanyName() { return companyName; }
size_t Client::getContractValue() { return contractValue; }
std::string Client::getCompanyLocation() { return companyLocation; }
std::string Client::getContactPersonName() { return contactPersonName; }
std::string Client::getContactPersonSurname() { return contactPersonSurname; }
std::string Client::getContactPersonPhoneNumber() { return contactPersonPhoneNumber; }
std::string Client::getContactPersonMail() { return contactPersonMail; }
size_t Client::getNumberOfTasks() { return numberOfTasks; }
bool Client::getTicketIsClosed(size_t ticketIndex) { return taskList.find(ticketIndex)->second->getIsClosed(); }

bool Client::checkIfTaskIndexIsValid(size_t index) {
	if (taskList.count(index) == 0) return false;
	return true;
}

void Client::increaseNumberOfTasks() { numberOfTasks++; }
void Client::decreaseNumberOfTasks() { numberOfTasks--; }

Client::Ticket::Ticket() : id{ assignTicketId() } {}
Client::Ticket::Ticket(std::string topic, std::string ticketContent, std::string category, std::string queue) : id{ assignTicketId() } {
	this->topic = topic;
	this->ticketContent = ticketContent;
	this->category = category;
	this->queue = queue;
}

void Client::Ticket::setTopic(std::string topic) { this->topic = topic; }
void Client::Ticket::setTicketContent(std::string ticketContent) { this->ticketContent = ticketContent; }
void Client::Ticket::setCategory(std::string category) { this->category = category; }
void Client::Ticket::setQueue(std::string queue) { this->queue = queue; }
void Client::Ticket::setIsClosed(bool i) { this->isClosed = i; }
void Client::Ticket::setClosedBy(std::string closedBy) { this->closedBy = closedBy; }
void Client::Ticket::setComment(std::string comment) { this->comment = comment; }

int Client::Ticket::getId() { return id; }
std::string Client::Ticket::getTopic() { return topic; }
std::string Client::Ticket::getTicketContent() { return ticketContent; }
std::string Client::Ticket::getCategory() { return category; }
std::string Client::Ticket::getQueue() { return queue; }
bool Client::Ticket::getIsClosed() { return isClosed; }
std::string Client::Ticket::getClosedBy() { return closedBy; }
std::string Client::Ticket::getComment() { return comment; }

Client& Client::operator=(const Client& client) {
	if (&client != this) {
		//taskList.swap(client.taskList); aaaaaaaaaaaaaaaaaaaaa
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
	closedBy = ticket.closedBy;
	comment = ticket.comment;

	return *this;
}
std::ostream& operator<<(std::ostream& output, Client& client) {
	output << "ID:                               " << client.getId() << std::endl
		<< "NIP:                              " << client.getNip() << std::endl
		<< "Nazwa firmy:                      " << client.getCompanyName() << std::endl
		<< "Miasto:                           " << client.getCompanyLocation() << std::endl
		<< "Wartoœæ umowy                     " << client.getContractValue() << std::endl
		<< "Imiê osoby kontaktowej:           " << client.getContactPersonName() << std::endl
		<< "Nazwisko osoby kontaktowej:       " << client.getContactPersonSurname() << std::endl
		<< "Numer telefonu osoby kontaktowej: " << client.getContactPersonPhoneNumber() << std::endl
		<< "Adres email osoby kontaktowej:    " << client.getContactPersonMail() << std::endl
		<< "------------------------------------------------------------";
	return output;
}

std::ostream& operator<<(std::ostream& output, Client::Ticket& ticket) {
	std::string tmp;
	if (ticket.getIsClosed() == 1) {
		tmp = "Zamkniête";
	} else {
		tmp = "W trakcie realizacji";
	}
	output	<< "Numer zg³oszenia:  " << ticket.getId() << std::endl
		<< "Temat:             " << ticket.getTopic() << std::endl
		<< "Treœæ:             " << ticket.getTicketContent() << std::endl
		<< "Kategoria:         " << ticket.getCategory() << std::endl
		<< "Kolejka:           " << ticket.getQueue() << std::endl
		<< "Status zg³oszenia: " << tmp << std::endl
		<< "Komentarz:         " << ticket.getComment() << std::endl
		<< "------------------------------------------------------------";
	return output;
}
/*
Client::Ticket& Client::operator[](size_t index) {
	if (index > numberOfTasks) {
		std::cout << "B³êdny indeks" << std::endl;
		exit(0);
	}
	return taskList[index];
}
*/
void Client::addTicket() {
	std::shared_ptr<Ticket> newTicket = std::make_shared<Ticket>();
	size_t x = assignMapKey();
	taskList.insert(std::make_pair(x, newTicket));
	auto it = taskList.find(x);
	insertTicketContent((*it).second);
	increaseNumberOfTasks();
}
void Client::insertTicketContent(std::shared_ptr<Ticket> ticket) {
	setlocale(LC_CTYPE, "Polish");
	std::string tmpStr;
	std::cin.ignore();
	std::cout << "Tytu³ zg³oszenia: ";
	std::getline(std::cin, tmpStr);
	ticket->setTopic(tmpStr);
	std::cout << "Treœæ: ";
	std::getline(std::cin, tmpStr);
	ticket->setTicketContent(tmpStr);
	std::cout << "Kategoria: ";
	std::getline(std::cin, tmpStr);
	ticket->setCategory(tmpStr);
	std::cout << "Kolejka: ";
	std::cin >> tmpStr;
	ticket->setQueue(tmpStr);
}
void Client::deleteTicket(size_t index) {
	if (taskList.count(index) == 0) std::cout << "Nieprawid³owy indeks" << std::endl;
	taskList.erase(index);
	decreaseNumberOfTasks();
}
void Client::printTickets() {
	setlocale(LC_CTYPE, "Polish");
	if (taskList.empty())
		return;
	std::cout << "------------------------------------------------------------" << std::endl;
	for (auto i : taskList) {
		std::cout << *i.second << std::endl;
	}
}
void Client::changeTicketStatusToClosed(size_t index, std::string serviceTechnician) {
	std::string comment;
	std::cout << "Komentarz do zg³oszenia: ";
	std::cin.ignore();
	std::getline(std::cin, comment);
	taskList.at(index)->setIsClosed(true);
	taskList.at(index)->setClosedBy(serviceTechnician);
	taskList.at(index)->setComment(comment);
}
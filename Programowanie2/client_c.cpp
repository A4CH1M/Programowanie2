#include <iostream>
#include <locale>
#include <string>
#include "client_c.h"
#include "functions.h"
using namespace std;

Client::Client() : id{ rand() % 100 + 1 } {}
Client::Client(string nip, string companyName, size_t contractValue, string companyLocation, string contactPersonName, string contactPersonSurname, string contactPersonPhoneNumber, string contactPersonMail, Ticket** taskList, size_t numberOfTasks) : id{ rand() % 100 + 1 } {
	this->nip = nip;
	this->companyName = companyName;
	this->contractValue = contractValue;
	this->companyLocation = companyLocation;
	this->contactPersonName = contactPersonName;
	this->contactPersonSurname = contactPersonSurname;
	this->contactPersonPhoneNumber = contactPersonPhoneNumber;
	this->contactPersonMail = contactPersonMail;
	createTicket(this->taskList, this->numberOfTasks);
}

Client::~Client() {
	deleteTickets(this->taskList, this->numberOfTasks);
}

Client::Client(const Client& client) : id{ id } {
	this->nip = client.nip;
	this->companyName = client.companyName;
	this->companyLocation = client.companyLocation;
	this->contractValue = client.contractValue;
	this->contactPersonName = client.contactPersonName;
	this->contactPersonSurname = client.contactPersonSurname;
	this->contactPersonPhoneNumber = client.contactPersonPhoneNumber;
	this->contactPersonMail = client.contactPersonMail;
	createTicket(this->taskList, this->numberOfTasks);
	for (size_t i = 0; i < numberOfTasks; i++) {
		taskList[i]->setShortCompanyName(client.taskList[i]->getShortCompanyName());
		taskList[i]->setTicketContent(client.taskList[i]->getTicketContent());
		taskList[i]->setTopic(client.taskList[i]->getTopic());
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

string Client::getNip() { return nip; }
string Client::getCompanyName() { return companyName; }
size_t Client::getContractValue() { return contractValue; }
string Client::getCompanyLocation() { return companyLocation; }
string Client::getContactPersonName() { return contactPersonName; }
string Client::getContactPersonSurname() { return contactPersonSurname; }
string Client::getContactPersonPhoneNumber() { return contactPersonPhoneNumber; }
string Client::getContactPersonMail() { return contactPersonMail; }
size_t Client::getNumberOfTasks() { return numberOfTasks; }

Client Client::operator=(const Client& client) {
	companyName = client.companyName;
	companyLocation = client.companyLocation;
	contractValue = client.contractValue;
	contactPersonName = client.contactPersonName;
	contactPersonSurname = client.contactPersonSurname;
	contactPersonPhoneNumber = client.contactPersonPhoneNumber;
	contactPersonMail = client.contactPersonMail;
	return *this;
}
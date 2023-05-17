#include <iostream>
#include <locale>
#include <string>
#include "ticket_c.h"
using namespace std;

Ticket::Ticket() : id{ rand() % 100 + 1 } {}
Ticket::Ticket(string shortCompanyName, string topic, string ticketContent) : id{ rand() % 100 + 1 } {
	this->shortCompanyName = shortCompanyName;
	this->topic = topic;
	this->ticketContent = ticketContent;
}

void Ticket::setShortCompanyName(string shortCompanyName) { this->shortCompanyName = shortCompanyName; }
void Ticket::setTopic(string topic) { this->topic = topic; }
void Ticket::setTicketContent(string ticketContent) { this->ticketContent = ticketContent; }

int Ticket::getId() { return this->id; }
string Ticket::getShortCompanyName() { return this->shortCompanyName; }
string Ticket::getTopic() { return this->topic; }
string Ticket::getTicketContent() { return this->ticketContent; }

Ticket Ticket::operator=(const Ticket& ticket) {
	shortCompanyName = ticket.shortCompanyName;
	topic = ticket.topic;
	ticketContent = ticket.ticketContent;
	
	return *this;
}

Ticket::Status::Status() : status{ Open }, priority{ Normal } {}
void Ticket::Status::setTicketStatus(TicketStatus status) { this->status = status; }
void Ticket::Status::setTiocketPriority(TicketPriority priority) { this->priority = priority; }
TicketStatus Ticket::Status::getTicketStatus() { return this->status; }
TicketPriority Ticket::Status::getTicketPriority() { return this->priority; }
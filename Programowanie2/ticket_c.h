#ifndef Ticket_HEADER
#define Ticket_HEADER
#include <iostream>
#include <string>
using namespace std;

enum TicketStatus {
	Open = 0,
	InProgress,
	Closed,
	ReOpened
};
enum TicketPriority {
	Low = 0,
	Normal,
	High,
	Critical
};

class Ticket {
	const int id;
	string shortCompanyName;
	string topic;
	string ticketContent;
	class Status {
		friend class Ticket;
		TicketStatus status;
		TicketPriority priority;
	public:
		Status();
		void setTicketStatus(TicketStatus);
		void setTiocketPriority(TicketPriority);

		TicketStatus getTicketStatus();
		TicketPriority getTicketPriority();
	};
	Status status;
	bool done = false;
public:
	Ticket();
	Ticket(string, string, string);
	void setShortCompanyName(string);
	void setTopic(string);
	void setTicketContent(string);

	int getId();
	string getShortCompanyName();
	string getTopic();
	string getTicketContent();

	Ticket operator=(const Ticket& ticket);
};
#endif
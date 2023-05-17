#ifndef Client_HEADER
#define Client_HEADER
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Client {
	//friend class Ticket;
	class Ticket {
		friend class Client;
		const size_t id;
		string topic;
		string ticketContent;
		string category;
		string queue;
		bool isClosed = 0;
		string closedBy = "";
		string comment = "";
	public:
		Ticket();
		Ticket(string, string, string, string);
		void setTopic(string);
		void setTicketContent(string);
		void setCategory(string);
		void setQueue(string);
		void setIsClosed(bool);
		void setClosedBy(string);
		void setComment(string);

		int getId();
		string getTopic();
		string getTicketContent();
		string getCategory();
		string getQueue();
		bool getIsClosed();
		string getClosedBy();
		string getComment();

		Ticket operator=(const Ticket&);
		friend ostream& operator<<(ostream&, Client::Ticket&);
	};
	const size_t id;
	string nip;
	string companyName;
	string companyLocation;
	size_t contractValue;
	string contactPersonName;
	string contactPersonSurname;
	string contactPersonPhoneNumber;
	string contactPersonMail;
	Ticket** taskList;
	size_t numberOfTasks = 0;
public:
	Client();
	Client(string, string, string, size_t, string, string, string, string);
	~Client();
	Client(const Client&);

	void setNip(string);
	void setCompanyName(string);
	void setCompanyLocation(string);
	void setContractValue(size_t);
	void setContactPersonName(string);
	void setContactPersonSurname(string);
	void setContactPersonPhoneNumber(string);
	void setContactPersonMail(string);

	size_t getId();
	string getNip();
	string getCompanyName();
	string getCompanyLocation();
	size_t getContractValue();
	string getContactPersonName();
	string getContactPersonSurname();
	string getContactPersonPhoneNumber();
	string getContactPersonMail();
	//Ticket**& getTaskList();
	size_t getNumberOfTasks();
	bool getTicketIsClosed(size_t);

	void increaseNumberOfTasks();
	void decreaseNumberOfTasks();

	void createTickets(Ticket**&, size_t);
	void addTicket();
	void insertTicketContent(Ticket*);
	void printTickets();
	void deleteTicket(size_t);
	void deleteTickets(Ticket**&, size_t&);
	void changeTicketStatusToClosed(size_t, string);

	Client& operator=(const Client&);
	friend ostream& operator<<(ostream&, Client&);
	friend ostream& operator<<(ostream&, Client::Ticket&);
	Ticket& operator[](const size_t);
};
#endif
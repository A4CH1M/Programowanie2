#ifndef Client_HEADER
#define Client_HEADER
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Client {
	class Ticket {
		friend class Client;
		const int id;
		string topic;
		string ticketContent;
		string category;
		string queue;
		bool isDone = 0;
	public:
		Ticket();
		Ticket(string, string, string, string, bool);
		void setTopic(string);
		void setTicketContent(string);
		void setCategory(string);
		void setQueue(string);
		void setIsDone(size_t);

		int getId();
		string getTopic();
		string getTicketContent();
		string getCategory();
		string getQueue();
		bool getIsDone();

		Ticket operator=(const Ticket&);
	};
	const int id;
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
	Client(string, string, size_t, string, string, string, string, string, Ticket**, size_t);
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

	int getId();
	string getNip();
	string getCompanyName();
	string getCompanyLocation();
	size_t getContractValue();
	string getContactPersonName();
	string getContactPersonSurname();
	string getContactPersonPhoneNumber();
	string getContactPersonMail();
	size_t getNumberOfTasks();

	void increaseNumberOfTasks();
	void decreaseNumberOfTasks();

	void createTickets(Ticket**& tickets, size_t size);
	void addTicket();
	void insertTicketContent(Ticket* ticket);
	void printTickets();
	void deleteTicket(size_t index);
	void deleteTickets(Ticket**& tickets, size_t size);

	//Client& operator=(const Client&);

	Client& operator=(const Client&);
};
#endif


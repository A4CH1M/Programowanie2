#ifndef Client_HEADER
#define Client_HEADER
#include <iostream>
#include <string>
#include <cstdlib>
#include <map>

class Client {
	class Ticket {
		friend class Client;
		const size_t id;
		std::string topic;
		std::string ticketContent;
		std::string category;
		std::string queue;
		bool isClosed = 0;
		std::string closedBy = "";
		std::string comment = "";
	public:
		Ticket();
		Ticket(std::string, std::string, std::string, std::string);
		void setTopic(std::string);
		void setTicketContent(std::string);
		void setCategory(std::string);
		void setQueue(std::string);
		void setIsClosed(bool);
		void setClosedBy(std::string);
		void setComment(std::string);

		int getId();
		std::string getTopic();
		std::string getTicketContent();
		std::string getCategory();
		std::string getQueue();
		bool getIsClosed();
		std::string getClosedBy();
		std::string getComment();

		Ticket operator=(const Ticket&);
		friend std::ostream& operator<<(std::ostream&, Client::Ticket&);
	};
	const size_t id;
	std::string nip;
	std::string companyName;
	std::string companyLocation;
	size_t contractValue;
	std::string contactPersonName;
	std::string contactPersonSurname;
	std::string contactPersonPhoneNumber;
	std::string contactPersonMail;
	std::map<size_t, std::shared_ptr<Ticket>> taskList;
	size_t numberOfTasks = 0;
public:
	Client();
	Client(std::string, std::string, std::string, size_t, std::string, std::string, std::string, std::string);
	~Client();
	Client(const Client&);

	void setNip(std::string);
	void setCompanyName(std::string);
	void setCompanyLocation(std::string);
	void setContractValue(size_t);
	void setContactPersonName(std::string);
	void setContactPersonSurname(std::string);
	void setContactPersonPhoneNumber(std::string);
	void setContactPersonMail(std::string);

	size_t getId();
	std::string getNip();
	std::string getCompanyName();
	std::string getCompanyLocation();
	size_t getContractValue();
	std::string getContactPersonName();
	std::string getContactPersonSurname();
	std::string getContactPersonPhoneNumber();
	std::string getContactPersonMail();
	size_t getNumberOfTasks();
	bool getTicketIsClosed(size_t);

	bool checkIfTaskIndexIsValid(size_t index);

	void increaseNumberOfTasks();
	void decreaseNumberOfTasks();

	//void createTickets(std::map<size_t, std::shared_ptr<Ticket>>&, size_t);
	void addTicket();
	void insertTicketContent(std::shared_ptr<Ticket>);
	void printTickets();
	void deleteTicket(size_t);
	//void deleteTickets(Ticket**&, size_t&);
	void changeTicketStatusToClosed(size_t, std::string);

	Client& operator=(const Client&);
	friend std::ostream& operator<<(std::ostream&, Client&);
	friend std::ostream& operator<<(std::ostream&, Ticket&);
	//friend bool operator<(const Ticket&, const Ticket&);
	Ticket& operator[](const size_t);
};
#endif
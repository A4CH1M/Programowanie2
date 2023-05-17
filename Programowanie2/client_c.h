#ifndef Client_HEADER
#define Client_HEADER
#include <iostream>
#include <string>
#include <cstdlib>
#include "ticket_c.h"
using namespace std;

class Client {
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

	string getNip();
	string getCompanyName();
	string getCompanyLocation();
	size_t getContractValue();
	string getContactPersonName();
	string getContactPersonSurname();
	string getContactPersonPhoneNumber();
	string getContactPersonMail();
	size_t getNumberOfTasks();

	Client operator=(const Client& client);
};
#endif
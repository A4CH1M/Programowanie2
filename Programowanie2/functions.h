#include <iostream>
#include <string>
#include <cstdlib>
#include <locale>
#include "client_c.h"
#include "ticket_c.h"
using namespace std;

void createClient(Client*& client);
void createClient(Client**& client);
void createClient(Client*& client, const size_t size);
void createClient(Client**& client, const size_t size);

void insertClientData(Client* client);
void insertClientData(Client* clients, const size_t size);
void insertClientData(Client** clients, const size_t size);

void printClientData(Client* client);
void printClientData(Client* client, const size_t size);
void printClientData(Client** client, const size_t size);

void deleteClient(Client*& client);
void deleteClients(Client*& client, size_t& size);
void deleteClients(Client**& client, size_t& size);
void deleteClient(Client*& file, size_t& size, size_t index);
void deleteClient(Client**& file, size_t& size, size_t index);

void addClient(Client*& file, size_t& size);
void addClient(Client**& file, size_t& size);

void printAverageContractValue(Client* client, size_t size);
void printAverageContractValue(Client** client, size_t size);
void printContractorWithHighestContractValue(Client* client, size_t size);
void printContractorWithHighestContractValue(Client** client, size_t size);
void printContractorWithLowestContractValue(Client* client, size_t size);
void printContractorWithLowestContractValue(Client** client, size_t size);

string generateRandomNip();
string generateRandomPhoneNumber();
void canCreateClientDatabase(Client*& clientDb, size_t size);
void canCreateClientDatabase(Client**& clientDb, size_t size);

void createTicket(Ticket*& tickets, size_t& size);
void createTicket(Ticket**& tickets, size_t& size);

void insertTicketContent(Ticket ticket);
void insertTicketContent(Ticket* ticket);

void printTickets(Ticket* tickets, const size_t size);
void printTickets(Ticket** tickets, const size_t size);

void deleteTicket(Ticket*& tickets, size_t& size, size_t index);
void deleteTicket(Ticket**& tickets, size_t& size, size_t index);
void deleteTickets(Ticket*& tickets, size_t size);
void deleteTickets(Ticket**& tickets, size_t& size);

void selectCompanyTickets(Ticket* tickets, string name, size_t size);

void menu();
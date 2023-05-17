#pragma once
#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <locale>
#include "client_c.h"

using namespace std;

void createClient(Client**& client);
void createClient(Client**& client, const size_t size);
void insertClientData(Client* client);
void insertClientData(Client** clients, const size_t size);
void printClientData(Client* client);
void printClientData(Client** client, const size_t size);
void deleteClient(Client*& client);
void deleteClients(Client**& client, size_t& size);
void deleteClient(Client**& file, size_t& size, size_t index);
void addClient(Client**& file, size_t& size);
void printAverageContractValue(Client** client, size_t size);
void printContractorWithHighestContractValue(Client** client, size_t size);
void printContractorWithLowestContractValue(Client** client, size_t size);

string generateRandomNip();
string generateRandomPhoneNumber();
void canCreateClientDatabase(Client**& clientDb, size_t size);

void addTicket(Client**& client, size_t size, size_t index);
void deleteTicket(Client**& client, size_t size, size_t clientIndex, size_t ticketIndex);
void printTickets(Client**& client, size_t size);
void printTickets(Client**& client, size_t size, size_t index);

void menu();
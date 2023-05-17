#include <iostream>
#include <locale>
#include <string>
#include <ctime>
#include "employee_c.h"
using namespace std;

Employee::Employee() : id{ rand() % 100 + 1 } {}
Employee::Employee(string pesel, string name, string surname, string dateOfEmployment, size_t previousWorkPeriod) : id{ rand() % 100 + 1 } {
	this->pesel = pesel;
	this->name = name;
	this->surname = surname;
	this->dateOfEmployment = dateOfEmployment;
	if (previousWorkPeriod < 8) this->previousWorkPeriod = 8;
	else this->previousWorkPeriod = previousWorkPeriod;
	//this->maxHolidayLeaveDays = maxHolidayLeaveDays;
	//this->salary = salary;
}
Employee::Employee(const Employee& employee) : id{ id } {
	this->pesel = employee.pesel;
	this->name = employee.name;
	this->surname = employee.surname;
	this->dateOfEmployment = employee.dateOfEmployment;
	this->previousWorkPeriod = employee.previousWorkPeriod;
	this->maxHolidayLeaveDays = employee.maxHolidayLeaveDays;
	this->salary = employee.salary;
}
Employee::~Employee() {}

ostream& operator<<(ostream& output, Employee& employee) {
	output << "Identyfikator pracownika: " << employee.getEmployeeId() << endl
		<< "PESEL pracownika:         " << employee.getEmployeePesel() << endl
		<< "Imiê pracownika:          " << employee.getEmployeeName() << endl
		<< "Nazwisko pracownika:      " << employee.getEmployeeSurname() << endl
		<< "Data zatrudnienia:        " << employee.getEmployeeDateOfEmployment() << endl
		<< "Stanowisko:               " << employee.getEmployeePosition() << endl
		<< "Pozosta³y urlop (dni):    " << employee.getEmployeeMaxHolidayLeaveDays() << endl
		<< "Pensja:                   " << employee.getEmployeeSalary() << endl
		<< "------------------------------------------------------------";
	return output;
}
Employee& Employee::operator=(const Employee& employee) {
	if (&employee != this) {
		pesel = employee.pesel;
		name = employee.name;
		surname = employee.surname;
		dateOfEmployment = employee.dateOfEmployment;
		position = employee.position;
		maxHolidayLeaveDays = employee.maxHolidayLeaveDays;
		salary = employee.salary;

		return *this;
	}
}

int Employee::getEmployeeId() { return id; }
string Employee::getEmployeePesel() { return pesel; }
string Employee::getEmployeeName() { return name; }
string Employee::getEmployeeSurname() { return surname; }
string Employee::getEmployeeDateOfEmployment() { return dateOfEmployment; }
string Employee::getEmployeePosition() { return position; }
size_t Employee::getEmployeePreviousWorkPeriod() { return previousWorkPeriod; }
size_t Employee::getEmployeeMaxHolidayLeaveDays() { return maxHolidayLeaveDays; }
float Employee::getEmployeeSalary() { return salary; }
bool Employee::getEmployeeRecievedMaxHolidayBonus() { return recievedMaxHolidayBonus; }
bool Employee::getEmployeeRecievedMaxSalaryBonus() { return recievedMaxSalaryBonus; }

void Employee::setEmployeePesel(string pesel) { this->pesel = pesel; }
void Employee::setEmployeeName(string name) { this->name = name; }
void Employee::setEmployeeSurname(string surname) { this->surname = surname; }
void Employee::setEmployeeDateOfEmployment(string dateOfEmployment) { this->dateOfEmployment = dateOfEmployment; }
void Employee::setEmployeePosition(string position) { this->position = position; }
void Employee::setEmployeePreviousWorkPeriod(size_t previousWorkPeriod) { this->previousWorkPeriod = previousWorkPeriod; }
void Employee::setEmployeeMaxHolidayLeaveDays(size_t maxHolidayLeaveDaysLeft) { this->maxHolidayLeaveDays = maxHolidayLeaveDaysLeft; }
void Employee::setEmployeeSalary(float salary) { this->salary = salary; }
void Employee::setEmployeeRecievedMaxHolidayBonus(bool recievedMaxHolidayBonus) { this->recievedMaxHolidayBonus = recievedMaxHolidayBonus; }
void Employee::setEmployeeRecievedMaxSalaryBonus(bool recievedMaxSalaryBonus) { this->recievedMaxSalaryBonus = recievedMaxSalaryBonus; }

void Employee::calculateThings() {
	setlocale(LC_CTYPE, "Polish");
	string employeeDate = getEmployeeDateOfEmployment(), tmp;
	size_t date[3], pos, i = 0;
	if ((pos = employeeDate.find(".")) == string::npos) {
		cout << "B³¹d: B³êdna data" << endl;
		return;
	}
	while ((pos = employeeDate.find(".")) != string::npos) {
		tmp = employeeDate.substr(0, pos);
		date[i] = stoi(tmp);
		employeeDate.erase(0, pos + 1);
		i++;
	}
	date[i] = stoi(employeeDate);
	time_t now;
	tm tmObj;
	auto currentTime = &tmObj;
	time(&now);
	localtime_s(currentTime, &now);

	bool justifiedToGetBonus = 0;

	if (getEmployeeRecievedMaxHolidayBonus() == 0) {

		if (((currentTime->tm_year + 1900 - date[2]) + getEmployeePreviousWorkPeriod()) > 10) {
			justifiedToGetBonus = 1;
		} else if (((currentTime->tm_year + 1900 - date[2]) + getEmployeePreviousWorkPeriod()) == 10) {
			if (((currentTime->tm_mon) - date[1]) > 0) {
				justifiedToGetBonus = 1;
			} else if (((currentTime->tm_mon) - date[1]) == 0) {
				if (((currentTime->tm_mday) - date[0]) >= 0)
					justifiedToGetBonus = 1;
			}
		}
		if (justifiedToGetBonus == 1) {
			this->setEmployeeMaxHolidayLeaveDays(this->getEmployeeMaxHolidayLeaveDays() + 6);
			justifiedToGetBonus = 0;
			setEmployeeRecievedMaxHolidayBonus(1);
		}
	}
	if (getEmployeeRecievedMaxSalaryBonus() == 0) {
		if (((currentTime->tm_year + 1900) - date[2]) > 3) {
			justifiedToGetBonus = 1;
		} else if (((currentTime->tm_year + 1900) - date[2]) == 3) {
			if (((currentTime->tm_mon) - date[1]) > 0) {
				justifiedToGetBonus = 1;
			} else if (((currentTime->tm_mon) - date[1]) == 0) {
				if (((currentTime->tm_mday) - date[0]) >= 0)
					justifiedToGetBonus = 1;
			}
		}
		if (justifiedToGetBonus == 1) {
			this->setEmployeeSalary(this->getEmployeeSalary() * 1.05);
			justifiedToGetBonus = 0;
		}

		if (((currentTime->tm_year + 1900) - date[2]) > 5) {
			justifiedToGetBonus = 1;
		} else if (((currentTime->tm_year + 1900) - date[2]) == 5) {
			if (((currentTime->tm_mon) - date[1]) > 0) {
				justifiedToGetBonus = 1;
			} else if (((currentTime->tm_mon) - date[1]) == 0) {
				if (((currentTime->tm_mday) - date[0]) >= 0)
					justifiedToGetBonus = 1;
			}
		}
		if (justifiedToGetBonus == 1) {
			this->setEmployeeSalary(this->getEmployeeSalary() * 1.1);
			justifiedToGetBonus = 0;
		}

		if (((currentTime->tm_year + 1900) - date[2]) > 10) {
			justifiedToGetBonus = 1;
		} else if (((currentTime->tm_year + 1900) - date[2]) == 10) {
			if (((currentTime->tm_mon) - date[1]) > 0) {
				justifiedToGetBonus = 1;
			} else if (((currentTime->tm_mon) - date[1]) == 0) {
				if (((currentTime->tm_mday) - date[0]) >= 0)
					justifiedToGetBonus = 1;
			}
		}
		if (justifiedToGetBonus == 1) {
			this->setEmployeeSalary(this->getEmployeeSalary() * 1.1);
			setEmployeeRecievedMaxSalaryBonus(1);
		}
	}
}

void Employee::closeTicket(Client**& client, size_t size) {
	if (client == nullptr || size < 0)
		return;
	setlocale(LC_CTYPE, "Polish");
	size_t clientIndex, ticketIndex;
	cout << "Podaj indeks firmy, której zg³oszenie chcesz zamkn¹æ: ";
	cin >> clientIndex;
	cout << "Podaj indeks zg³oszenia, które chcesz zamkn¹æ: ";
	cin >> ticketIndex;
	if (clientIndex > size || ticketIndex > client[clientIndex]->getNumberOfTasks())
		return;
	string x = getEmployeeName() + " " + getEmployeeSurname();
	client[clientIndex]->setTicketIsDone(ticketIndex, 1, x);
}

ServiceTechnician::ServiceTechnician() {
	setEmployeePosition("Technik serwisant");
	setEmployeeSalary(4000);
}

ServiceTechnician::ServiceTechnician(string pesel, string name, string surname, string dateOfEmployment, size_t previousWorkPeriod) : Employee(pesel, name, surname, dateOfEmployment, previousWorkPeriod) {
	setEmployeePosition("Technik serwisant");
	setEmployeeSalary(4000);
}

ServiceTechnician::~ServiceTechnician() {}

void ServiceTechnician::virtualFunction() {
	setlocale(LC_CTYPE, "Polish");
	string employeeDate = getEmployeeDateOfEmployment(), tmp;
	size_t date[3], pos, i = 0;
	if ((pos = employeeDate.find(".")) == string::npos) {
		cout << "B³¹d: B³êdna data" << endl;
		return;
	}
	while ((pos = employeeDate.find(".")) != string::npos) {
		tmp = employeeDate.substr(0, pos);
		date[i] = stoi(tmp);
		employeeDate.erase(0, pos + 1);
		i++;
	}
	date[i] = stoi(employeeDate);
	time_t now;
	tm tmObj;
	auto currentTime = &tmObj;
	time(&now);
	localtime_s(currentTime, &now);

	bool justifiedToGetBonus = 0;

	if (((currentTime->tm_year + 1900 - date[2]) + getEmployeePreviousWorkPeriod()) > 15) {
		justifiedToGetBonus = 1;
	} else if (((currentTime->tm_year + 1900 - date[2]) + getEmployeePreviousWorkPeriod()) == 15) {
		if (((currentTime->tm_mon) - date[1]) > 0) {
			justifiedToGetBonus = 1;
		} else if (((currentTime->tm_mon) - date[1]) == 0) {
			if (((currentTime->tm_mday) - date[0]) >= 0)
				justifiedToGetBonus = 1;
		}
	}
	if (justifiedToGetBonus == 1)
		setEmployeePosition("Starszy Technik Serwisant");
}

DepartmentManager::DepartmentManager() {
	setEmployeePosition("Kierownik dzia³u");
	setEmployeeSalary(5500);
}
DepartmentManager::DepartmentManager(string pesel, string name, string surname, string dateOfEmployment, size_t previousWorkPeriod) : Employee(pesel, name, surname, dateOfEmployment, previousWorkPeriod) {
	setEmployeePosition("Kierownik dzia³u");
	setEmployeeSalary(5500);
}

DepartmentManager::~DepartmentManager() {}

void DepartmentManager::virtualFunction() {
	setEmployeeMaxHolidayLeaveDays(getEmployeeMaxHolidayLeaveDays() + 2);
}
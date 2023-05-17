#include <iostream>
#include <locale>
#include <string>
#include <ctime>
#include "employee_c.h"
#include "functions.h"

Employee::Employee() : id{ assignEmployeeId() } {}
Employee::Employee(std::string pesel, std::string name, std::string surname, std::string dateOfEmployment, size_t previousWorkPeriod) : id{ assignEmployeeId() } {
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

std::ostream& operator<<(std::ostream& output, Employee& employee) {
	output << "Identyfikator pracownika: " << employee.getId() << std::endl
		<< "PESEL pracownika:         " << employee.getEmployeePesel() << std::endl
		<< "Imiê pracownika:          " << employee.getEmployeeName() << std::endl
		<< "Nazwisko pracownika:      " << employee.getEmployeeSurname() << std::endl
		<< "Data zatrudnienia:        " << employee.getEmployeeDateOfEmployment() << std::endl
		<< "Stanowisko:               " << employee.getEmployeePosition() << std::endl
		<< "Pozosta³y urlop (dni):    " << employee.getEmployeeMaxHolidayLeaveDays() << std::endl
		<< "Pensja:                   " << employee.getEmployeeSalary() << std::endl
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
size_t Employee::getId() { return id; }
std::string Employee::getEmployeePesel() { return pesel; }
std::string Employee::getEmployeeName() { return name; }
std::string Employee::getEmployeeSurname() { return surname; }
std::string Employee::getEmployeeDateOfEmployment() { return dateOfEmployment; }
std::string Employee::getEmployeePosition() { return position; }
size_t Employee::getEmployeePreviousWorkPeriod() { return previousWorkPeriod; }
size_t Employee::getEmployeeMaxHolidayLeaveDays() { return maxHolidayLeaveDays; }
float Employee::getEmployeeSalary() { return salary; }
bool Employee::getEmployeeRecievedMaxHolidayBonus() { return recievedMaxHolidayBonus; }
bool Employee::getEmployeeRecievedMaxSalaryBonus() { return recievedMaxSalaryBonus; }

void Employee::setEmployeePesel(std::string pesel) { this->pesel = pesel; }
void Employee::setEmployeeName(std::string name) { this->name = name; }
void Employee::setEmployeeSurname(std::string surname) { this->surname = surname; }
void Employee::setEmployeeDateOfEmployment(std::string dateOfEmployment) { this->dateOfEmployment = dateOfEmployment; }
void Employee::setEmployeePosition(std::string position) { this->position = position; }
void Employee::setEmployeePreviousWorkPeriod(size_t previousWorkPeriod) { this->previousWorkPeriod = previousWorkPeriod; }
void Employee::setEmployeeMaxHolidayLeaveDays(size_t maxHolidayLeaveDaysLeft) { this->maxHolidayLeaveDays = maxHolidayLeaveDaysLeft; }
void Employee::setEmployeeSalary(float salary) { this->salary = salary; }
void Employee::setEmployeeRecievedMaxHolidayBonus(bool recievedMaxHolidayBonus) { this->recievedMaxHolidayBonus = recievedMaxHolidayBonus; }
void Employee::setEmployeeRecievedMaxSalaryBonus(bool recievedMaxSalaryBonus) { this->recievedMaxSalaryBonus = recievedMaxSalaryBonus; }

void Employee::calculateThings() {
	setlocale(LC_CTYPE, "Polish");
	std::string employeeDate = getEmployeeDateOfEmployment(), tmp;
	size_t date[3], pos, i = 0;
	if ((pos = employeeDate.find(".")) == std::string::npos) {
		std::cout << "B³¹d: B³êdna data" << std::endl;
		return;
	}
	while ((pos = employeeDate.find(".")) != std::string::npos) {
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

ServiceTechnician::ServiceTechnician() {
	setEmployeePosition("Technik serwisant");
	setEmployeeSalary(4000);
}
ServiceTechnician::ServiceTechnician(std::string pesel, std::string name, std::string surname, std::string dateOfEmployment, size_t previousWorkPeriod) : Employee(pesel, name, surname, dateOfEmployment, previousWorkPeriod) {
	setEmployeePosition("Technik serwisant");
	setEmployeeSalary(4000);
}
ServiceTechnician::~ServiceTechnician() {}
void ServiceTechnician::virtualFunction() {
	setlocale(LC_CTYPE, "Polish");
	std::string employeeDate = getEmployeeDateOfEmployment(), tmp;
	size_t date[3], pos, i = 0;
	if ((pos = employeeDate.find(".")) == std::string::npos) {
		std::cout << "B³¹d: B³êdna data" << std::endl;
		return;
	}
	while ((pos = employeeDate.find(".")) != std::string::npos) {
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
DepartmentManager::DepartmentManager(std::string pesel, std::string name, std::string surname, std::string dateOfEmployment, size_t previousWorkPeriod) : Employee(pesel, name, surname, dateOfEmployment, previousWorkPeriod) {
	setEmployeePosition("Kierownik dzia³u");
	setEmployeeSalary(5500);
}
DepartmentManager::~DepartmentManager() {}
void DepartmentManager::virtualFunction() {
	setEmployeeMaxHolidayLeaveDays(getEmployeeMaxHolidayLeaveDays() + 2);
}
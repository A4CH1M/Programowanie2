#ifndef Employee_HEADER
#define Employee_HEADER
#include <iostream>
#include <ctime>
#include <string>
#include "client_c.h"
using namespace std;
class Employee {
	const int id;
	string pesel;
	string name;
	string surname;
	//birthdate - maybe later, don't need it for now
	string dateOfEmployment;
	string position;
	size_t previousWorkPeriod = 8; //I hire only people after university so it counts as 8ys of employment period. WARNING: works only in Poland
	size_t maxHolidayLeaveDays = 20;
	float salary;
	bool recievedMaxHolidayBonus = 0;
	bool recievedMaxSalaryBonus = 0;
	//bool canRetire = 0; with date of birth maybe?
public:
	Employee();
	Employee(string, string, string, string, size_t);
	Employee(const Employee&);
	virtual ~Employee();

	int getEmployeeId();
	string getEmployeePesel();
	string getEmployeeName();
	string getEmployeeSurname();
	string getEmployeeDateOfEmployment();
	string getEmployeePosition();
	size_t getEmployeePreviousWorkPeriod();
	size_t getEmployeeMaxHolidayLeaveDays();
	float getEmployeeSalary();
	bool getEmployeeRecievedMaxHolidayBonus();
	bool getEmployeeRecievedMaxSalaryBonus();

	void setEmployeePesel(string);
	void setEmployeeName(string);
	void setEmployeeSurname(string);
	void setEmployeeDateOfEmployment(string);
	void setEmployeePosition(string);
	void setEmployeePreviousWorkPeriod(size_t);
	void setEmployeeMaxHolidayLeaveDays(size_t);
	void setEmployeeSalary(float);
	void setEmployeeRecievedMaxHolidayBonus(bool);
	void setEmployeeRecievedMaxSalaryBonus(bool);

	void calculateThings();
	void closeTicket(Client**& client, size_t size);
	virtual void virtualFunction() = 0;
	friend ostream& operator<<(ostream&, Employee&);
	Employee& operator=(const Employee&);
};

class ServiceTechnician : public Employee {
public:
	ServiceTechnician();
	ServiceTechnician(string, string, string, string, size_t);
	virtual ~ServiceTechnician();
	virtual void virtualFunction();
};

class DepartmentManager : public Employee {
public:
	DepartmentManager();
	DepartmentManager(string, string, string, string, size_t);
	virtual ~DepartmentManager();
	virtual void virtualFunction();
};
#endif
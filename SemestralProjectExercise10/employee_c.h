#ifndef Employee_HEADER
#define Employee_HEADER
#include <iostream>
#include <ctime>
#include <string>
#include "client_c.h"

class Employee {
	const size_t id;
	std::string pesel;
	std::string name;
	std::string surname;
	//birthdate - maybe later, don't need it for now
	std::string dateOfEmployment;
	std::string position;
	size_t previousWorkPeriod = 8; //I hire only people after university so it counts as 8ys of employment period. WARNING: works only in Poland
	size_t maxHolidayLeaveDays = 20;
	float salary;
	bool recievedMaxHolidayBonus = 0;
	bool recievedMaxSalaryBonus = 0;
	//bool canRetire = 0; with date of birth maybe?
public:
	Employee();
	Employee(std::string, std::string, std::string, std::string, size_t);
	Employee(const Employee&);
	virtual ~Employee();

	size_t getId();
	std::string getEmployeePesel();
	std::string getEmployeeName();
	std::string getEmployeeSurname();
	std::string getEmployeeDateOfEmployment();
	std::string getEmployeePosition();
	size_t getEmployeePreviousWorkPeriod();
	size_t getEmployeeMaxHolidayLeaveDays();
	float getEmployeeSalary();
	bool getEmployeeRecievedMaxHolidayBonus();
	bool getEmployeeRecievedMaxSalaryBonus();

	void setEmployeePesel(std::string);
	void setEmployeeName(std::string);
	void setEmployeeSurname(std::string);
	void setEmployeeDateOfEmployment(std::string);
	void setEmployeePosition(std::string);
	void setEmployeePreviousWorkPeriod(size_t);
	void setEmployeeMaxHolidayLeaveDays(size_t);
	void setEmployeeSalary(float);
	void setEmployeeRecievedMaxHolidayBonus(bool);
	void setEmployeeRecievedMaxSalaryBonus(bool);

	void calculateThings();
	virtual void virtualFunction() = 0;
	friend std::ostream& operator<<(std::ostream&, Employee&);
	Employee& operator=(const Employee&);
};

class ServiceTechnician : public Employee {
public:
	ServiceTechnician();
	ServiceTechnician(std::string, std::string, std::string, std::string, size_t);
	virtual ~ServiceTechnician();
	virtual void virtualFunction();
};

class DepartmentManager : public Employee {
public:
	DepartmentManager();
	DepartmentManager(std::string, std::string, std::string, std::string, size_t);
	virtual ~DepartmentManager();
	virtual void virtualFunction();
};
#endif
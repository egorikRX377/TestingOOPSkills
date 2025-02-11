#pragma once
#include <string>

using namespace std;


class Person 
{
protected:
	string name;
	int age;
public:
	Person();
	Person(string name, int age);
	Person(const Person& person);

	Person(Person&& person);

	~Person();

	Person& operator=(const Person& person);
	Person& operator=(Person&& person);


	virtual void displayInfo() const;
};


class Employee : public Person
{
private:
	string position;
	double salary;
public:
	Employee();
	Employee(string name, int age, string position, double salary);

	void displayInfo() const override;
};







#include "OOP_skills.h"
#include <iostream>


Person::Person() : name("unknown"), age(0) { cout << "Person Constructor run!" << endl; }
Person::Person(string name, int age) : name(name), age(age) { cout << "Person Constructor run!" << endl; }
Person::Person(const Person& person) : name(person.name), age(person.age) { cout << "Person Copy Constructor run!" << endl; }
Person::~Person() { cout << "Person Destructor run!" << endl; }


Person& Person::operator=(const Person& person) { this->name = person.name; this->age = person.age; cout << "Operator = has been worked!" << endl; return *this; }


Person::Person(Person&& person) : name(person.name), age(person.age) { person.name = "clear"; person.age = 0; }

Person& Person::operator=(Person&& person)
{
	if (this == &person) { return *this; }

	this->name = person.name;
	this->age = person.age;

	person.name = "clear";
	person.age = -1;

	return *this;
}


void Person::displayInfo() const { cout << "Person info\n"; cout << "name: " << this->name << endl; cout << "age: " << this->age << endl; }


Employee::Employee() : Person() { cout << "Employee Constructor run!" << endl; }
Employee::Employee(string name, int age, string position, double salary) : Person(name, age), position(position), salary(salary) { cout << "Employee Constructor run!" << endl; }
void Employee::displayInfo() const { cout << "Employee info\n"; cout << "name: " << this->name << endl; cout << "age: " << this->age << endl; cout << "position: " << this->position << endl; cout << "salary: " << this->salary << endl; }
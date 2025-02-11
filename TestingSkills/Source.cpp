#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>


#include "OOP_skills.h"
#include "SortingClass.h"



using namespace std;


const int arrSIZE = 5;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*vector<Person*> people;
	
	people.push_back(new Person("some", 12));
	people.emplace_back(new Person("Grisha", 29));

	for (const auto& item : people)
	{
		item->displayInfo();
	}

	std::vector<Person*>::iterator it = people.begin();

	for (; it != people.end(); it++)
	{
		(*it)->displayInfo();
	}*/

	
	int* arr = new int[arrSIZE];


	cout << "Input array: ";

	for (int i = 0; i < arrSIZE; i++)
	{
		cin >> *(arr + i);
	}

	SortingMethod<int>* someMethod = new BubbleSort<int>(arr, arrSIZE);

	someMethod->sortArr();

	someMethod->displayArr();

	delete someMethod;

	return 0;
}
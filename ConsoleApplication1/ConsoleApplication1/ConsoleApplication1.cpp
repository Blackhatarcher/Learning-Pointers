// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iomanip>
using namespace std;

class Person {
private:
	string name;
	int age;
	string studentId;
public:
	Person() { name = "George Whitworth"; age = 198; studentId = "GW"; }
	Person(string n, int a, string id) { name = n; age = a; studentId = id; }

	string getName() { return name; }
	int getAge() { return age; }
	void setName(string n) { name = n; }
	void setAge(int a) { age = a; }
	void birthday() { age++; }
	string getStudentId() { return studentId; }

	bool isEqualToPerson(Person* p) {
		return p != NULL && getStudentId() == p->getStudentId();
	}
};
class CS172 {
private:
	const static int MAX_CLASS_SIZE = 1000;
	Person* students[MAX_CLASS_SIZE];
public:
	CS172() {
		for (int i = 0; i < MAX_CLASS_SIZE; i++) {
			students[i] = NULL;
		}
	}

	void registerStudent(Person* p) {
		if (p != NULL)
		{
			bool alreadyRegistered = false;
			for (int i = 0; i < MAX_CLASS_SIZE; i++) {
				if (p->isEqualToPerson(students[i])) {
					alreadyRegistered = true;
					break;
				}
			}

			if (!alreadyRegistered)
			{
				for (int i = 0; i < MAX_CLASS_SIZE; i++) {
					if (students[i] == NULL) {
						students[i] = p;
						break;
					}
				}
			}
		}
	}

	void unregisterStudent(Person* p) {
		for (int i = 0; i < MAX_CLASS_SIZE; i++) {
			if (p->isEqualToPerson(students[i])) {
				students[i] = NULL;
			}
		}
	}

	void outputRoster() {
		cout << "CS 172 Roster" << endl;
		for (int i = 0; i < MAX_CLASS_SIZE; i++)
		{
			if (students[i] != NULL)
			{
				cout << students[i]->getName() << " " << students[i]->getAge() << endl;
			}
		}

		cout << endl;
	}
};
void lastDayToUnregister(CS172* cs172)
{
	Person* joe = new Person("Joe", 20, "J2");
	cs172->unregisterStudent(joe);
	delete joe;
}
int main()
{
	CS172* cs172 = new CS172();
	Person* jim = new Person("Jim", 20, "JM");
	Person* sue = new Person("Sue", 21, "SU");
	Person* joe = new Person("Joe", 20, "JO");

	Person* group[3];
	group[0] = new Person();
	group[1] = new Person();
	group[2] = new Person();

	for (int i = 0; i < 3; i++)
	{
		if (group[i] != NULL)
		{
			delete group[i];
		}
	}


	cs172->registerStudent(jim);
	cs172->registerStudent(sue);
	cs172->registerStudent(joe);

	cs172->outputRoster();

	cs172->registerStudent(jim);
	cs172->registerStudent(jim);

	sue->birthday();
	lastDayToUnregister(cs172);

	cs172->outputRoster();

	delete jim;
	delete sue;
	delete joe;
	delete cs172;

}



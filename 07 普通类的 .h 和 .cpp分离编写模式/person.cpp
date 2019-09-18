#include "Person.h"

Person::Person(string name, int age) {
	this->mAge = age;
	this->mName = name;


}

void Person::Show()
{
	cout << "Name:" << this->mName << "  Age:" << this->mAge << endl;
}
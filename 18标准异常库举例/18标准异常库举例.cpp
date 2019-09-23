#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdexcept>
#include <cstring>
#include <string.h>
using namespace std;

class Person {
public:
	Person() {
		mAge = 0;
	}
	void setAge(int age) {
		if (age < 0 || age>100) {
			throw out_of_range("年龄应该在0-100之间");
		}
		this->mAge = age;
	}
public:
	int mAge;
};

void test01()
{
	Person p;

	try {
		p.setAge(10000);
	}
	catch (out_of_range e) { //exception
		cout << e.what() << endl;
	}
}
class MyOutOfRange :public exception{
public:
	MyOutOfRange(const char * error) {
		this->pError = new char[strlen(error) + 1];
		strcpy(pError, error);
	}
	virtual const char * what() const {
		return pError;
	}

	~MyOutOfRange() {
		if (this->pError != NULL) {
			delete[] this->pError;
		}
	}

public:
	char * pError;
};

void func02()
{
	try
	{
	throw MyOutOfRange("我自己的 out_of_range");
	}
	catch (exception &e) {
		cout << e.what() << endl;
	}
}

int main(void) {
	test01();
	func02();
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>


using namespace std;

class Person
{

public:
	Person(const char * name, int age)
	{
		this->pName = new char[strlen(name) + 1];
		this->age = age;
		strcpy(this->pName, name);
		this->age = age;
	}
	Person(const Person &p)//把值拷贝改为引用拷贝
	{
		this->pName = new char[strlen(p.pName) + 1];
		strcpy(this->pName, p.pName);
		this->age = p.age;
	}

	Person &operator=(const Person &p)
	{
		if (this->pName != NULL)
		{
			delete this->pName;
		}
		this->pName = new char[strlen(p.pName) + 1];
		strcpy(this->pName, pName);
		this->age = age;

		return *this;
	}
	~Person()
	{
		if (this->pName != NULL)
		{
			delete[] this->pName;
		}
	}
public:
	char * pName;//指针，容易出现浅拷贝的问题。
	int age;
};

void test01()
{
	Person p1("aaa",20);
	vector<Person> v1;
	v1.push_back(p1);
}

int main(void)
{
	test01();
	system("pause");
	return 0;
}
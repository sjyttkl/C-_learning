#include<iostream>
#include<set>
#include<string>
using namespace std;

void printSet(set<int> & v)
{
	for (set<int>::iterator it = v.begin(); it!=v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//构造和赋值
void test01()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	printSet(s1);

	//拷贝构造
	set<int> s2(s1);
	printSet(s2);

	//赋值
	set<int> s3;
	s3 = s2;
	printSet(s3);

	if (s3.empty())
	{
		cout << "s3 为空" << endl;
	}
	else
	{
		cout << "s3 不为空" << endl;
		cout << "s3 的大小为：" << s3.size() << endl;
	}

	set<int> s4;
	s4.insert(100);
	s4.insert(200);
	s4.insert(300);
	printSet(s4);

	//交换
	s4.swap(s3);
	printSet(s3);
	printSet(s4);


	//删除
	s4.erase(s4.begin());
	printSet(s4);

	set<int> s5;
	s5.insert(10);
	s5.insert(10);
	s5.insert(10);
	s5.insert(10);
	//删除所有的10
	s5.erase(10);
	printSet(s5);


}


void test02()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);

	set<int>::iterator pos = s1.find(30);
	if (pos != s1.end())
	{
		cout << "找到元素了 " << *pos << endl;
	}
	else
	{
		cout << " 未找到元素" << endl;
	}
	//统计
	int num = s1.count(30);
	cout << "num = " << num << endl;




}

void test03()
{
	set<int> s;
	pair<set<int>::iterator, bool> ret = s.insert(10);
	if (ret.second)
	{
		cout << "第一次插入成功" << endl;
	}
	else
	{
		cout << "第一次插入失败" << endl;
	}

	ret = s.insert(10);
	if (ret.second)
	{
		cout << "第一次插入成功" << endl;
	}
	else
	{
		cout << "第一次插入失败" << endl;
	}

	multiset<int> ms;
	ms.insert(10);
	ms.insert(10);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end() ;it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

}

class Person {
public:
	Person(string a, int b)
	{
		this->name = a;
		this->age = b;
	}
public:
	string name;
	int age;
};

struct myCompare //也可以写成class
{
public://仿函数
	bool operator()(const Person &p1, const Person &p2)
	{
		return p1.age > p2.age;
	}
};

void test04()
{
	set<Person, myCompare> s;
	s.insert(Person("xiadong", 2));
	s.insert(Person("xiadong2", 0));
	s.insert(Person("xiadong", 1));

	for (set<Person> ::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "name :" << it->name << "  age:" << it->age << endl;
	}
}


int main(void)
{
	//test03();
	test04();
	system("pause");
	return 0;
}
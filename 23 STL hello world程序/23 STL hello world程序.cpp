#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector> //动态数组，可变数组
#include<algorithm> //算法
using namespace std;


void PrintVector(int v)
{
	cout << v << endl;
}


//STL基本语法
void test01(){
	//定义一个容器，并且知道这个容器存放的元素类型是int
	vector<int> v;
	v.push_back(30);
	v.push_back(2);
	v.push_back(3);
	v.push_back(9);

	//通过stl提供的for_each 算法
	//容器提供的迭代器
	//vector<int> ::iterator 迭代器类型
	vector<int> ::iterator pBegin = v.begin();
	vector<int> ::iterator pEnd = v.end();

	//容器中可能存放基础的数据类型，也可以能存放自定义的数据类型
	for_each(pBegin, pEnd, PrintVector);

}



class Person
{
public:
	Person(int age, int id):age(age), id(id) {}
public:
	int age;
	int id;
};

void test02()
{
	//创建容器，并且制定容器的元素类型是Person
	vector<Person> v;
	Person p1(10, 20), p2(30, 40), p3(30, 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	for (vector<Person>::iterator it = v.begin();it != v.end(); it++)
	{
		cout << (*it).id <<"  "<<  (*it).age << endl;
	}



}

//容器存放Person类型指针，并且打印for_each
int main(void)
{
	//test01();
	test02();
	return 0;
}
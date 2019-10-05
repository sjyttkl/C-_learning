#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
//仿函数适配器 bindlst bind2nd; 绑定适配器

struct MyPrint :public binary_function<int,int,void> //这里需要继承binary_function<第一个参数，第二个参数，返回值类型>
{
	void operator()(int v,int val ) const //这里需要常量修饰
	{
		cout << "v:  " << v << "  val:  " << val << endl;
		cout << v+val  << "  ";
	}
	   
};
void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//普通 
	//for_each(v.begin(), v.end(), MyPrint());
	//绑定适配器,将二元的函数对象转变成一元的函数对象
	int addNum = 100;
	for_each(v.begin(), v.end(), bind2nd(MyPrint(),addNum));
	//
	for_each(v.begin(), v.end(), bind1st(MyPrint(), addNum));
	//bind2nd,和bind1st的区别是：
	//bind2nd 将addNum绑定为函数对象的第二个参数
	//bind1st 将addNUM绑定为函数对象的第一个参数
}
struct MyPrint2 
{
	void operator()(int v) const
	{
		
		cout << v  << "  ";
	}

};

struct Mycompare :public binary_function<int ,int,bool>//二元谓词，
{
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};
struct MyGreater5 :public unary_function<int,bool> //一元谓词
{
public:
	bool operator()(int v) const
	{
		return v > 5;
	}
};

//仿函数适配器 not1 not2
void test02()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand()%100);
	}
	for_each(v.begin(), v.end(), MyPrint2());
	cout << endl;
	//sort(v.begin(), v.end(), Mycompare());
	//cout << endl;
	sort(v.begin(), v.end(), not2(Mycompare()));//取反适配器
	cout << endl;
	for_each(v.begin(), v.end(),MyPrint2());
	cout << endl;
	//not1 和not2 的区别
	//如果对一元谓词取反，用not1
	//如果对二元谓词取反，用not2
	vector<int>::iterator it = find_if(v.begin(), v.end(), MyGreater5());
	cout << *it << endl;
	vector<int>::iterator it2 = find_if(v.begin(), v.end(), not1(MyGreater5()));
	if (it2 == v.end())
	{
		cout << " 没有找到 " << endl;
	}
	else
	{
		cout << *it2 << endl;
	}
	
}



//仿函数适配器 ptr_fun
void myPrint03(int val)
{
	cout << val << " " ;
}
void myPrint04(int val,int v)
{
	cout << " val  " << val << " v " << v;
	cout << val + v << " " << endl;;
}
void test03()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand() % 100);
	}

	for_each(v.begin(), v.end(), myPrint03); cout << endl;
	//如果想适配，则需要把普通函数转成函数对象，使用ptr_fun
	for_each(v.begin(), v.end(), ptr_fun(myPrint03)); cout << endl;
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(myPrint04), 10)); cout << endl;
}

class Person
{

public:
	Person(int age, int id) :age(age), id(id) {}
	void show() {
		cout << "age: " << age << "  id: " << id << endl;
	} 
public:
	int age;
	int id;
};

//成员函数适配器 mem_fun和 mem_fun_ref
void test04()
{
	//如果容器中存放的是对象或者是指针，我们for_each算法打印的时候，调用类，
	//自己提供的打印函数
	vector<Person> v;
	Person p1(10, 20), p2(30, 40), p3(50, 60);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	//格式:&类名::函数名
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::show));

	vector<Person*> v2;
	v2.push_back(&p1);
	v2.push_back(&p2);
	v2.push_back(&p3);

	//格式:&类名::函数名
	for_each(v2.begin(), v2.end(), mem_fun(&Person::show));

	//mem_fun 和 mem_fun_ref的区别
	//如果存放的是对象指针：使用mem_fun
	//如果使用的是对象：使用mem_fun_ref

}


int main(void)
{
	//test01();
	//test02();
	//test03();
	test04();	
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>

using namespace std;

template<class T> class Person;
template<class T> void PrintPerson(Person <T> &p);

template<class T>
class Person {
public:
	//重载左移操作符
	template<class T>
	friend ostream& operator<< <T>(ostream& os,Person<T> &p); //<T> 加入 ，linux环境下 才可以通过


	//普通友元函数
	//template<class T>
	//friend void PrintPerson(Person <T> &p); //这种写法，在别的（linux环境下）也可能编译不通过
	template<class T>
	friend void PrintPerson<T>(Person <T> &p);////这种写法很合适


	Person(T age, T id);
	void Show();

private:
	T mAge;
	T mID;
};

//类模板的外部实现
template<class T>
Person<T>::Person(T age, T id)
{
	this->mID = id;
	this->mAge = age;
}

template<class T>
void Person<T>::Show() {
	cout << "age: " << mAge << " ID: " << mID << endl;
}

//重载左移操作符
template<class T>
ostream& operator<<(ostream& os, Person<T>& p) {
	os << "age: " << p.mAge << " ID: " << p.mID << endl;
	return os;
}
//普通友元、实现
template<class T>
 void PrintPerson(Person <T> &p) {
	 cout << "age: " << p.mAge << " ID: " << p.mID << endl;
}

 //不要乱用友元函数，很危险。尤其是友元模板
void tes01() {
	Person<int> p(10, 20);
	p.Show();

	//cout << p;  //重载左移操作符

	PrintPerson(p);

}
int main()
{
	tes01();
	return 0;
}



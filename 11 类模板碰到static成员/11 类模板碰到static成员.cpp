#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template<class T>
class Person {
public:
	static int a;

};

//类外初始化
template<class T> int Person<T>::a = 0;


int main(void) {
	//类独有的static变量，进行共享
	Person<int> p1, p2, p3;
	Person<char> pp1, pp2, pp3;

	p1.a = 10;
	pp1.a = 100;
	cout << p1.a << " " << p2.a << " " << p3.a << endl;
	cout << pp1.a << " " << pp2.a << " " <<pp3.a << endl;
	return 0;
}
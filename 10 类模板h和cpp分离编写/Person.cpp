#include "Person.h"

//函数模板需要经过两次编译，
//并没有生成具体函数。
//所以在独立编译的情况下，链接器会找不到具体实现函数在哪里（因为还没有被调用没有、生成）
//需要根据具体使用才会生成具体函数。所以编译没问题。
//解决方案：是把下面的所有的，模板和实现放到一起，#include"Person.hpp"
template<class T>
Person<T>::Person(T age) {
	this->age = age;
}

template<class T>
void Person<T>::Show() {
	cout << "age " << age << endl;
}
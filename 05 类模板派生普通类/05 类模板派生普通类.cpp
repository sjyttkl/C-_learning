#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
template<class T>
class Person {
public :
	Person() {
		this->mAge = 0;
	}
private :
	T mAge;
};
//为什么,继承超类的时候，需要分配内存，所以需要指定 类型<int>
//类区定义对象，这个对象是不是需要编译分配内存
class SubPerson :public Person<int> {

};
int main()
{
	return 0;
}
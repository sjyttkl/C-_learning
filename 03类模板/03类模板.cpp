#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
template<class T>
class Person {

public:
	Person(T id,T age) {
		this->mAge = age;
		this->mId = id;
	}
	void Show() {
		cout << " ID:  " << mId << "  Age  " << mAge << endl;
	}
public:
	T mId;
	T mAge;
};
void test01() {
	//函数模板在调用的时候，可以自动进行类型推导
	//类模板必须显示指定类型
	Person<int > p(10, 20);
	p.Show();
}
int main(void)
{
	test01();
	return 0;
}
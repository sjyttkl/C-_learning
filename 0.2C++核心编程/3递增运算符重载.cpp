#include<iostream>
using namespace  std;
class MyInteger {
public:
	friend ostream & operator<<(ostream &out, MyInteger myint);
	MyInteger(int num)
	{
		this->m_Num = num;
	}
	//前置 ++
	MyInteger & operator ++() {
		this->m_Num++;
		return  *this; // 前置递增，需要返回的是引用
	}
	//后置++,这里的int只是个占位参数，可以用于区分前置和后置递增。只能用int
	MyInteger operator++(int)
	{
		MyInteger temp = *this;
		this->m_Num++;
		return temp;//后置递增 返回必须是值，因为temp是局部的，如果返回引用，局部temp被释放了后，就是非法操作

	}
private :
	int m_Num;
};

ostream & operator<< (ostream &out, MyInteger myint) {
	out << myint.m_Num;
	return out;
}

//前置++ 先++ 再返回
int test01()
{
	MyInteger myInt(10);

	cout << ++myInt << endl;
	cout << myInt << endl;
	return 0;
}
//后置++ 先返回 再++
int test02()
{
	MyInteger myInt(20);
	cout << myInt++ << endl;
	cout << myInt << endl;
	return 0;
}
int main04() {

	//test01();
	test02();

	system("pause");

	return 0;
}
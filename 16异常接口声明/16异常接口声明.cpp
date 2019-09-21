#include<iostream>

using namespace std;


//这个函数只能抛出intfloat ,char 这三种类型的异常，抛出其他的就会报错
void func() throw(int,float,char) {
	throw "abc";
}

void func02() throw() //任何类型都不能抛出
{
	throw - 1;
}

void func03() throw() //可以抛出任何类型的异常
{
	throw - 1;
}

int main()
{

	try {
		func();
	}
	catch (char * str) {
		cout << str << endl;
	}
	catch (int e) {
		cout << "异常" << endl;
	}
	catch (...) {//捕获所有异常
		cout << "未知异常" << endl;
	}
	return 0;
}
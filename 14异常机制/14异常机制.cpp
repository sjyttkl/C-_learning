#include<iostream>

using namespace std;
//异常基本语法
int divied(int x, int y) {
	if (y == 0) {
		throw y;//抛出异常
	}
}

void test01() {
	//尝试着去捕获异常
	try {
		divied(10, 0);
	}
	catch (int e ) { //异常是根据类型进行匹配的,catch(int)
		cout << "除数为 " << e << endl;
	}
}
void CallDivide(int x,int y) {
	divied(x, y);
}

void test02() {
	try {
		CallDivide(1,0);
	}
	catch (int e) {
		cout << " test02 除数为 " << e << endl;
	}
}

//异常跨函数
//异常必须处理
int main()
{
	//test01();
	test02();
}
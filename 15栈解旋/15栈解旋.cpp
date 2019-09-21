#include<iostream>

using namespace std;


class Person {
public:
	Person() {
		cout << "对象构建！" << endl;
	}
	~Person() {
		cout << "对象析构！" << endl;
	}
};

//异常基本语法
int divied(int x, int y) {

	Person p1, p2; // 栈解旋：当dived出现异常，则局部变量，将自动析构掉。
	if (y == 0) {
		throw y;//抛出异常
	}
}

void test01() {
	//尝试着去捕获异常
	try {
		divied(10, 0);
		divied(20, 0);
	}
	catch (int e) { //异常是根据类型进行匹配的,catch(int)
		cout << "除数为 " << e << endl;
	}
}


//异常跨函数
//异常必须处理
int main()
{
	test01();
}
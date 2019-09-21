#include<iostream>
using namespace std;


class MyException {
public:
	MyException() {
		cout << "构造函数" << endl;
	}

	MyException(const MyException &ex) {
		cout << "构造函数" << endl;
	}

	~MyException() {
		cout << "析构函数" << endl;
	}

};
void func() {
	//throw &(MyException());
	//throw MyException(); //创建匿名对象，调用构造
	throw new MyException();
}

void test01()
{
	//普通类型元素，引用，指针
	//普通元素，异常对象catch处理完之后就析构
	//引用的话，不用调用拷贝构造，异常对象catch处理完之后就析构
	//指针 的话， 需要这样写throw new MyException()，并且手动析构指针，才可以。
	try {
		func();
	} 
	catch (MyException *e) { //拷贝构造
		cout << "异常捕获" << endl;
		delete e;//指针需要自己手动去析构
	}
}
int main() {

	test01();
	return 0;
	


}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//数据交换
void Myswap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//模板技术，类型参数化，编写代码可以忽略类型
//为了让编译器区分是普通函数，模板函数
template<class T> //template<typename T> 告诉编译器，我下面要写编译器函数，不要报错。只对第一个函数生效
void Myswap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01() {
	int a = 10;
	int b = 20;
	//1,自动类型推导
	cout << "a:  " << a << "  b:  " << b << endl;
	Myswap(a, b);//编译器根据你传入的值，进行推导
	cout << "a:  " << a << "  b:  " << b << endl;

	//2,显示的指定类型
	Myswap<int>(a, b);
	cout << "a:  " << a << "  b:  " << b << endl;

}


int main(void)
{
	test01();
	//ctrl + F5 进行调试
}

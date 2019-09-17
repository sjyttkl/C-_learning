#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;



//函数模板的参数必须一一对应
template<class T>
int MyAdd(T a, T b)
{
	cout << "模板函数" << endl;
	return a + b;
}

//因为普通函数可以进行自动类型转换，
//函数模板的参数必须一一对
//C++ 编译器，当参数满足的情况下，会优先选择普通函数，
int MyAdd(int a, char b) {
	cout << "非模板函数" << endl;
	return a + b;
}

//模板函数，可以进行重载
template<class T>
void Print(T a) {

}
template<class T>
void Print(T a, T b) {

}

void test02() {
	int a = 10;
	int b = 20;
	char c1 = 'a';
	char c2 = 'b';
	MyAdd(a, c1);//非模板
	MyAdd(a, b);//模板 --C++ 编译器，当参数满足的情况下，会优先选择普通函数，，MyAdd<>(a,b) ，这样就会调用模板函数了
	MyAdd(c1, b);//非模板  ---因为普通函数中的参数可以进行自动类型转换，函数模板的参数必须一一对应
#if 0
	MyAdd(a, c1);
	MyAdd(a, b);
	MyAdd(c1, b);

#endif 


}


int main(void)
{
	test02();
	//ctrl + F5 进行调试
}
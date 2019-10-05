#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//1、函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值 可以直接用class 也行
struct Myprint
{
	Myprint()
	{
		mNum = 0;
	}
	void operator()(int val)//
	{
		mNum++;
		cout << val << endl;
	}
public:
	int mNum;
};

int num = 0;//真正在开发中，尽量避免使用全局变量，加锁解锁
void Myprint02(int val)
{
	num++;
	cout << val << endl;
}
void test01()
{
	Myprint print;
	print(10);


	//函数对象可以像普通函数一样进行调用
	//函数对象可以像普通函数那样接收参数
	//函数对象超出了函数的概念，函数对象可以保存函数的调用状态。
}

void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);
	v.push_back(90);
	v.push_back(70);



	

	//计算函数调用次数
#if 0
	Myprint02(10);
	Myprint02(20);
	cout << num << endl;
	
	Myprint print;
	print(10);
	print(20);
	print(20);
	cout << print.mNum << endl;
#endif
	Myprint print;
	Myprint print02 = for_each (v.begin(), v.end(),print );
	cout << "运行前  print调用次数 " << print.mNum << endl;
	cout << "运行后  print调用次数 " << print02.mNum << endl;
}
int main(void)
{
	//test01();
	test02();
	system("pause");
	return 0;
}
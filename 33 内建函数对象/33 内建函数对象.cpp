#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional> //内建函数头文件
using namespace std;

void test01()
{
	plus<int> myplus;
	cout << myplus(10, 20) << endl;
}

int main(void)
{
	test01();
	system("pause");
	return 0;
}
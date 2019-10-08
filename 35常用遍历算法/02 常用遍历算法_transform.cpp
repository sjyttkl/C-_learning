#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//常用遍历算法 transform

class Transform
{
	//仿函数
public:
	int operator()( int v)
	{
		return v+10;//可以加入一些逻辑运算
	}
};

class MyPrint {
public:
	void  operator()(int v){
		cout << " v = " << v << " ";
	}
};

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int> vTarget;//目标容器

	vTarget.resize(v.size());//需要提前开辟空间

	transform(v.begin(), v.end(), vTarget.begin(), Transform());
	
	for_each(vTarget.begin(), vTarget.end(),MyPrint());
	cout << endl;

}

int main()
{
	test01();
	system("pause");
	return 0;
}
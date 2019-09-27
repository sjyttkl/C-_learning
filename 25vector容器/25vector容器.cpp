#include<iostream>
#include<string>
#include<vector>
using namespace std;

void PrintVector(vector<int> & v)
{
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}


void test01()
{
	vector<int> v1; //默认构造

	int arr[] = { 20,10,23,90 };
	vector<int> v2(arr, arr + sizeof(arr) / sizeof(int));//使用数组对vector进行初始化
	vector<int> v3(v2.begin(), v2.end());
	vector<int> v4(v3);

	PrintVector(v4);
	
}
//赋值操作
void test02()
{
	int arr[] = { 20,10,23,90 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));
	
	vector<int> v2;
	v2.assign(v1.begin(), v1.end());

	//重载
	vector<int> v3;
	v3 = v2;
	int arr1[] = { 200,100,300,400 };
	vector<int> v4(arr1, arr1 + sizeof(arr1) / sizeof(int));

	v4.swap(v1);//数据交换，只是对内部指针进行了交换
	PrintVector(v1);
	PrintVector(v2);
	PrintVector(v3);
	PrintVector(v4);

	cout <<"---------------" <<endl;

}
//大小操作
void test03()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	PrintVector(v1);
	if (v1.empty())
	{
		cout << "v1为空" << endl;
	}
	else
	{
		cout << "v1不为空" << endl;
		cout << "v1的容量 = " << v1.capacity() << endl;
		cout << "v1的大小 = " << v1.size() << endl;
	}

	//resize 重新指定大小 ，若指定的更大，默认用0填充新位置，可以利用重载版本替换默认填充
	v1.resize(15, 10);
	PrintVector(v1);

	//resize 重新指定大小 ，若指定的更小，超出部分元素被删除
	v1.resize(5);
	PrintVector(v1);
}
//数据取操作
void test04()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;

	cout << "v1的第一个元素为： " << v1.front() << endl;
	cout << "v1的最后一个元素为： " << v1.back() << endl;
}
//插入和删除
void test05()
{
	vector<int> v1;
	//尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	PrintVector(v1);
	//尾删
	v1.pop_back();
	PrintVector(v1);
	//插入
	v1.insert(v1.begin(), 100);
	PrintVector(v1);

	v1.insert(v1.begin(), 2, 1000);
	PrintVector(v1);

	//删除
	v1.erase(v1.begin());
	PrintVector(v1);

	//清空
	v1.erase(v1.begin(), v1.end());
	v1.clear();
	PrintVector(v1);
}

//收缩空间
void test06()
{
	//vector添加数据会，自动增长，如果减少元素的还是，空间会收缩吗？、不会，
	vector<int> v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;

	v.resize(10);
	cout << "--------------------" << endl;
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;


	//收缩空间,
	vector<int>(v).swap(v);
	cout << "--------------------" << endl;
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;

}

void test07()
{
	vector<int> v;

	//预留空间
	v.reserve(100000);

	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}

	cout << "扩张 空间多少次 ：  num:" << num << endl;
}
int main()
{
	//test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
}

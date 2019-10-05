#include<iostream>
#include <deque>
#include<algorithm>
using namespace std;

void printDeque(  deque<int> &d)
{
	cout << "sdf" << endl;
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}

	cout << endl;
} 


//deque构造
void test01()
{
	deque<int> d1;//无参构造函数
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	deque<int> d2(d1.begin(), d1.end());
	printDeque(d2);

	deque<int>d3 (10, 100);
	printDeque(d3);

	deque<int> d4 = d3;
	printDeque(d4);

	if (d4.empty())
	{
		cout << "d4 为空 " << endl;
	}
	else
	{
		cout << "d4 不为空" << endl;
		cout << "d4大小："<<d4.size() << endl;
	}
	
}

void test02()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(3);
	d.push_front(4);
	d.push_front(10);
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << "  ";
	}
	cout << endl;
	for (int i = 0; i < d.size(); i++)
	{
		cout << d.at(i) << "   ";
	}
	cout << endl;

	cout << " front " << d.front() << endl;
	cout << " back " << d.back() << endl;
	printDeque(d);

	sort(d.begin(), d.end());
	printDeque(d);

}

int main(void)
{
	//test01();
	test02();
	return 0;
}
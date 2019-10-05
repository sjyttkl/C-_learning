#include<iostream>
#include<map>
#include<string>
using namespace std;
void printMap(map<int,int> &m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key ==  " << it->first << "  value = " << it->second << endl;
	}
	cout << endl;
}
void test01()
{
	
	map<int, int> m;//默认构造函数
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(5, 50));

	printMap(m);
	if (m.empty())
	{
		cout << " m 为空" << endl;
	}
	else
	{
		cout << "m不为空 " << endl;
		cout << "m的大小为： " << m.size() << endl;

	}
}

void test02()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	map<int, int>m2;
	m2.insert(pair<int, int>(4, 100));
	m2.insert(pair<int, int>(5, 200));
	m2.insert(pair<int, int>(6, 300));


	cout << "交换前" << endl;
	printMap(m);
	printMap(m2);

	cout << "交换后" << endl;
	m.swap(m2);
	printMap(m);
	printMap(m2);

}

void test03()
{
	//插入
	map<int, int> m;
	//第一种插入方式
	m.insert(pair<int, int>(1, 10));
	//第二种插入方式
	m.insert(make_pair<int, int>(2, 20));
	//第三种插入方式
	m.insert(map<int, int>::value_type(3, 30));
	//第四种插入方式
	m[4] = 40;
	//删除
	m.erase(m.begin());
	printMap(m);

	m.erase(3);
	printMap(m);

	//清空
	m.erase(m.begin(), m.end());
	m.clear();
	printMap(m);

}
//map查找和统计
void test04()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair<int, int>(2, 20));
	m.insert(map<int, int>::value_type(3, 30));

	//查找
	map<int,int> ::iterator pos = m.find(3);

	if (pos != m.end())
	{
		cout << " 找到了元素 key = " << (*pos).first << " value = " << (*pos).second << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

	pair<map<int, int> ::iterator ,map<int,int>::iterator> ret= m.equal_range(2);//返回容器中key与keyelem相等的上下限的两个迭代器？
	map<int, int>::iterator ret2 = m.lower_bound(2);//返回第一个key>= keyElem元素的迭代器
	map<int, int>::iterator ret3 = m.upper_bound(2);////返回第一个key> keyElem元素的迭代器

	//(*(ret.first)).first
	if (ret.first->second)
	{
		cout << "找到low_bound " << endl;
	}
	else
	{
		cout << "没有找到" << endl;
	}
	if (ret.second->second)
	{
		cout << "找到upper_bound " << endl;
	}
	else
	{
		cout << "没有找到" << endl;
	}

	//统计
	int num = m.count(3);
	cout << " num = " << num << endl;
}

//map容器排序
class MyCompare2
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test05()
{
	//默认从小到大排序
	//利用仿函数实现从大到小排序
	map<int, int, MyCompare2> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));

	for (map<int, int, MyCompare2>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key: " << it->first << " value " << it->second << endl;
	}


}

//map补充，在map中放入自定义类型，需要定义仿函数进行排序，map不明白自定义数据类型咋排序，会报错
class Mykey {
public:
	Mykey(int index, int id)
	{
		this->m_id = id;
		this->m_index = index;
	}
public:
	int m_index;
	int m_id;
};

struct myCompare3
{
public:
	bool operator()(Mykey key1, Mykey key2)
	{
		return key1.m_index > key2.m_index;
	}
};
void test06()
{
	map<Mykey, int,myCompare3> mymap;//自动排序，自定义数据类型，咋排？
	mymap.insert(make_pair (Mykey(1, 2), 10));
	mymap.insert(make_pair(Mykey(2, 5), 20));
	mymap.insert(make_pair(Mykey(3, 6), 30));
	for(map<Mykey,int, myCompare3> ::iterator it = mymap.begin(); it != mymap.end(); it++)
	{
		cout << it->first.m_index << "  :   " << it->first.m_id <<" value: "<<it->second<< endl;
	}
}

void test07()
{
	map<int, int> mymap;
	mymap.insert(make_pair(1, 1));
	mymap.insert(make_pair(2, 2));
	mymap.insert(make_pair(3, 3));

	mymap.find(3);
}
int main(void)
{
	//test01();
	//test03();
	test04();	
	test05();
	test06();
	system("pause");
}
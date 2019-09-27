#include<iostream>
#include<string>
using namespace std;

//初始化
void test01() {
	string a1; //无参构造函数
	string a2("abcdefg", 10);
	string a3("abcdefd");
	string a4(a3);//拷贝构造

	cout << a1 << endl;
	cout << a2 << endl;
	cout << a3 << endl;
	cout << a4 << endl;
}

//赋值操作
void test02()
{
	string s1;
	string s2("aap");
	s1 = "abcdfdsf";
	cout << s1 << endl;
	s1 = s2;
	cout << s1 << endl;
	s1 = "a";
	cout << s1 << endl;

	//成员方法
	s1.assign("jdk");
	cout << s1 << endl;
}
//取值操作
void test03()
{
	string  s1 = "abcdefg";
	//重载[]操作符
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << "";  //使用[] 操作如果角标越界会直接程序停止
	}
	cout << endl;
	//at 成员函数
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1.at(i) << " "; //使用at 操作如果角标越界会 抛出异常 out of range
	}
	cout << endl;


}
//字符串拼接
void test04()
{
	string s = "adbcd";
	string s2 = "1111";
	s += "adbdfsf";
	s += s2;
	cout << s << endl;

	string s3 = "22222";

	s2.append(s3);
	
	cout << s2 << endl;

	string s4 = s2 + s3;
	cout << s4 << endl;

}

//查找操作
void test05()
{
	string s = "adbdsfdsf";
	int pos = s.find("f");
	cout << "第一次出现的位置pos  " << pos << endl;

	int pos2 = s.rfind("f");
	cout << "第 最后一次出现的位置pos  " << pos2 << endl;
}

//替换
void test06() {
	string s = "asdbdsfd";
	s.replace(0, 2, "111");
	cout << s << endl;
}
//string比较
void test07()
{
	string s1 = "adbc";
	string s2 = "avg";
	if (s1.compare(s2) == 0)
	{
		cout << "字符串相等" << endl;
	}
	else {
		cout << "字符串不相等" << endl;
	}
}
//子串
void test08()
{

	string str = "abcdefg";
	string subStr = str.substr(1, 3);
	cout << "subStr = " << subStr << endl;

	string email = "hello@sina.com";
	int pos = email.find("@");
	string username = email.substr(0, pos);
	cout << "username: " << username << endl;

}
//字符串插入和删除
void test09()
{
	string str = "hello";
	str.insert(1, "111");
	cout << str << endl;

	str.erase(1, 3);  //从1号位置开始3个字符 ,删除
	cout << str << endl;
}
int main(void)
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	test09();
}
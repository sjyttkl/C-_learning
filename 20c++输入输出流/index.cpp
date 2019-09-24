#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip> //控制符号
using namespace std;

//标准输入流
void test01() {
	char ch;
	//while ((ch = cin.get()) != EOF) {
	//	cout << ch << endl;
	//}

	//cin.get
	char ch2;
	cin.get(ch2);//读取一个字符

	char buf[256] = { 0 };
	//cin.get(buf, 256);
	cin.getline(buf, 256);//读取一行数据,不读换行符
	cout << buf << endl;
}
//cin.ignore 忽略当前字符
void test02() {
	char ch;
	cin.get(ch);//从缓冲区要数据，阻塞
	//cin.ignore();
	cin.ignore(10,'\n'); //忽略当前字符，从缓冲区取走了
	cin.get(ch);
	cout << ch << endl;
}
void test03()
{
	cout << "请输入数组或者字符串" << endl;
	char ch;
	ch = cin.peek();//偷窥一下缓冲区，返回第一个字符
	if (ch >= '0' && ch <= '9')
	{
		int number;
		cin >> number;
		cout << "您输入的是数字: " << number << endl;
	}
	else {
		char buf[] = { 0 };
		cin >> buf;
		cout << "您输入的是字符串: " << buf << endl;
	}
}


//cin.putback  放回到缓冲区   cin.get  从缓冲区取走一个字符
void test04()
{
	cout << "请输入数组或者字符串" << endl;
	char ch;
	cin.get(ch); //从缓冲区取走一个字符

	if (ch >= '0' &&ch <= '9')
	{
		//ch放回到缓冲区
		cin.putback(ch);
		int number;
		cin >> number;
		cout << "您输入的是数字: " << number << endl;
	}
	else {
		//ch放回到缓冲区
		cin.putback(ch);
		char buf[] = { 0 };
		cin >> buf;
		cout << "您输入的是字符串: " << buf << endl;
	}
}

//标准输出流
void test05() {
	cout << "hello world "; //不会写的客户端
	//cout.flush(); //需要刷新缓冲区
	cout.put('h').put('d').put('1') << endl; //链式输出字符
	cout.write("Hello songdongdong ",strlen("Hello songdongdong "));

}
//格式化输出
void test06() {
	int number = 10;
	cout.unsetf(ios::dec);//卸载当前默认的10进制输出的方式
	cout.setf(ios::oct);//设置八进制输出
	cout.setf(ios::showbase);//把八进制的0到x体现出来
	cout << number << endl;//012 ，八进制的形式。
	cout.unsetf(ios::oct);//卸载八进制
	cout.setf(ios::hex);//设置16进制输出
	cout << number << endl;

	cout.width(10);
	cout.fill('*');//默认右对齐
	cout << number << endl;
	cout.setf(ios::left); //左对齐
	cout << number << endl;


	//通过控制符 设置，需要导入#include<iomanip> //控制符号
	int number2 = 10;
	cout << hex
		<< setiosflags(ios::showbase) //#include<iomanip> //控制符号
		<< setw(10)
		<< setfill('~')
		<< setiosflags(ios::left)
		<< number2
		<< endl;

}


int main(void)
{
	cout;//全局流对象
	cin;
	//cerr有缓冲区，clog没有哦缓冲区
	cerr;//标准错误，输出数据到显示器
	clog;//标注日志，输出数据到显示器


	//test01();
    //test02();
	//test03();
	//test04();
	//test05();
	test06();
	return 0;
}
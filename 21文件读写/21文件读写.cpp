#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream> //读取文件的头文件
using namespace std;
class Person {
public:
	Person(){}
	Person(int age, int id) : age(age), id(id) {}
	void show() {
		cout << "Age: " << age<<"  id: "<<id<< endl;
	}
	
public:
	int age;
	int id;
};
//1,文件读写
void test01() {
	const char * filename = "source.txt";
	const char * TargeName = "target.txt";

	//1,第一种打开文件的方式
	ifstream ism(filename, ios::in); //只读的方式打开文件
	//ofstream osm(TargeName, ios::out);//没有追加效果
	ofstream osm(TargeName, ios::out |ios::app); //有追加效果
	// 2. 第二种打开文件的方式
	//ifstream ism;
	//ism.open(filename, ios::in);

	if (!ism) {
		cout << "打开文件失败" << endl;
		return;
	}
    // 读取文件
	char ch;
	while (ism.get(ch))
	{
		cout << ch;
		osm.put(ch);//读进去
	}

	//关闭文件
	ism.close();
	osm.close();
}


//2.二进制文件操作，对象序列化
void test02() {

	//文本模式读的是文本文件吗？
	//二进制模式读的是二进制文件吗？
	Person p1(10, 20), p2(30, 40);//二进制保存
	//把p1,p2 写入到文件里
	
	const char * TargetName = "target.txt";
	ofstream osm(TargetName, ios::out|ios::binary);

	osm.write((char*)&p1, sizeof(Person));//二进制的方式写文件
	osm.write((char*)&p2, sizeof(Person));
	osm.close();


	//读取文件
	cout << "读取文件" << endl;
	ifstream ism(TargetName, ios::in | ios::binary);
	Person  p3,p4;
	ism.read((char *)&p3, sizeof(Person)); //从文件中读取二进制文件
	ism.read((char *)&p4, sizeof(Person)); //从文件中读取二进制文件

	p3.show();
	p4.show();
	cout << p3.age << endl;
}
int main(void) {
	//test01();
	test02();
	return 0;
}
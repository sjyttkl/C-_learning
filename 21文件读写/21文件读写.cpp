#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream> //读取文件的头文件
using namespace std;

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

int main(void) {
	test01();
	return 0;
}
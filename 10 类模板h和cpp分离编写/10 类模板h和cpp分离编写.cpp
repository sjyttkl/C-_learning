#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


//#include"Person.h"
#include"Person.hpp"//独立编译,防止出现问题， 把cpp改为hpp



int main(void) {

	//让连接器去找实现吧
	Person<int> p(10);//构造函数定义在当前文件并没有找到，编译认为这个函数在其他文件中编译(Person.h为声明，不会去编译）。
	//让链接器在链接的时候，去找函数实现的具体位置。
	p.Show();
	return 0;
}

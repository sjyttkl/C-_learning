#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


class Building{};
class Animal {};
class Cat: public Animal{};

//static_cast 说明使用
void static_cast_test() {
	int a = 97;
	char c = static_cast<char>(a);//一般类型转换
	cout << c << endl;


	//基础数据类型指针
	//int * p = NULL;
	//char *p = static_cast<char*>(p);//报错，static_cast 不能用于没有继承关系的指针

	//对象指针
	//Building * building = NULL;
	//Animal *ani = static_cast<Building*>(building); //报错

	//转换具有继承关系的指针
	//父类指针转向子类指针
	Animal *ani2 = NULL;
	Cat * cat = static_cast<Cat*>(ani2);

	//子类指针转换成父类指针
	Cat* soncat = NULL;
	Animal * anifather = static_cast<Cat*> (soncat);

	//父类引用转向子类引用
	Animal aniobj;
	Animal & aniref = aniobj;
	Cat & cat2 = static_cast<Cat&> (aniref);

	//子类引用转换成父类引用
	Cat catobj;
	Cat & catref = catobj;
	Animal & anifater2 = static_cast<Animal&>(catref);

	//static_cast 用于内置的数据类型、还用于有继承关系的指针或者引用

}

// dynamic_cast 转换具有继承关系的指针或者引用，在转换前会进行对象类型检查
void dynamic_cast_test() {

	//基础数据类型
	//int a = 10;
	//char c = dynamic_cast<char>(a);//报错，不能用于基础数据类型

    //非基础关系的指针
	//Animal * ani = NULL;
	//Building * building = dynamic_cast<Building*>(ani);//报错，没有继承关系

	//具有继承关系的指针
	//Animal * ani = NULL;
	//Cat * cat = dynamic_cast<Cat*> (ani);//报错，原因在于dynamic_cast会对类型进行检测。因为：父类指针转换成子类指针（从小到大）类型不安全了
	//子类指针可以转换为父类指针（从大到小），类型安全。
	//父类指针转换成子类指针（从小到大）类型不安全了。

	Cat * cat = NULL;
	Animal * ani = dynamic_cast<Animal*>(cat);


	//结论：dynamic_cast 只能转换具有继承关系的指针或者引用，并且 只能由子类型转换成基类型



}

//const_cast  基础数据类型、指针、引用或者对象指针。作用、把const取消掉、
void const_cast_test() {

	//1,基础数据类型
	int a = 10;
	const int& b = a;//引用
	//b = 10;//报错，因为常量不能修改
	int & c = const_cast<int&>(b);//把const功能取消掉
	c = 20;//可以修改，因为const已经被取消了

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;

	//看指针
	const int *p = NULL;
	int * p2 = const_cast<int*>(p);//把const功能取消掉

	int *p3 = NULL;
	const int * p4 = const_cast<const int*>(p3);//增加const功能==转换成const int 类型

	//总结：增加和去除一个变量的const功能

}

//reinterpret_cast 强制类型转换‘无关指针类型，包括函数指针都可以进行转换
typedef void(*FUNC)(int, int); //函数指针
typedef int(*FUNC2)(int,char*);//函数指针
void reinterpret_cast_test() {


	//1. 无关的指针类型都可以进行转换
	Building * building = NULL;
	Animal * ani = reinterpret_cast<Animal*>(building);


	//2. 函数指针转换
	FUNC func1;
	FUNC2 func2 = reinterpret_cast<FUNC2>(func1);


}


/**
	总结：程序员必须知道要转变的类型变量，转换前什么类型，转换后是什么类型，以及转换后有什么后果。
	      一般清康熙，不建议类型转换，避免进行类型转换

*/


int main(void) {
	static_cast_test();
	const_cast_test();
}
#include<iostream>

using namespace std;

int  func(int a, int b)
{
	cout << "func(int a, int b) " << endl;
	return 0;
}

int  func(int a, int b,int c )
{
	cout << "func(int a, int b,int c ) " << endl;
	return 0;
}

//1 。定义一种函数类型
typedef int(MY_FUNC)(int, int);

//2. 定义一个指向 函数类型的指针类型
typedef int(*MY_FUNC_P)(int, int);

int main2(void)
{
	//1.
	MY_FUNC *fp = NULL;
	fp = func;
	fp(10, 20);
	(*fp)(10, 20);

	//2. 这里MY_FUNC_P定义为 指针了，所以不需要 加*
	//函数指针是一个特殊的指针，不能fp1++,
	MY_FUNC_P fp1 = NULL;
	fp1 = func;
	fp1(10, 20);

	//3. 常用
	int(*fp3)(int, int) = NULL;
	fp3 = func;
	fp3(10, 10);



	//4.
	fp3 = func;//fp3 -->func(int,int)
	
	fp3(10, 30);
	//fp3(10, 20, 30);//报错

	//5.函数指针，实际上是在函数指针赋值的时候，是会发生函数重载匹配，
	//     在调用函数指针的时候，所调用的函数就已经固定了。
	int(*fp4)(int, int, int) = NULL;//fp4 -->func(int,int,int)
	fp4 = func;
	fp4(10, 20, 30);

	
	return 0;
}
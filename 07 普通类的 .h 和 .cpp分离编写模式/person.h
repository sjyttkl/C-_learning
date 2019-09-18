#pragma once  // c++  里防止头文件被重复包含
#include<iostream>
#include<string>
/*
#ifndef PERSON_H  //ctrl + shift +U  大写转换  C里面 ，防止头文件被重复包含
#define PERSON_H
#endif // !PERSON_H  //ctrl + shift +U  大写转换  C里面 ， 防止头文件被重复包含
*/

using namespace  std;

class Person {

public:
	Person(string name, int age);//只做声明
	void Show();
public :
	string mName;
	int mAge;
};

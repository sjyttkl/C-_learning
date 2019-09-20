#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template<class T>
class MyArray {

public:
	MyArray(int capacity) {
		this->mCapacity = capacity;
		this->mSize = 0;
		//申请内存
		this->pAddr = new T[this->mCapacity];
	}
	//copy
	MyArray(const MyArray &arr) {
		this->mSize = arr.mSize;
		this->mCapacity = arr.mCapacity;
		//申请内存
		this->pAddr = new T[this->mCapacity];
		//数据拷贝
		for (int i = 0; i < this->mSize; i++) {
			this->pAddr[i] = arr.pAddr[i];
		}
	}

	T & operator[](int index) {
		return this->pAddr[index];//返回一个引用
	}
	//等号重载
	MyArray<T> operator= (const MyArray &arr) {
		if (this->pAddr != NULL) {
			delete[] this->pAddr;
		}
		this->mSize = arr.mSize;
		this->mCapacity = arr.mCapacity;
		//申请内存
		this->pAddr = new T[this->mCapacity];
		//数据拷贝
		for (int i = 0; i < this->mSize; i++) {
			this->pAddr[i] = arr.pAddr[i];
		}
		return *this;
	}
	
	void PushBack(T& data) {
		//判断容器中是否有位置
		if (this->mSize == this->mCapacity) {
			return;
		}
		//调用拷贝构造 = 号操作符
		//1，对象元素必须能够被拷贝
		//2.容器都是值寓意，而非引用寓意，向容器中放入元素，都是放入元素的拷贝份，不是元素本身。
		//3,如果元素的成员有指针，注意深拷贝和浅拷贝的问题。
		this->pAddr[this->mSize] = data;
		//mSize++
		this->mSize++;
	}
//#if 0
	//对右值取引用
	void PushBack(T&& data) {
		//判断容器中是否有位置
		if (this->mSize == this->mCapacity) {
			return;
		}

		this->pAddr[this->mSize] = data;
		//mSize++
		this->mSize++;
	}
//#endif

	//析构函数
	MyArray() {
		if (this->pAddr != NULL) {
			delete[] this->pAddr;
		}
	}
public:

	//一共可以容下多少个元素
	int mCapacity;
	int mSize;
	//保存数据的首地址
	T* pAddr;
};

void test() {
	MyArray<int> marray(20);
	int a = 10, b = 20, c = 30, d = 40;
	marray.PushBack(a);
	marray.PushBack(b);
	marray.PushBack(c);
	marray.PushBack(d);

	//不能对右值取引用，&&
	//左值之可以在多行使用
	//临时变量，智能在当前行使用
	marray.PushBack(100);


	for (int i = 0; i < marray.mSize; i++) {
		cout << marray[i] << endl;
	}
}
class Person {};
void test02()
{
	Person p1, p2;
	MyArray<Person> arr(10);
	arr.PushBack(p1);
	arr.PushBack(p2);

}

int main() {
	test();
}
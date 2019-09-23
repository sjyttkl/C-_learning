#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


//异常基类
class BaseMyException {
public:
	virtual void  what() = 0;
	virtual ~BaseMyException(){}
};

class TargetSpaceNullException :public::BaseMyException{
public:
	virtual void what() {
		cout << "目标空间为空！ " << endl;
	}
	virtual ~TargetSpaceNullException()
	{

	}
};

class SourceSpaceNullException :public::BaseMyException {
public:
	virtual void what() {
		cout << "源空间为空！ " << endl;
	}
	virtual ~SourceSpaceNullException()
	{

	}
};

void copy_str(char*  taget,const char* source) {
	if (taget = NULL) {
		throw TargetSpaceNullException();
		//cout << "目标空间为空！ " << endl;
		//return;
	}
	if (source == NULL) {
		//cout << "源空间为空！ "<< endl;
		//return; 
		throw SourceSpaceNullException();
	}

	//int len = strlen(source)+1;
	while (*source != '\0') {
		*taget = *source;
		taget++;
		source++;
	}


}

int main(void) {
	
	const char * source = "abcdef";

	char buf[1024] = {0};
	
	try
	{
		copy_str(buf, source);
	}
	catch (BaseMyException &ex) {
		ex.what();
	}

	cout << buf << endl;
	return 0;
}

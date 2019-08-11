#pragma once
#include "DanLi.h"
#include <iostream>
#include "Glo_Obj.h"
#include <Windows.h>
using namespace std;


class TextIO :public Glo_Obj
{

	friend class DanLi<TextIO>;  //声明TextIO的友元为单例类模板
private:
	TextIO& operator = (const TextIO& t);	//返回类型是引用类型,一般用于左值
	TextIO(const TextIO&);	//带参数的构造函数???
public:
	TextIO();
	~TextIO();
	static	LPTSTR print();	////声明输出函数,类型为引用(指针常量(不能改变地址))
							//TextIO operator = (const TextIO& t);

};



TextIO::TextIO() {		//构造函数实现
	cout << "TextIO构造函数..." << std::endl;
}

TextIO::~TextIO() {		//析构函数实现
	cout << "TextIO析构函数..." << std::endl;
}

LPTSTR TextIO::print()
{
	return L"aaaaaaaaaaaa";
}




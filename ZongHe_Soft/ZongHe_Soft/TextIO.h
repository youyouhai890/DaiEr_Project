#pragma once
#include "DanLi.h"
#include <iostream>
#include "Glo_Obj.h"
#include <Windows.h>
using namespace std;


class TextIO :public Glo_Obj
{

	friend class DanLi<TextIO>;  //����TextIO����ԪΪ������ģ��
private:
	TextIO& operator = (const TextIO& t);	//������������������,һ��������ֵ
	TextIO(const TextIO&);	//�������Ĺ��캯��???
public:
	TextIO();
	~TextIO();
	static	LPTSTR print();	////�����������,����Ϊ����(ָ�볣��(���ܸı��ַ))
							//TextIO operator = (const TextIO& t);

};



TextIO::TextIO() {		//���캯��ʵ��
	cout << "TextIO���캯��..." << std::endl;
}

TextIO::~TextIO() {		//��������ʵ��
	cout << "TextIO��������..." << std::endl;
}

LPTSTR TextIO::print()
{
	return L"aaaaaaaaaaaa";
}




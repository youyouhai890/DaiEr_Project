#pragma once
#include <iostream>
#include "stdafx.h"

#ifndef _SINGLETON_H_
#define _SINGLETON_H_

template <typename T>
class DanLi
{
private:
	static T* danli;

	DanLi()         //���캯��Ϊprivate
	{
	}

public:
	static T* getInstance()
	{
		return danli;
	}
};


template <typename T>
T*  DanLi<T> ::danli = new T;	//�ȸ���Ա������ֵ

#endif
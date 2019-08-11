#pragma once
#include "Glo_Obj.h"
#include <Windows.h>

class Glo_Obj
{
public:
	Glo_Obj();
	~Glo_Obj();
	static void Gprint(LPTSTR str);
};

Glo_Obj::Glo_Obj()
{
}


Glo_Obj::~Glo_Obj()
{
}


void Glo_Obj::Gprint(LPTSTR str)
{
	MessageBox(NULL, str, L"БъЬт", MB_OK);
}

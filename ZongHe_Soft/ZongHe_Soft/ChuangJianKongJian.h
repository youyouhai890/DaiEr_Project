#pragma once
#include <Windows.h>






HWND ChuangJianKongJian(
	const LPTSTR KongJianMing,			//控件的类名
	const LPTSTR BiaoTi,				//标题(文本自定义)
	DWORD dwStyle,                         //窗口样式(对齐)
	const RECT& ZuoBiao,                           //相对于父窗口的位置矩形
	const HWND hParent,							//控件的父窗口
	const int ID,                                   //ID号
	const HINSTANCE hInst						//应用程序实例
)            
{
	dwStyle |= WS_CHILD | WS_VISIBLE;
	return CreateWindowEx(
		0,
		KongJianMing,                       //控件的类名
		BiaoTi,							 //按钮标题
		dwStyle,						//窗口样式
		ZuoBiao.left,					//坐标
		ZuoBiao.top,
		ZuoBiao.right - ZuoBiao.left,
		ZuoBiao.bottom - ZuoBiao.top,
		hParent,				//控件的父窗口
		reinterpret_cast<HMENU>(static_cast<INT_PTR>(ID)),		//ID号
		hInst,					//应用程序实例
		NULL);
}





#define IDC_BUTTON_1 101

int ChuangJianAnNiu(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {


		RECT WeiZhi = { 50,30,255,55 };	//设定坐标
		ChuangJianKongJian(
			TEXT("BUTTON"),				//控件名
			TEXT("DNF关闭后台进程"),			//标题
			BS_DEFPUSHBUTTON,				 //窗口样式(对齐)
			WeiZhi,										//输入自定义的坐标
			hWnd,										//父窗口类	
			IDC_BUTTON_1,                                  //ID号,用宏来自定义
			(HINSTANCE)  GetWindowLong(hWnd,GWL_HINSTANCE)	//获取指定窗口的有关信息
		);
	return 0;
}



#define IDC_Lable_1 102
//标签控件
int ChuangJianBiaoQian(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	RECT WeiZhi2 = { 300,30,550,55 };	//设定坐标

	ChuangJianKongJian(
		TEXT("STATIC"),				//控件名
		TEXT("标签11111"),			//标题
		BS_DEFPUSHBUTTON,			 //窗口样式(对齐)
		WeiZhi2,										//输入自定义的坐标
		hWnd,								//父窗口类
		IDC_Lable_1,                                  //ID号,用宏来自定义
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE)	//获取指定窗口的有关信息
	);
	return 0;
}



//弹窗提示
void Messb(LPTSTR str) {
	MessageBox(NULL, str, L"标题", MB_OK);
}


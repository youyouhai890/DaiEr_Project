#pragma once
#include <Windows.h>






HWND ChuangJianKongJian(
	const LPTSTR KongJianMing,			//�ؼ�������
	const LPTSTR BiaoTi,				//����(�ı��Զ���)
	DWORD dwStyle,                         //������ʽ(����)
	const RECT& ZuoBiao,                           //����ڸ����ڵ�λ�þ���
	const HWND hParent,							//�ؼ��ĸ�����
	const int ID,                                   //ID��
	const HINSTANCE hInst						//Ӧ�ó���ʵ��
)            
{
	dwStyle |= WS_CHILD | WS_VISIBLE;
	return CreateWindowEx(
		0,
		KongJianMing,                       //�ؼ�������
		BiaoTi,							 //��ť����
		dwStyle,						//������ʽ
		ZuoBiao.left,					//����
		ZuoBiao.top,
		ZuoBiao.right - ZuoBiao.left,
		ZuoBiao.bottom - ZuoBiao.top,
		hParent,				//�ؼ��ĸ�����
		reinterpret_cast<HMENU>(static_cast<INT_PTR>(ID)),		//ID��
		hInst,					//Ӧ�ó���ʵ��
		NULL);
}





#define IDC_BUTTON_1 101

int ChuangJianAnNiu(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {


		RECT WeiZhi = { 50,30,255,55 };	//�趨����
		ChuangJianKongJian(
			TEXT("BUTTON"),				//�ؼ���
			TEXT("DNF�رպ�̨����"),			//����
			BS_DEFPUSHBUTTON,				 //������ʽ(����)
			WeiZhi,										//�����Զ��������
			hWnd,										//��������	
			IDC_BUTTON_1,                                  //ID��,�ú����Զ���
			(HINSTANCE)  GetWindowLong(hWnd,GWL_HINSTANCE)	//��ȡָ�����ڵ��й���Ϣ
		);
	return 0;
}



#define IDC_Lable_1 102
//��ǩ�ؼ�
int ChuangJianBiaoQian(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	RECT WeiZhi2 = { 300,30,550,55 };	//�趨����

	ChuangJianKongJian(
		TEXT("STATIC"),				//�ؼ���
		TEXT("��ǩ11111"),			//����
		BS_DEFPUSHBUTTON,			 //������ʽ(����)
		WeiZhi2,										//�����Զ��������
		hWnd,								//��������
		IDC_Lable_1,                                  //ID��,�ú����Զ���
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE)	//��ȡָ�����ڵ��й���Ϣ
	);
	return 0;
}



//������ʾ
void Messb(LPTSTR str) {
	MessageBox(NULL, str, L"����", MB_OK);
}


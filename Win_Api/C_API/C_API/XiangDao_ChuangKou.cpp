//#include <stdio.h>
//#include <Windows.h>
//#include <locale.h>	
//#include "resource.h"
//
//
////���ڹ��̺���,���ڴ�����Ϣ(�ص�����)
//
//INT_PTR  CALLBACK MainWndProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
//
//int main() {
//
//	setlocale(LC_ALL, "");		//���õ���
//
//	char str1[] = "��ͨ�ַ���";		//����ASC2��	
//
//	//int ChangDu = strlen(str1);
//int KuanChangDu = MultiByteToWideChar(	//���ֽ�(ASC2)ת���ַ�(Unicode)����,ע�����ﷵ�صĳ�����wchar_t����ĳ���,����char�ĳ���
//				CP_ACP,		//����ת������ASC2��	
//				0,			//���Ʊ�־,һ����Ϊ0
//				str1,		//Ҫת�����ַ���
//				-1,			//�������ַ��������'\0'
//				NULL,		//ת���Ժ�Ҫ�洢���ݵ�ָ��,NULL��ʾ����ת��
//				0			//ָ��ת���Ժ�洢�ռ�(ǰһ������)�Ĵ�С,���ڲ����洢������0
//		);
//	printf("��ǰUnicode����ַ�������Ϊ---%d\n", KuanChangDu);
//
//
//	wchar_t * str2 = NULL;	//ָ�����NULLһ��
//	str2= new wchar_t[KuanChangDu];
//	if (!str2)		//����ʧ�ܽ���
//	{
//		printf("����ʧ��");
//
//		delete[] str2;	//�ͷ�ָ��
//		return 1;
//	}
//
//	 MultiByteToWideChar(//���ֽ�(ASC2)ת���ַ�(Unicode)����,ע�����ﷵ�صĳ�����wchar_t����ĳ���,����char�ĳ���
//		CP_ACP,		//����ת������ASC2��	
//		0,			//���Ʊ�־,һ����Ϊ0
//		str1,		//Ҫת�����ַ���
//		-1,			//�������ַ��������'\0'
//		 str2,		//ת���Ժ�Ҫ�洢���ݵ�ָ��,NULL��ʾ����ת��
//		 KuanChangDu			//ָ��ת���Ժ�洢�ռ�(ǰһ������)�Ĵ�С
//	);
//	 wprintf(L"����ַ���Ϊ---%s\n", str2);
//
//	 //=============================================================================
//
//	 wchar_t strr3[] = L"���ַ�(Unicode)����";
//
//	 int ChangDu = WideCharToMultiByte(//���ַ�(UNICODE)ת���ֽ�(ASC2)�ĺ���,,ע�����ﷵ�صĳ�����char����ĳ���,����wchar_t�ĳ���
//		 CP_OEMCP,		//����ת������ASC2��	
//		 0,			//���Ʊ�־,һ����Ϊ0
//		 strr3,		//Ҫת�����ַ���
//		 -1,			//�������ַ��������'\0'
//		 NULL,		//ת���Ժ�Ҫ�洢���ݵ�ָ��,NULL��ʾ����ת��
//		 0,			//ָ��ת���Ժ�洢�ռ�(ǰһ������)�Ĵ�С
//		 NULL,		//���ַ�ת��ʧ��ʱ�õ���ǰ�����ͺ����
//		 NULL
//	 );
//
//	 printf("��ǰASC2����ַ�������Ϊ---%d\n", ChangDu);
//
//	 char *str4 = NULL;	
//	 str4 = new char[ChangDu];
//	 if (!str4)
//	 {
//		 delete[] str4;	//��ʼ��ʧ��,�ͷ��ڴ�
//		 return 1;
//	 }
//	  WideCharToMultiByte(  //���ַ�(UNICODE)ת���ֽ�(ASC2)�ĺ���,,ע�����ﷵ�صĳ�����char����ĳ���,����wchar_t�ĳ���
//				 CP_OEMCP,		//����ת������ASC2��	
//				 0,			//���Ʊ�־,һ����Ϊ0
//				 strr3,		//Ҫת�����ַ���
//				 -1,			//�������ַ��������'\0'
//				 str4,		//ת���Ժ�Ҫ�洢���ݵ�ָ��,NULL��ʾ����ת��
//				 ChangDu,			//ָ��ת���Ժ�洢�ռ�(ǰһ������)�Ĵ�С
//				 NULL,			//���ַ�ת��ʧ��ʱ�õ���ǰ�����ͺ����
//				 NULL
//	 );
//
//	 printf("����ַ���Ϊ---%s\n", str4);
//
//	 delete[]	str2;
//	 delete[]	str4;
//
//	return 0;
//}
//
//int APIENTRY WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
//{
//
//	//DialogBox(
//	//	hinstance,	//ʵ�����
//	//	MAKEINTRESOURCE(IDD_DIALOG1),	//������Դ,��ԴIDΪIDD_DIALOG1(�Ի���(����))
//	//	NULL,							//û�и�����
//	//	MainWndProc		//���ڹ��̺���(������Ϣ)
//	//);
//}
//
//
//INT_PTR  CALLBACK MainWndProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//
//	TCHAR a[5] = { 0 };
//
//	BOOL bol = TRUE;
//	//uMsgΪ���ڹ��̺���Ҫ�������Ϣ
//	switch (uMsg)
//	{
//	case WM_CLOSE:		//���ǶԻ���رյ�����,���ǶԻ���Ļ��ر���ϢΪWM_DESTROY
//		EndDialog(hDlg, 0);	//�˳��Ի���(����),���ǶԻ���Ļ��˳���������ΪPostQuitMessage(0);
//		break;
//	case WM_COMMAND:	//������ⰴť���յ������Ϣ,������Ҫ��ťID���ж�
//
//		switch (LOWORD(wParam))		//�����Ϣ����(wParam ), �����Ϣ�����ĵ�λ��(LOWORD)
//		{
//		case IDOK:		//��Ϣ����wParam�ĵ�λ(LOWORD)��IDΪIDOKʱ
//			MessageBox(hDlg, "ȷ����ť��", "����Ϊȷ��", MB_OK);
//			break;
//		case IDCANCEL:		//��Ϣ����wParam�ĵ�λ(LOWORD)��IDΪIDOKʱ
//			MessageBox(hDlg, "ȡ����ť", "����Ϊȡ��", MB_OK);
//			break;
//		default:		////Ĭ�ϴ�����Ϣ
//			bol = FALSE;	//Ӧ����0	
//			break;
//		}
//
//	default:	//Ĭ�ϴ�����Ϣ
//		bol = FALSE;	//Ӧ����0	
//	}
//
//	return bol;
//
//}

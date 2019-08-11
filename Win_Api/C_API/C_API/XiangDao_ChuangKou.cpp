//#include <stdio.h>
//#include <Windows.h>
//#include <locale.h>	
//#include "resource.h"
//
//
////窗口过程函数,用于处理消息(回调函数)
//
//INT_PTR  CALLBACK MainWndProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
//
//int main() {
//
//	setlocale(LC_ALL, "");		//设置地域
//
//	char str1[] = "普通字符串";		//代表ASC2码	
//
//	//int ChangDu = strlen(str1);
//int KuanChangDu = MultiByteToWideChar(	//多字节(ASC2)转宽字符(Unicode)函数,注意这里返回的长度是wchar_t计算的长度,不是char的长度
//				CP_ACP,		//代表转换的是ASC2码	
//				0,			//控制标志,一般设为0
//				str1,		//要转换的字符串
//				-1,			//不计算字符串后面的'\0'
//				NULL,		//转换以后要存储数据的指针,NULL表示不做转换
//				0			//指定转换以后存储空间(前一个参数)的大小,由于不做存储所以是0
//		);
//	printf("当前Unicode码的字符串长度为---%d\n", KuanChangDu);
//
//
//	wchar_t * str2 = NULL;	//指针最好NULL一下
//	str2= new wchar_t[KuanChangDu];
//	if (!str2)		//分配失败结束
//	{
//		printf("分配失败");
//
//		delete[] str2;	//释放指针
//		return 1;
//	}
//
//	 MultiByteToWideChar(//多字节(ASC2)转宽字符(Unicode)函数,注意这里返回的长度是wchar_t计算的长度,不是char的长度
//		CP_ACP,		//代表转换的是ASC2码	
//		0,			//控制标志,一般设为0
//		str1,		//要转换的字符串
//		-1,			//不计算字符串后面的'\0'
//		 str2,		//转换以后要存储数据的指针,NULL表示不做转换
//		 KuanChangDu			//指定转换以后存储空间(前一个参数)的大小
//	);
//	 wprintf(L"输出字符串为---%s\n", str2);
//
//	 //=============================================================================
//
//	 wchar_t strr3[] = L"宽字符(Unicode)类型";
//
//	 int ChangDu = WideCharToMultiByte(//宽字符(UNICODE)转多字节(ASC2)的函数,,注意这里返回的长度是char计算的长度,不是wchar_t的长度
//		 CP_OEMCP,		//代表转换的是ASC2码	
//		 0,			//控制标志,一般设为0
//		 strr3,		//要转换的字符串
//		 -1,			//不计算字符串后面的'\0'
//		 NULL,		//转换以后要存储数据的指针,NULL表示不做转换
//		 0,			//指定转换以后存储空间(前一个参数)的大小
//		 NULL,		//宽字符转换失败时用到当前参数和后面的
//		 NULL
//	 );
//
//	 printf("当前ASC2码的字符串长度为---%d\n", ChangDu);
//
//	 char *str4 = NULL;	
//	 str4 = new char[ChangDu];
//	 if (!str4)
//	 {
//		 delete[] str4;	//初始化失败,释放内存
//		 return 1;
//	 }
//	  WideCharToMultiByte(  //宽字符(UNICODE)转多字节(ASC2)的函数,,注意这里返回的长度是char计算的长度,不是wchar_t的长度
//				 CP_OEMCP,		//代表转换的是ASC2码	
//				 0,			//控制标志,一般设为0
//				 strr3,		//要转换的字符串
//				 -1,			//不计算字符串后面的'\0'
//				 str4,		//转换以后要存储数据的指针,NULL表示不做转换
//				 ChangDu,			//指定转换以后存储空间(前一个参数)的大小
//				 NULL,			//宽字符转换失败时用到当前参数和后面的
//				 NULL
//	 );
//
//	 printf("输出字符串为---%s\n", str4);
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
//	//	hinstance,	//实例句柄
//	//	MAKEINTRESOURCE(IDD_DIALOG1),	//调用资源,资源ID为IDD_DIALOG1(对话框(窗口))
//	//	NULL,							//没有副窗口
//	//	MainWndProc		//窗口过程函数(处理消息)
//	//);
//}
//
//
//INT_PTR  CALLBACK MainWndProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//
//	TCHAR a[5] = { 0 };
//
//	BOOL bol = TRUE;
//	//uMsg为窗口过程函数要处理的消息
//	switch (uMsg)
//	{
//	case WM_CLOSE:		//这是对话框关闭的命令,而非对话框的话关闭消息为WM_DESTROY
//		EndDialog(hDlg, 0);	//退出对话框(窗口),而非对话框的话退出窗口命令为PostQuitMessage(0);
//		break;
//	case WM_COMMAND:	//点击任意按钮都收到这个消息,所以需要按钮ID来判断
//
//		switch (LOWORD(wParam))		//检测消息参数(wParam ), 检测消息参数的低位置(LOWORD)
//		{
//		case IDOK:		//消息参数wParam的低位(LOWORD)置ID为IDOK时
//			MessageBox(hDlg, "确定按钮！", "内容为确定", MB_OK);
//			break;
//		case IDCANCEL:		//消息参数wParam的低位(LOWORD)置ID为IDOK时
//			MessageBox(hDlg, "取消按钮", "内容为取消", MB_OK);
//			break;
//		default:		////默认处理消息
//			bol = FALSE;	//应该是0	
//			break;
//		}
//
//	default:	//默认处理消息
//		bol = FALSE;	//应该是0	
//	}
//
//	return bol;
//
//}

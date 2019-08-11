//#include <stdio.h>
//#include <stdlib.h>
//
//#include <Windows.h>
//
//void tprint( PTCHAR pstr) {
//	int i = 0;
//	while (pstr[i] != '\0')
//	{
//		printf("系统目录名%d-----%c\n", i, pstr[i]);
//		//printf("%c", pstr[i]);
//		i++;
//	}
//	printf("\n");
//
//}
//
//int main(int argc, char* argv[]) {
//
//
//
//
//	WCHAR path[MAX_PATH] = {0};	//MAX_PATH库函数里的内置变量
//	//获取系统目录
//	GetSystemDirectory(path, MAX_PATH);
//
//	//printf("系统目录名-----%s\n", path);
//	tprint( path);
//
//	HANDLE JuBing;
//	DWORD ShiJiXieRuChangDu;
//	JuBing = CreateFile(
//						L"系统目录写入.txt",
//						GENERIC_WRITE,			//写入
//						0,						//共享模式
//						NULL,					//安全属性
//						CREATE_ALWAYS,			//总是创建文件
//						FILE_ATTRIBUTE_NORMAL,		//常规属性
//						NULL						
//					);
//
//	if (JuBing != INVALID_HANDLE_VALUE)	//JuBing不等于无效句柄时
//	{
//		if (      !WriteFile(
//					JuBing,					//文件对象
//					path,					//应该是写入的内容
//					50,			//内容的长度
//					&ShiJiXieRuChangDu,		//实际写入的长度
//					NULL)
//			)
//		{
//			return GetLastError();//返回错误信息
//		}
//	}
//	CloseHandle(JuBing);	//关闭句柄
//
//	printf("-----%d", ShiJiXieRuChangDu);
//	
//	return 0;
//}
//
//
//
//

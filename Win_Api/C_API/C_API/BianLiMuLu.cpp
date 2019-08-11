//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//
//
//DWORD BianLiMuLu(LPTSTR ml) {
//	
//	WIN32_FIND_DATA	CunChuMuLuHuoWenJian;	//结构体类型用于存储目录
//	HANDLE JuBing;	//定义句柄(对象)
//	TCHAR MuLu[MAX_PATH];
//		
//		lstrcpy(MuLu, ml);	//拷贝字符串
//		lstrcat(MuLu, TEXT("\\*"));	//追加字符串,相当于D:\\MyWorkspase\\*
//		printf("完整路径-----------%s\n", MuLu);
//
//				//查找所有子目录和文件,结果存储到结构体
//		JuBing = FindFirstFile(MuLu, &CunChuMuLuHuoWenJian);
//
//		if (JuBing == INVALID_HANDLE_VALUE) //检测结果集对象
//		{
//			printf("错误-----------%d\n", GetLastError());
//			return 1;
//		}
//		else
//		{
//			do
//			{
//				if (
//					lstrcmp(CunChuMuLuHuoWenJian.cFileName,TEXT("."))==0	//比较字符串
//					|| lstrcmp(CunChuMuLuHuoWenJian.cFileName, TEXT(".."))==0
//					)
//				{
//					continue;
//				}
//
//				//输出目录或文件名
//				printf("%s--------------------", CunChuMuLuHuoWenJian.cFileName);
//
//				if (CunChuMuLuHuoWenJian.dwFileAttributes & FILE_ATTRIBUTE_ENCRYPTED)
//				{
//					printf("<加密文件>\t");
//				}
//				if (CunChuMuLuHuoWenJian.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN)
//				{
//					printf("<隐藏文件>\t");
//				}
//				if (CunChuMuLuHuoWenJian.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
//				{
//					printf("<当前为目录>\t");
//				}
//				printf("\n");
//
//			} while (FindNextFile(JuBing, &CunChuMuLuHuoWenJian)); //遍历所有目录或文件(应该是移动指针)
//		}
//		return 0;
//}
//
//int main() {
//
//	BianLiMuLu(TEXT("D:\\MyWorkspase"));
//	return 0;
//}
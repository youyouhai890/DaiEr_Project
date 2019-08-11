//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//
//DWORD MuLuShuLiang = 0;
//
//DWORD ListAllFileInDirectrory(LPTSTR ShangYiGeLuJing) {
//
//	WIN32_FIND_DATA ZiMuLu_OR_WenJian;	//用于存储目录或文件的结构体类型
//	HANDLE DuiXiang;			//应该是用为关联子目录或文件的对象
//	TCHAR WanZhengLuJing[MAX_PATH];
//	TCHAR HuanCun[MAX_PATH];
//
//	lstrcpy(WanZhengLuJing, ShangYiGeLuJing);		//拷贝字符串
//	lstrcat(WanZhengLuJing, TEXT("\\*"));	//字符串追加
//
//	DuiXiang = FindFirstFile(WanZhengLuJing, &ZiMuLu_OR_WenJian);	//搜索第一个目录
//	if (DuiXiang == INVALID_HANDLE_VALUE)
//	{
//		printf("错误 : %d\n", GetLastError());
//		return 1;
//	}
//	else
//	{
//		do
//		{
//			//把无用的目录过滤掉, (.)为当前目录 , (..)为上一个目录
//	    	if (
//				lstrcmp(ZiMuLu_OR_WenJian.cFileName, TEXT(".")) == 0 ||
//				lstrcmp(ZiMuLu_OR_WenJian.cFileName,TEXT(".."))==0
//			)
//			{
//				continue;	//跳过当前循环
//			}
//
//
//			//将变量ZiMuLu_OR_WenJian.cFileName的值格式化为字符串(%s\\%s)输出到缓冲区HuanCun指向的内存单元。
//			wsprintf(HuanCun, "%s\\%s", ShangYiGeLuJing, ZiMuLu_OR_WenJian.cFileName);
//			MuLuShuLiang++;
//			printf("\n%d\t%s", MuLuShuLiang, HuanCun);
//
//			if (ZiMuLu_OR_WenJian.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)	//检测是否为目录
//			{
//				printf("<DIR>");	//目录标志
//				ListAllFileInDirectrory(HuanCun);	//如果是目录就调用递归函数
//			}
//		} while (FindNextFile(DuiXiang,&ZiMuLu_OR_WenJian));	//搜索下一个目录或文件
//	}
//
//	return 0;
//}
//
//
//
//
//int main() {
//
//	ListAllFileInDirectrory(TEXT("D:\\DownLoad\\BaiDuDown"));
//
//	return 0;
//}
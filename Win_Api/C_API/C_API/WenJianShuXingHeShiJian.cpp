//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//
//
////时间转换过程,源时间(世界时间) ->北京时间(本地时间) -> 系统时间
//DWORD XianShiWenJianShiJian(PFILETIME YuanShiJian) {
//	FILETIME BenDiShiJian;	
//	SYSTEMTIME XiTongShiJian;
//	FileTimeToLocalFileTime(YuanShiJian, &BenDiShiJian);	//把源时间(世界时间)转换为本地时间(北京时间)
//	FileTimeToSystemTime(&BenDiShiJian, &XiTongShiJian);	//把本地时间(北京时间)转换为系统时间
//
//	printf("%d年%#02d月%#2d日, %#2d: %#2d: %#2d:\n"
//		, XiTongShiJian.wYear
//		, XiTongShiJian.wMonth
//		, XiTongShiJian.wDay
//		, XiTongShiJian.wHour
//		, XiTongShiJian.wMinute
//		, XiTongShiJian.wSecond);
//
//	return 0;
//
//}
//
////合并位数,普通的DWORD类型只能保存4G,所以用两个DWORD类型结合起来
//DWORD XianShiWenJianDaXiao(DWORD GaoWei , DWORD DiWei) {
//	ULONGLONG HeBing;	//定义64位无符号变量,U表示无符号
//
//	HeBing = GaoWei;	//把32位的变量(GaoWei)放到64位变量(HeBing)的低32位里
//	HeBing <<= 32;	//把64位的变量左移32位,放到高32位里
//	HeBing += DiWei;	//把32位的变量(DiWei)追加到64位变量((HeBing))的低32位里
//	printf("文件大小: \t %I64u 字节\n",HeBing);
//
//	return 0;
//}
//
////获取文件属性
//DWORD XianShiWenJianShuXing(DWORD dwAttribute) {
//
//	printf("显示文件属性: \t");
//	if (dwAttribute & FILE_ATTRIBUTE_ARCHIVE)		//归档属性
//	{
//		printf("<归档属性> ");
//	}
//	if (dwAttribute & FILE_ATTRIBUTE_COMPRESSED)		//压缩
//	{
//		printf("<压缩> ");
//	}	
//	if (dwAttribute & FILE_ATTRIBUTE_READONLY)		//只读
//	{
//		printf("<只读> ");
//	}	
//	if (dwAttribute & FILE_ATTRIBUTE_DIRECTORY)		//目录
//	{
//		printf("<目录> ");
//	}
//	if (dwAttribute & FILE_ATTRIBUTE_ENCRYPTED)		//加密
//	{
//		printf("<加密> ");
//	}	
//	if (dwAttribute & FILE_ATTRIBUTE_HIDDEN)		//隐藏
//	{
//		printf("<隐藏> ");
//	}	
//	if (dwAttribute & FILE_ATTRIBUTE_NORMAL)		//NORMAL
//	{
//		printf("<NORMAL> ");
//	}	
//	if (dwAttribute & FILE_ATTRIBUTE_OFFLINE)		//OFFLINE
//	{
//		printf("<OFFLINE> ");
//	}	
//	if (dwAttribute & FILE_ATTRIBUTE_SYSTEM)		//系统
//	{
//		printf("<系统> ");
//	}
//
//	return 0;
//}
//
//DWORD XianShiShuXing(LPTSTR LuJing) {
//
//	WIN32_FILE_ATTRIBUTE_DATA	ShuXing;	//用于获取文件属性的结构体
//	printf("文件: %s\n", LuJing);
//
//	//把文件的属性存储到WIN32_FILE_ATTRIBUTE_DATA结构体变量里
//	if (!GetFileAttributesEx(LuJing,GetFileExInfoStandard, &ShuXing))
//	{
//		printf("获取文件属性失败: %s\n", GetLastError());
//		return 1;
//	}
//	printf("创建时间: \t");
//	XianShiWenJianShiJian(&(ShuXing.ftCreationTime));
//	printf("访问时间: \t");
//	XianShiWenJianShiJian(&(ShuXing.ftLastAccessTime));	
//	printf("修改时间: \t");
//	XianShiWenJianShiJian(&(ShuXing.ftLastWriteTime));
//
//	//参数为高低位,普通的DWORD类型只能保存4G,所以用两个DWORD类型结合起来
//	XianShiWenJianDaXiao(ShuXing.nFileSizeHigh, ShuXing.nFileSizeLow);	
//	//显示文件属性
//	XianShiWenJianShuXing(ShuXing.dwFileAttributes);	
//
//	return 2;
//}
//
//
//DWORD SheZhiWenJianShuXing(LPTSTR WenJianLuJing) {
//
//	//获取文件所有属性
//	DWORD ShuXing = GetFileAttributes(WenJianLuJing);
//	//用位或(|)运算来设置文件属性
//	ShuXing |= FILE_ATTRIBUTE_READONLY;
//	ShuXing |= FILE_ATTRIBUTE_HIDDEN;
//	if (SetFileAttributes(WenJianLuJing, ShuXing))	//设置文件属性
//	{
//		printf("文件 %s 隐藏属性和只读属性设置成功\n", WenJianLuJing);
//	}
//	else
//	{
//		printf("属性设置失败 %d\n",GetLastError());
//	}
//	return 0;
//}
//
//int main() {
//
//	//XianShiShuXing(TEXT("D:\\YouXi\\Warcraft 3.zip"));
//
//
//	SheZhiWenJianShuXing(TEXT("D:\\YouXi\\Warcraft 3.zip"));
//	return 0;
//}

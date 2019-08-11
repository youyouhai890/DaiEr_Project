//
//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//
//
//#define size 1024
//int main() {
//
//	////char类型
//	//CHAR HuoQuPanFuMing[size];
//	////CHAR的指针类型*CHAR
//	//PCHAR YiDongZhiZhen = NULL;
//	////把分配后的内存的垃圾数据清零
//	//ZeroMemory(HuoQuPanFuMing, size);
//
//	////获取所有盘符名,size-1是最后要保留'\0'(空)的字符
//	//GetLogicalDriveStrings(size - 1, HuoQuPanFuMing);
//	////printf("%s\n", HuoQuPanFuMing);	//由于获取的字符串中间以空字符('\0')分割,所以printf只能获取第一个盘符
//
//	////移动指针(移动每个字符串),可以理解为移动字符串数组
//	////由于字符串里面有空('\0')字符,所以读取到空('\0')字符时会返回当前指针
//	//YiDongZhiZhen = (PCHAR)HuoQuPanFuMing;	//获取第一个字符串的指针地址
//	//do
//	//{
//	//	printf("%s  ", YiDongZhiZhen); //往字符串指针里存储读取到的内容,遇到空('\0')字符时会返回
//	//	YiDongZhiZhen += (lstrlen(YiDongZhiZhen) + 1); //移动到下一个字符串的开头,遇到空('\0')字符时会返回
//	//} while (*YiDongZhiZhen !='\x00');	//这里\x00是16进制,也可以用'\0'
//
//	//printf("\n\n");
//	////////////////////////////////////////////////////////////////////////////
//	//TCHAR HuoQuSheBeiMing[size];
//	//HANDLE hand;	//任意句柄
//	//BOOL bol=true;
//
//	//hand = FindFirstVolume(HuoQuSheBeiMing, size);	//获取第一个盘符的设备名称,返回一个句柄(对象)
//
//	//if (hand == INVALID_HANDLE_VALUE)
//	//{
//	//	printf(TEXT("没有找到句柄(对象)....."));
//	//}
//	//printf("设备名称为:------%s\n", HuoQuSheBeiMing);
//
//	////移动到下一个盘符(移动指针)
//	//while (FindNextVolume(hand, HuoQuSheBeiMing, size))	
//	//{
//	//	printf("设备名称为:------%s\n", HuoQuSheBeiMing);
//	//}
//
//	//bol = FindVolumeClose(hand);	//关闭句柄,返回1时true
//	//printf("BOOL的值为:------%d\n", (int)bol);
//	//return bol;		//返回0时正常
//
//	//////////////////////////////////////////
//	char aa[] = "aaa\0bbb\0ccc\0";
//
//	char *bb = NULL;
//	//获取第一个字符串的指针地址
//	bb = (char*)aa;
//	//bb = &aa;
//	printf("----%p\n", bb);
//	printf("----%s\n", bb);
//
//	bb += lstrlen(aa) + 1;	//移动指针到下一个字符串开头
//	printf("----%p\n", bb);
//	printf("----%s\n", bb);
//
//	bb += lstrlen(aa) + 1;
//	printf("----%p\n", bb);
//	printf("----%s\n", bb);
//
//	return 0;		//返回0时正常
//
//}
//

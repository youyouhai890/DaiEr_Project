//
//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//
//
//#define DangQianWenJian	//定义当前文件宏
//
//#define SIZE_BUF 256
//
//int main(int GeShu , char *CanShuNeiRong[]) {
//
//#pragma region 文件操作(移动,重命名,拷贝)
//
//
//
//	////printf("参数个数-----%d\n", GeShu);
//	////printf("第一个参数的值为-----%s\n", CanShuNeiRong[0]);
//	////printf("第二个参数的值为-----%s\n", CanShuNeiRong[1]);
//	////printf("第三个参数的值为-----%s\n", CanShuNeiRong[2]);
//	//
//	////lstrcmp比较两个字符串，此比较不区分大小写。若第一个字符串比第二个字符串小则返回值为负；
//	////若第一个字符串比第二个字符串大则返回值为正；若两个字符串相等则返回值为0。
//	//if (0 == lstrcmp("-sc",CanShuNeiRong[1]) && GeShu==3)	//命令行方式删除文件
//	//{
//	//	if (!DeleteFile(CanShuNeiRong[2]))	//API函数DeleteFile为删除文件
//	//	{
//	//		printf("删除文件发生错误:%x\n", GetLastError());
//
//	//	}
//	//	else
//	//	{
//	//		printf("删除文件成功...\n");
//
//	//	}
//	//}
//	//else if(0==lstrcmp("-kb",CanShuNeiRong[1]) && GeShu==4 )	//命令行方式拷贝文件
//	//{
//	//	if (!CopyFile(CanShuNeiRong[2],CanShuNeiRong[3],TRUE))  //API函数DeleteFile为拷贝文件,TRUE为不覆盖
//	//	{
//	//			if (GetLastError() == 0x50)	//检测错误
//	//			{
//	//					printf("%s文件已经存在,是否覆盖???...y/n \n",CanShuNeiRong[3]);
//	//					if ('y' == getchar())	//从键盘接受字符
//	//					{
//	//						if (!CopyFile(CanShuNeiRong[2],CanShuNeiRong[3],FALSE))//API函数DeleteFile为拷贝文件,FALSE覆盖
//	//						{
//	//							printf("复制文件时发生错误...%d\n",GetLastError());
//	//						}
//	//						else
//	//						{
//	//							printf("复制成功...\n");
//	//						}
//
//	//					}
//	//					else
//	//					{
//	//						printf("输入错误...\n");
//	//						return 0;
//	//					}
//	//			}
//	//			else
//	//			{
//	//					return 0;
//	//			}
//	//	}
//	//}
//	////lstrcmp比较两个字符串，此比较不区分大小写。若第一个字符串比第二个字符串小则返回值为负；
//	////若第一个字符串比第二个字符串大则返回值为正；若两个字符串相等则返回值为0。
//	//else if(0==lstrcmp("-gm",CanShuNeiRong[1]) && GeShu==4 )
//	//{
//	//	if (!MoveFile(CanShuNeiRong[2],CanShuNeiRong[3]))	//修改文件名
//	//	{
//	//		printf("重命名文件时发生错误...%d\n",GetLastError());
//	//	}
//	//	else
//	//	{
//	//		printf("修改文件名称成功...%d\n");
//
//	//	}
//	//		
//	//}
//	//else
//	//{
//	//		printf("参数错误...\n");
//	//}
//
//#pragma endregion
//
//#pragma region C语言方式读写文件
//
//	//FILE *WenJianLiuDuQu, *WenJianLiuXieRu;
//	//char HuanCun[SIZE_BUF];
//	//size_t DuQuLiuNeiRongGeShu, XieRuLiuNeiRongGeShu;	//size_t类型对应 无符号int类型
//
//	//if (GeShu !=3)
//	//{
//	//	printf("参数的数量不对...\n");
//	//}
//	////命令行方式操作的文件为,当前目录里的文件
//	//WenJianLiuDuQu = fopen(CanShuNeiRong[1], "rb");	//2进制方式读取,每次读取一个字节
//	//if (WenJianLiuDuQu==NULL)
//	//{
//	//	perror(CanShuNeiRong[1]);	//错误函数
//	//	return 2;
//	//}
//
//	//WenJianLiuXieRu = fopen(CanShuNeiRong[2], "wb");//2进制方式写入,每次写入一个字节
//	//if (WenJianLiuXieRu == NULL)
//	//{
//	//	perror(CanShuNeiRong[2]);	//错误函数
//	//	return 3;
//	//}
//	////每次循环读取256个字节, DuQuLiuNeiRongGeShu为实际读到的个数
//	//while ((DuQuLiuNeiRongGeShu = fread(HuanCun,1, SIZE_BUF, WenJianLiuDuQu))>0)	//DuQuLiuNeiRongGeShu==0时读取结束
//	//{
//	//	//把缓存里的内容写入文件, XieRuLiuNeiRongGeShu为实际写入的个数
//	//	XieRuLiuNeiRongGeShu = fwrite(HuanCun, 1, DuQuLiuNeiRongGeShu, WenJianLiuXieRu);
//	//	if (XieRuLiuNeiRongGeShu != DuQuLiuNeiRongGeShu)
//	//	{
//	//		perror("字节数不对");	//错误函数
//	//		return 4;
//	//	}
//
//	//}
//
//	//fclose(WenJianLiuDuQu);
//	//fclose(WenJianLiuXieRu);
//#pragma endregion
//
//#pragma region WINAPI方式读写文件
//	
//		//HANDLE DuQuLiuDuiXiang, XieRuLiuDuiXiang;	//流对象
//		//DWORD DuQu_ShiJiDaXiao, XieRu_ShiJiDaXiao;
//		//CHAR	buffer[SIZE_BUF];
//
//		//if (GeShu !=3)
//		//{
//		//	printf("参数的数量不对...\n");
//		//}
//
//		//DuQuLiuDuiXiang  = CreateFile(		//应该是获取读取流对象
//		//	CanShuNeiRong[1],		//文件名(默认为当前文件) 
//		//	GENERIC_READ,			//读取模式 , 应该还有写入模式
//		//	FILE_SHARE_READ,		//共享模式(应该是指当前文件)
//		//	NULL,					//NULL表示默认的安全属性
//		//	OPEN_EXISTING,			//打开已经存在的文件,应该还有创建文件
//		//	FILE_ATTRIBUTE_NORMAL,	//文件属性为常规
//		//	NULL					//模版(应该可以指定一个模板)
//		//);
//
//		//if (DuQuLiuDuiXiang == INVALID_HANDLE_VALUE)
//		//{
//		//	printf("读取流对象时发生错误:%x\n", GetLastError());
//		//}
//
//
//		//XieRuLiuDuiXiang = CreateFile(		//应该是获取写入流对象
//		//	CanShuNeiRong[2],		//文件名(默认为当前文件) 
//		//	GENERIC_WRITE,			//读取模式 , 应该还有写入模式
//		//	0,					//共享模式(应该是指当前文件)
//		//	NULL,					//NULL表示默认的安全属性
//		//	CREATE_ALWAYS,			//总是创建文件
//		//	FILE_ATTRIBUTE_NORMAL,	//文件属性为常规
//		//	NULL					//模版(应该可以指定一个模板)
//		//);
//		//if (XieRuLiuDuiXiang == INVALID_HANDLE_VALUE)
//		//{
//		//	printf("写入流对象时发生错误:%x\n", GetLastError());
//		//}
//
//		////每次循环复制256字节,如果ReadFile()函数返回的结果为0表示已经读取完成,大于0表示读取内容
//		//	while (
//		//				ReadFile(		//读取文件函数
//		//						DuQuLiuDuiXiang,	//指定读取流文件对象(句柄)
//		//						buffer,	//缓存名称
//		//						SIZE_BUF,		//缓存大小
//		//						&DuQu_ShiJiDaXiao,	//实际读取的大小个数
//		//						NULL
//		//					)  && DuQu_ShiJiDaXiao >0
//		//		)
//		//		{
//		//				WriteFile(
//		//						XieRuLiuDuiXiang,	//指定写入流文件对象
//		//						buffer,	//缓存名称
//		//						DuQu_ShiJiDaXiao,	//由于是拷贝文件所以这里要跟读取的字节数量一样
//		//						&XieRu_ShiJiDaXiao,	//实际写入的的大小个数
//		//						NULL
//		//					);
//		//					if (XieRu_ShiJiDaXiao != DuQu_ShiJiDaXiao)
//		//					{
//		//						printf("写入和读取的实际大小不符合\n");
//		//						return 4;
//		//					}
//		//		}
//
//		////释放流对象
//		//CloseHandle(DuQuLiuDuiXiang);
//		//CloseHandle(XieRuLiuDuiXiang);
//
//
//#pragma endregion
//
//#pragma region WINAPI拷贝文件(推荐)
//
//		if (!CopyFile(CanShuNeiRong[1], CanShuNeiRong[2],FALSE))	//拷贝文件函数,FALSE为总是覆盖文件(有同名时)
//		{
//			printf("拷贝文件时发生错误:%x\n", GetLastError());
//			return 6;
//		}
//
//#pragma endregion
//
//
//	return 0;
//}
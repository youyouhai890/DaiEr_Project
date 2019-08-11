#include <stdio.h>
#include <stdlib.h>  //可以应用rand()随机数
#include <time.h>		//调用时间相关函数
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "TouWenJian.h"	//导入自己创建的头文件

extern int errno;	//引用外部变量

struct JieGouTi {
	char str1[50];
	char str2[100];
	int  it;
};
struct bs {
	unsigned a : 1;	//1位
	unsigned b : 3;	//3位
	unsigned c : 4;
} bit, *pbit;

//共用体
union Data
{
	int i;
	float f;
	char  str[20];
};
typedef struct t1 {		
	short x;	//short占两个字节
	char y;
	int z;
	char l;		//12
	int ll;		//16 
}T1;

typedef struct t2 {	
	int x;
	short z;
	char y;
	char l;		//8
	char ll;	//12
}T2;


//参数转换为字符串常量时，则使用字符串常量化运算符（#）
#define  message_for(a, b)  \
    {printf(#a " and " #b ": We love you!\n");}

#define HeBingCanCshu(n) printf ("ShuChu" #n " = %d", ShuChu##n)

#if !defined (MESSAGE)
#define MESSAGE "没有定义过"
#endif

#define square(x) ((x) * (x))
#define square_1(x) (x * x)

int main()
{
#pragma region 函数指针
	//int HanShu1(int, int);	//声明函数
	////声明函数指针,返回类型为int类型 , 参数为(int,int)
	//int(*HanShuZhiZhen)(int, int) = NULL;
	//HanShuZhiZhen = HanShu1;	//前面的&符号可以省略

	//printf("从键盘接受两个数字,再存到对应变量的地址里:\n");
	//int x, y;
	////从键盘接受两个数字,再存到对应变量的地址里
	//scanf("%d %d", &x, &y);

	//int c;
	////启用函数指针里的函数
	//c = HanShuZhiZhen(x, y);
	//printf("函数返回后的值为 %d\n", c);

#pragma endregion

#pragma region 回调函数

	////函数声明
	//int FuZhi();
	//void HuiDiaoHanShu(int *, int, int(*)(void));

	//int Array[10];
	//HuiDiaoHanShu(Array,10, &FuZhi);	//调用已经定义的函数,第三个参数的&符号可以省略

	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d ",Array[i]);
	//}
	//printf("\n");

#pragma endregion

#pragma region 2级指针

	//int  var;
	//int  *ptr;
	//int  **pptr;

	//var = 3000;

	///* 获取 var 的地址 */
	//ptr = &var;

	///* 使用运算符 & 获取 ptr 的地址 */
	//pptr = &ptr;

	///* 使用 pptr 获取值 */
	//printf("Value of var = %d\n", var);
	//printf("Value available at *ptr = %d\n", *ptr);
	//printf("Value available at **pptr = %d\n\n\n", **pptr);

	//printf("显示地址 *pptr = %p\n", *pptr);
	//printf("显示地址 ptr = %p\n", ptr);

#pragma endregion

#pragma region 结构体
	//void pntfun(struct JieGouTi *jj);
	//void pntfun(char  * jj);
	////声明结构体
	//struct JieGouTi jgt[2];
	//strcpy(jgt[0].str1, "第一个结构体");
	//strcpy(jgt[0].str2, "第二个结构体");
	//jgt[0].it = 123456;

	////printf("输出字符串1--%s\n", jgt.str1);
	////printf("输出字符串2--%s\n", jgt.str2);
	////printf("输出int类型--%d\n\n", jgt.it);

	//
	//pntfun(jgt[0].str1);


	//bit.a = 1;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
	//bit.b = 7;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
	//bit.c = 15;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
	//printf("%d,%d,%d\n", bit.a, bit.b, bit.c);    /* 以整型量格式输出三个域的内容 */
	//pbit = &bit;    /* 把位域变量 bit 的地址送给指针变量 pbit */
	//pbit->a = 0;    /* 用指针方式给位域 a 重新赋值，赋为 0 */
	//pbit->b &= 3;    /* 使用了复合的位运算符 "&="，相当于：pbit->b=pbit->b&3，位域 b 中原有值为 7，与 3 作按位与运算的结果为 3（111&011=011，十进制值为 3） */
	//pbit->c |= 1;    /* 使用了复合位运算符"|="，相当于：pbit->c=pbit->c|1，其结果为 15 */
	//printf("%d,%d,%d\n", pbit->a, pbit->b, pbit->c);    /* 用指针方式输出了这三个域的值 */

#pragma endregion

#pragma region 共用体
	//union Data data;

	//data.i = 10;
	//data.f = 220.5;
	//strcpy(data.str, "C Programming");

	//printf("data.i : %d\n", data.i);
	//printf("data.f : %f\n", data.f);
	//printf("data.str : %s\n", data.str);


#pragma endregion

#pragma region I/O(输入/输出)

//char str[100];
//
//printf("Enter a value : ");
//gets_s(str);
//
//printf("\nYou entered: ");
//puts(str);

#pragma endregion


#pragma region 文件的读写

//////////////////////////////////////////////写入文件////////////////////////////////
//FILE *fp = NULL;
////fopen创建一个文件或者打开一个已有的文件
//fp = fopen("D:/aaa/bbb.txt", "w+");
////直接把字符串写入到文件中(意味着只能写入到文件里)
//fprintf(fp, "直接把字符串写入到文件中...\n");
////把字符串输写入到fp所指向的输出流中(意味着可以写入到内存)
//fputs("把字符串输写入到fp所指向的输出流中...\n", fp);
////如果成功关闭文件，fclose( ) 函数返回零，如果关闭文件时发生错误，函数返回 EOF。
//fclose(fp);

//////////////////////////////////////////////读取文件////////////////////////////////
//FILE *fp = NULL;
//char buff[255];
//
//fp = fopen("D:/aaa/bbb.txt", "r");
////从文件中读取字符串，但是在遇到第一个空格字符时，它会停止读取。
//fscanf(fp, "%s", buff);
//printf("1: %s\n", buff);
//
////从 fp 所指向的输入流中读取 n - 1 个字符。它会把读取的字符串复制到缓冲区 buff，并在最后追加一个 null('\0') 字符来终止字符串。
//fgets(buff, 255, (FILE*)fp);
//printf("2: %s\n", buff);
//
////从 fp 所指向的输入流中读取 n - 1 个字符。它会把读取的字符串复制到缓冲区 buff，并在最后追加一个 null('\0') 字符来终止字符串。
//fgets(buff, 255, (FILE*)fp);
//printf("3: %s\n", buff);
//fclose(fp);

//////////////////////////////////////////////指针读写///////////////////////////////
//FILE *fp = NULL;
//fp = fopen("D:/aaa/bbb.txt", "r+");  // 确保 test.txt 文件已创建
////把指针往后移动10个字节, 注意：只有用 r+ 模式打开文件才能插入内容
//fseek(fp, 10, SEEK_SET);
//if (fputc(65, fp) == EOF) {
//	printf("fputc fail");
//}
//fclose(fp);

//////////////////////////////////////////////追加模式写入文件///////////////////////////////

FILE *fp = NULL;
fp = fopen("D:/aaa/bbb.txt", "a+");  // 确保 test.txt 文件已创建
// 在test.txt文件末尾追加写入
fputs("\n这里是追加的内容.", fp);
// 关闭文件
fclose(fp);

#pragma endregion

#pragma region 预处理器

//下面是预定义的宏,可直接调用
//printf("File :%s\n", __FILE__);	//这会包含当前文件名，一个字符串常量。
//printf("Date :%s\n", __DATE__);	//当前日期，一个以 "MMM DD YYYY" 格式表示的字符常量。
//printf("Time :%s\n", __TIME__); //当前时间，一个以 "HH:MM:SS" 格式表示的字符常量。
//printf("Line :%d\n", __LINE__);	//这会包含当前行号，一个十进制常量。
/////////////////////////////////////////////////////////////
//message_for(123, bbb);
////////////////////////////////////////////////////
//int ShuChu33=11;
//HeBingCanCshu(33);
///////////////////////////////////////////////

//printf("检测是否已经使用 #define 定义过 : %s\n", MESSAGE);

//////////////////////
//printf("square 5+4 is %d\n", square(5 + 4));
//printf("square_1 5+4 is %d\n", square_1(5 + 4));



#pragma endregion

#pragma region 头文件(扩展名为 .h 的文件，包含了 C 函数声明和宏定义)

//printf("调用头文件里的宏---%d", Hong_1);


#pragma endregion


#pragma region 错误处理
	FILE * pf;
	int errnum;
	pf = fopen("unexist.txt", "rb");
	if (pf == NULL)
	{
		errnum = errno;
		fprintf(stderr, "错误号: %d\n", errno);
		perror("通过 perror 输出错误");
		fprintf(stderr, "打开文件错误: %s\n", strerror(errnum));
	}
	else
	{
		fclose(pf);
	}
#pragma endregion




	return 0;
}

void pntfun(char  * jj) {
	printf("这里是函数字符串1--%s\n", jj);
	//printf("这里是函数字符串2--%s\n", jj->str2);
	//printf("这里是函数int类型3--%d\n", jj->it);
}

int HanShu1(int a,int b) {

	int s= a > b ? a : b;
	return s;
}

//设定回调函数,最后的参数为函数指针
void HuiDiaoHanShu(int *ShuZu, int ChangDu,int (*ZhiZhenHanShu)(void)) {
	for (int i = 0; i < ChangDu; i++)
	{
		ShuZu[i] = ZhiZhenHanShu();	//调用指针里的函数
	}
}

int FuZhi() {
	return rand();
}


int * getRandom()
{
	static int  r[10];
	int i;

	/* 设置种子 */
	srand((unsigned)time(NULL));
	for (i = 0; i < 10; ++i)
	{
		r[i] = rand();	//获得随机数
		printf("%d\n", r[i]);
	}

	return r;

}

#include <stdio.h>
#include <stdlib.h>  //����Ӧ��rand()�����
#include <time.h>		//����ʱ����غ���
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "TouWenJian.h"	//�����Լ�������ͷ�ļ�

extern int errno;	//�����ⲿ����

struct JieGouTi {
	char str1[50];
	char str2[100];
	int  it;
};
struct bs {
	unsigned a : 1;	//1λ
	unsigned b : 3;	//3λ
	unsigned c : 4;
} bit, *pbit;

//������
union Data
{
	int i;
	float f;
	char  str[20];
};
typedef struct t1 {		
	short x;	//shortռ�����ֽ�
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


//����ת��Ϊ�ַ�������ʱ����ʹ���ַ����������������#��
#define  message_for(a, b)  \
    {printf(#a " and " #b ": We love you!\n");}

#define HeBingCanCshu(n) printf ("ShuChu" #n " = %d", ShuChu##n)

#if !defined (MESSAGE)
#define MESSAGE "û�ж����"
#endif

#define square(x) ((x) * (x))
#define square_1(x) (x * x)

int main()
{
#pragma region ����ָ��
	//int HanShu1(int, int);	//��������
	////��������ָ��,��������Ϊint���� , ����Ϊ(int,int)
	//int(*HanShuZhiZhen)(int, int) = NULL;
	//HanShuZhiZhen = HanShu1;	//ǰ���&���ſ���ʡ��

	//printf("�Ӽ��̽�����������,�ٴ浽��Ӧ�����ĵ�ַ��:\n");
	//int x, y;
	////�Ӽ��̽�����������,�ٴ浽��Ӧ�����ĵ�ַ��
	//scanf("%d %d", &x, &y);

	//int c;
	////���ú���ָ����ĺ���
	//c = HanShuZhiZhen(x, y);
	//printf("�������غ��ֵΪ %d\n", c);

#pragma endregion

#pragma region �ص�����

	////��������
	//int FuZhi();
	//void HuiDiaoHanShu(int *, int, int(*)(void));

	//int Array[10];
	//HuiDiaoHanShu(Array,10, &FuZhi);	//�����Ѿ�����ĺ���,������������&���ſ���ʡ��

	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d ",Array[i]);
	//}
	//printf("\n");

#pragma endregion

#pragma region 2��ָ��

	//int  var;
	//int  *ptr;
	//int  **pptr;

	//var = 3000;

	///* ��ȡ var �ĵ�ַ */
	//ptr = &var;

	///* ʹ������� & ��ȡ ptr �ĵ�ַ */
	//pptr = &ptr;

	///* ʹ�� pptr ��ȡֵ */
	//printf("Value of var = %d\n", var);
	//printf("Value available at *ptr = %d\n", *ptr);
	//printf("Value available at **pptr = %d\n\n\n", **pptr);

	//printf("��ʾ��ַ *pptr = %p\n", *pptr);
	//printf("��ʾ��ַ ptr = %p\n", ptr);

#pragma endregion

#pragma region �ṹ��
	//void pntfun(struct JieGouTi *jj);
	//void pntfun(char  * jj);
	////�����ṹ��
	//struct JieGouTi jgt[2];
	//strcpy(jgt[0].str1, "��һ���ṹ��");
	//strcpy(jgt[0].str2, "�ڶ����ṹ��");
	//jgt[0].it = 123456;

	////printf("����ַ���1--%s\n", jgt.str1);
	////printf("����ַ���2--%s\n", jgt.str2);
	////printf("���int����--%d\n\n", jgt.it);

	//
	//pntfun(jgt[0].str1);


	//bit.a = 1;    /* ��λ��ֵ��Ӧע�⸳ֵ���ܳ�����λ�������Χ�� */
	//bit.b = 7;    /* ��λ��ֵ��Ӧע�⸳ֵ���ܳ�����λ�������Χ�� */
	//bit.c = 15;    /* ��λ��ֵ��Ӧע�⸳ֵ���ܳ�����λ�������Χ�� */
	//printf("%d,%d,%d\n", bit.a, bit.b, bit.c);    /* ����������ʽ�������������� */
	//pbit = &bit;    /* ��λ����� bit �ĵ�ַ�͸�ָ����� pbit */
	//pbit->a = 0;    /* ��ָ�뷽ʽ��λ�� a ���¸�ֵ����Ϊ 0 */
	//pbit->b &= 3;    /* ʹ���˸��ϵ�λ����� "&="���൱�ڣ�pbit->b=pbit->b&3��λ�� b ��ԭ��ֵΪ 7���� 3 ����λ������Ľ��Ϊ 3��111&011=011��ʮ����ֵΪ 3�� */
	//pbit->c |= 1;    /* ʹ���˸���λ�����"|="���൱�ڣ�pbit->c=pbit->c|1������Ϊ 15 */
	//printf("%d,%d,%d\n", pbit->a, pbit->b, pbit->c);    /* ��ָ�뷽ʽ��������������ֵ */

#pragma endregion

#pragma region ������
	//union Data data;

	//data.i = 10;
	//data.f = 220.5;
	//strcpy(data.str, "C Programming");

	//printf("data.i : %d\n", data.i);
	//printf("data.f : %f\n", data.f);
	//printf("data.str : %s\n", data.str);


#pragma endregion

#pragma region I/O(����/���)

//char str[100];
//
//printf("Enter a value : ");
//gets_s(str);
//
//printf("\nYou entered: ");
//puts(str);

#pragma endregion


#pragma region �ļ��Ķ�д

//////////////////////////////////////////////д���ļ�////////////////////////////////
//FILE *fp = NULL;
////fopen����һ���ļ����ߴ�һ�����е��ļ�
//fp = fopen("D:/aaa/bbb.txt", "w+");
////ֱ�Ӱ��ַ���д�뵽�ļ���(��ζ��ֻ��д�뵽�ļ���)
//fprintf(fp, "ֱ�Ӱ��ַ���д�뵽�ļ���...\n");
////���ַ�����д�뵽fp��ָ����������(��ζ�ſ���д�뵽�ڴ�)
//fputs("���ַ�����д�뵽fp��ָ����������...\n", fp);
////����ɹ��ر��ļ���fclose( ) ���������㣬����ر��ļ�ʱ�������󣬺������� EOF��
//fclose(fp);

//////////////////////////////////////////////��ȡ�ļ�////////////////////////////////
//FILE *fp = NULL;
//char buff[255];
//
//fp = fopen("D:/aaa/bbb.txt", "r");
////���ļ��ж�ȡ�ַ�����������������һ���ո��ַ�ʱ������ֹͣ��ȡ��
//fscanf(fp, "%s", buff);
//printf("1: %s\n", buff);
//
////�� fp ��ָ����������ж�ȡ n - 1 ���ַ�������Ѷ�ȡ���ַ������Ƶ������� buff���������׷��һ�� null('\0') �ַ�����ֹ�ַ�����
//fgets(buff, 255, (FILE*)fp);
//printf("2: %s\n", buff);
//
////�� fp ��ָ����������ж�ȡ n - 1 ���ַ�������Ѷ�ȡ���ַ������Ƶ������� buff���������׷��һ�� null('\0') �ַ�����ֹ�ַ�����
//fgets(buff, 255, (FILE*)fp);
//printf("3: %s\n", buff);
//fclose(fp);

//////////////////////////////////////////////ָ���д///////////////////////////////
//FILE *fp = NULL;
//fp = fopen("D:/aaa/bbb.txt", "r+");  // ȷ�� test.txt �ļ��Ѵ���
////��ָ�������ƶ�10���ֽ�, ע�⣺ֻ���� r+ ģʽ���ļ����ܲ�������
//fseek(fp, 10, SEEK_SET);
//if (fputc(65, fp) == EOF) {
//	printf("fputc fail");
//}
//fclose(fp);

//////////////////////////////////////////////׷��ģʽд���ļ�///////////////////////////////

FILE *fp = NULL;
fp = fopen("D:/aaa/bbb.txt", "a+");  // ȷ�� test.txt �ļ��Ѵ���
// ��test.txt�ļ�ĩβ׷��д��
fputs("\n������׷�ӵ�����.", fp);
// �ر��ļ�
fclose(fp);

#pragma endregion

#pragma region Ԥ������

//������Ԥ����ĺ�,��ֱ�ӵ���
//printf("File :%s\n", __FILE__);	//��������ǰ�ļ�����һ���ַ���������
//printf("Date :%s\n", __DATE__);	//��ǰ���ڣ�һ���� "MMM DD YYYY" ��ʽ��ʾ���ַ�������
//printf("Time :%s\n", __TIME__); //��ǰʱ�䣬һ���� "HH:MM:SS" ��ʽ��ʾ���ַ�������
//printf("Line :%d\n", __LINE__);	//��������ǰ�кţ�һ��ʮ���Ƴ�����
/////////////////////////////////////////////////////////////
//message_for(123, bbb);
////////////////////////////////////////////////////
//int ShuChu33=11;
//HeBingCanCshu(33);
///////////////////////////////////////////////

//printf("����Ƿ��Ѿ�ʹ�� #define ����� : %s\n", MESSAGE);

//////////////////////
//printf("square 5+4 is %d\n", square(5 + 4));
//printf("square_1 5+4 is %d\n", square_1(5 + 4));



#pragma endregion

#pragma region ͷ�ļ�(��չ��Ϊ .h ���ļ��������� C ���������ͺ궨��)

//printf("����ͷ�ļ���ĺ�---%d", Hong_1);


#pragma endregion


#pragma region ������
	FILE * pf;
	int errnum;
	pf = fopen("unexist.txt", "rb");
	if (pf == NULL)
	{
		errnum = errno;
		fprintf(stderr, "�����: %d\n", errno);
		perror("ͨ�� perror �������");
		fprintf(stderr, "���ļ�����: %s\n", strerror(errnum));
	}
	else
	{
		fclose(pf);
	}
#pragma endregion




	return 0;
}

void pntfun(char  * jj) {
	printf("�����Ǻ����ַ���1--%s\n", jj);
	//printf("�����Ǻ����ַ���2--%s\n", jj->str2);
	//printf("�����Ǻ���int����3--%d\n", jj->it);
}

int HanShu1(int a,int b) {

	int s= a > b ? a : b;
	return s;
}

//�趨�ص�����,���Ĳ���Ϊ����ָ��
void HuiDiaoHanShu(int *ShuZu, int ChangDu,int (*ZhiZhenHanShu)(void)) {
	for (int i = 0; i < ChangDu; i++)
	{
		ShuZu[i] = ZhiZhenHanShu();	//����ָ����ĺ���
	}
}

int FuZhi() {
	return rand();
}


int * getRandom()
{
	static int  r[10];
	int i;

	/* �������� */
	srand((unsigned)time(NULL));
	for (i = 0; i < 10; ++i)
	{
		r[i] = rand();	//��������
		printf("%d\n", r[i]);
	}

	return r;

}

#include <stdio.h>
#include <float.h>

int main()
{
	char ch = 'A';
	char str[20] = "www.runoob.com";
	float flt = 10.234;
	int no = 150;
	double dbl = 20.123456;
	printf("�ַ�Ϊ %c \n", ch);
	printf("�ַ���Ϊ %s \n", str);
	printf("������Ϊ %f \n", flt);
	printf("����Ϊ %d\n", no);
	printf("˫����ֵΪ %lf \n", dbl);
	printf("�˽���ֵΪ %o \n", no);
	printf("ʮ������ֵΪ %x \n\n\n", no);


	//sizeof
	printf("int���ʹ�СΪ %d \n", sizeof(int));
	printf("char���ʹ�СΪ %d \n", sizeof(char));
	printf("float���ʹ�СΪ %d \n", sizeof(float));
	printf("double���ʹ�СΪ %d \n\n\n\n", sizeof(double));

	/////////////////
	printf("float �洢����ֽ��� : %d \n", sizeof(float));
	printf("float ָ����Сֵ: %E\n", FLT_MIN);
	printf("float ָ�����ֵ: %E\n", FLT_MAX);
	printf("float ��Сֵf: %f\n", FLT_MIN);
	printf("float ���ֵ: %f\n", FLT_MAX);
	printf("����ֵ: %d\n", FLT_DIG);
	return 0;
}


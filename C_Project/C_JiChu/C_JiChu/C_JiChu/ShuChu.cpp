#include <stdio.h>
#include <float.h>

int main()
{
	char ch = 'A';
	char str[20] = "www.runoob.com";
	float flt = 10.234;
	int no = 150;
	double dbl = 20.123456;
	printf("字符为 %c \n", ch);
	printf("字符串为 %s \n", str);
	printf("浮点数为 %f \n", flt);
	printf("整数为 %d\n", no);
	printf("双精度值为 %lf \n", dbl);
	printf("八进制值为 %o \n", no);
	printf("十六进制值为 %x \n\n\n", no);


	//sizeof
	printf("int类型大小为 %d \n", sizeof(int));
	printf("char类型大小为 %d \n", sizeof(char));
	printf("float类型大小为 %d \n", sizeof(float));
	printf("double类型大小为 %d \n\n\n\n", sizeof(double));

	/////////////////
	printf("float 存储最大字节数 : %d \n", sizeof(float));
	printf("float 指数最小值: %E\n", FLT_MIN);
	printf("float 指数最大值: %E\n", FLT_MAX);
	printf("float 最小值f: %f\n", FLT_MIN);
	printf("float 最大值: %f\n", FLT_MAX);
	printf("精度值: %d\n", FLT_DIG);
	return 0;
}


#include <stdio.h>

//int main()
//{
//	/* 我的第一个 C 程序 */
//	printf("Hello, World! \n");
//
//	return 0;
//}

int main(int argc, char *argv[])
{
	/* 我的第一个 C 程序 */
	printf("可执行程序 %s ,参数个数为[%d], 运行输出：[%s]\n\n", argv[0], argc, argv[1]);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i; j++)
		{

			printf("*");
		}
		printf("\n");
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <5- i; j++)
		{

			printf("*");
		}
		printf("\n");
	}
	return 0;
}


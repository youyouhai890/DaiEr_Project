#include <stdio.h>

//int main()
//{
//	/* �ҵĵ�һ�� C ���� */
//	printf("Hello, World! \n");
//
//	return 0;
//}

int main(int argc, char *argv[])
{
	/* �ҵĵ�һ�� C ���� */
	printf("��ִ�г��� %s ,��������Ϊ[%d], ���������[%s]\n\n", argv[0], argc, argv[1]);

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


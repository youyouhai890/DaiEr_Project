//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//
//
//
//
//
////Ҳ������typedef����������
//typedef struct
//{
//	int a;
//	char b;
//	double c;
//} JieGouTi;
//
//
//
//union GongYongTi
//{
//	int i;
//	//float f;
//	char  str[20];
//};
//
//
//int main()
//{
//	//union GongYongTi* gyt = nullptr;
//	GongYongTi * gyt=nullptr;
//
//	//gyt->i = 111;
//	//gyt->f = 22.2;
//	//strcpy(gyt->str, "ccccccccccc");
//	//int k = 12345;
//	char* k = "abcde";
//	gyt = (GongYongTi *)(k);
//
//	//printf("Memory size occupied by gyt : %d\n", sizeof(gyt));
//	printf("�������Ա��ֵΪ : %d\n", gyt->i);
//	printf("�������Ա��ֵΪ : %s\n", gyt->str);
//
//	//delete gyt;
//	return 0;
//}
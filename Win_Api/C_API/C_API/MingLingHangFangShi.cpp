//
//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//
//
//#define DangQianWenJian	//���嵱ǰ�ļ���
//
//#define SIZE_BUF 256
//
//int main(int GeShu , char *CanShuNeiRong[]) {
//
//#pragma region �ļ�����(�ƶ�,������,����)
//
//
//
//	////printf("��������-----%d\n", GeShu);
//	////printf("��һ��������ֵΪ-----%s\n", CanShuNeiRong[0]);
//	////printf("�ڶ���������ֵΪ-----%s\n", CanShuNeiRong[1]);
//	////printf("������������ֵΪ-----%s\n", CanShuNeiRong[2]);
//	//
//	////lstrcmp�Ƚ������ַ������˱Ƚϲ����ִ�Сд������һ���ַ����ȵڶ����ַ���С�򷵻�ֵΪ����
//	////����һ���ַ����ȵڶ����ַ������򷵻�ֵΪ�����������ַ�������򷵻�ֵΪ0��
//	//if (0 == lstrcmp("-sc",CanShuNeiRong[1]) && GeShu==3)	//�����з�ʽɾ���ļ�
//	//{
//	//	if (!DeleteFile(CanShuNeiRong[2]))	//API����DeleteFileΪɾ���ļ�
//	//	{
//	//		printf("ɾ���ļ���������:%x\n", GetLastError());
//
//	//	}
//	//	else
//	//	{
//	//		printf("ɾ���ļ��ɹ�...\n");
//
//	//	}
//	//}
//	//else if(0==lstrcmp("-kb",CanShuNeiRong[1]) && GeShu==4 )	//�����з�ʽ�����ļ�
//	//{
//	//	if (!CopyFile(CanShuNeiRong[2],CanShuNeiRong[3],TRUE))  //API����DeleteFileΪ�����ļ�,TRUEΪ������
//	//	{
//	//			if (GetLastError() == 0x50)	//������
//	//			{
//	//					printf("%s�ļ��Ѿ�����,�Ƿ񸲸�???...y/n \n",CanShuNeiRong[3]);
//	//					if ('y' == getchar())	//�Ӽ��̽����ַ�
//	//					{
//	//						if (!CopyFile(CanShuNeiRong[2],CanShuNeiRong[3],FALSE))//API����DeleteFileΪ�����ļ�,FALSE����
//	//						{
//	//							printf("�����ļ�ʱ��������...%d\n",GetLastError());
//	//						}
//	//						else
//	//						{
//	//							printf("���Ƴɹ�...\n");
//	//						}
//
//	//					}
//	//					else
//	//					{
//	//						printf("�������...\n");
//	//						return 0;
//	//					}
//	//			}
//	//			else
//	//			{
//	//					return 0;
//	//			}
//	//	}
//	//}
//	////lstrcmp�Ƚ������ַ������˱Ƚϲ����ִ�Сд������һ���ַ����ȵڶ����ַ���С�򷵻�ֵΪ����
//	////����һ���ַ����ȵڶ����ַ������򷵻�ֵΪ�����������ַ�������򷵻�ֵΪ0��
//	//else if(0==lstrcmp("-gm",CanShuNeiRong[1]) && GeShu==4 )
//	//{
//	//	if (!MoveFile(CanShuNeiRong[2],CanShuNeiRong[3]))	//�޸��ļ���
//	//	{
//	//		printf("�������ļ�ʱ��������...%d\n",GetLastError());
//	//	}
//	//	else
//	//	{
//	//		printf("�޸��ļ����Ƴɹ�...%d\n");
//
//	//	}
//	//		
//	//}
//	//else
//	//{
//	//		printf("��������...\n");
//	//}
//
//#pragma endregion
//
//#pragma region C���Է�ʽ��д�ļ�
//
//	//FILE *WenJianLiuDuQu, *WenJianLiuXieRu;
//	//char HuanCun[SIZE_BUF];
//	//size_t DuQuLiuNeiRongGeShu, XieRuLiuNeiRongGeShu;	//size_t���Ͷ�Ӧ �޷���int����
//
//	//if (GeShu !=3)
//	//{
//	//	printf("��������������...\n");
//	//}
//	////�����з�ʽ�������ļ�Ϊ,��ǰĿ¼����ļ�
//	//WenJianLiuDuQu = fopen(CanShuNeiRong[1], "rb");	//2���Ʒ�ʽ��ȡ,ÿ�ζ�ȡһ���ֽ�
//	//if (WenJianLiuDuQu==NULL)
//	//{
//	//	perror(CanShuNeiRong[1]);	//������
//	//	return 2;
//	//}
//
//	//WenJianLiuXieRu = fopen(CanShuNeiRong[2], "wb");//2���Ʒ�ʽд��,ÿ��д��һ���ֽ�
//	//if (WenJianLiuXieRu == NULL)
//	//{
//	//	perror(CanShuNeiRong[2]);	//������
//	//	return 3;
//	//}
//	////ÿ��ѭ����ȡ256���ֽ�, DuQuLiuNeiRongGeShuΪʵ�ʶ����ĸ���
//	//while ((DuQuLiuNeiRongGeShu = fread(HuanCun,1, SIZE_BUF, WenJianLiuDuQu))>0)	//DuQuLiuNeiRongGeShu==0ʱ��ȡ����
//	//{
//	//	//�ѻ����������д���ļ�, XieRuLiuNeiRongGeShuΪʵ��д��ĸ���
//	//	XieRuLiuNeiRongGeShu = fwrite(HuanCun, 1, DuQuLiuNeiRongGeShu, WenJianLiuXieRu);
//	//	if (XieRuLiuNeiRongGeShu != DuQuLiuNeiRongGeShu)
//	//	{
//	//		perror("�ֽ�������");	//������
//	//		return 4;
//	//	}
//
//	//}
//
//	//fclose(WenJianLiuDuQu);
//	//fclose(WenJianLiuXieRu);
//#pragma endregion
//
//#pragma region WINAPI��ʽ��д�ļ�
//	
//		//HANDLE DuQuLiuDuiXiang, XieRuLiuDuiXiang;	//������
//		//DWORD DuQu_ShiJiDaXiao, XieRu_ShiJiDaXiao;
//		//CHAR	buffer[SIZE_BUF];
//
//		//if (GeShu !=3)
//		//{
//		//	printf("��������������...\n");
//		//}
//
//		//DuQuLiuDuiXiang  = CreateFile(		//Ӧ���ǻ�ȡ��ȡ������
//		//	CanShuNeiRong[1],		//�ļ���(Ĭ��Ϊ��ǰ�ļ�) 
//		//	GENERIC_READ,			//��ȡģʽ , Ӧ�û���д��ģʽ
//		//	FILE_SHARE_READ,		//����ģʽ(Ӧ����ָ��ǰ�ļ�)
//		//	NULL,					//NULL��ʾĬ�ϵİ�ȫ����
//		//	OPEN_EXISTING,			//���Ѿ����ڵ��ļ�,Ӧ�û��д����ļ�
//		//	FILE_ATTRIBUTE_NORMAL,	//�ļ�����Ϊ����
//		//	NULL					//ģ��(Ӧ�ÿ���ָ��һ��ģ��)
//		//);
//
//		//if (DuQuLiuDuiXiang == INVALID_HANDLE_VALUE)
//		//{
//		//	printf("��ȡ������ʱ��������:%x\n", GetLastError());
//		//}
//
//
//		//XieRuLiuDuiXiang = CreateFile(		//Ӧ���ǻ�ȡд��������
//		//	CanShuNeiRong[2],		//�ļ���(Ĭ��Ϊ��ǰ�ļ�) 
//		//	GENERIC_WRITE,			//��ȡģʽ , Ӧ�û���д��ģʽ
//		//	0,					//����ģʽ(Ӧ����ָ��ǰ�ļ�)
//		//	NULL,					//NULL��ʾĬ�ϵİ�ȫ����
//		//	CREATE_ALWAYS,			//���Ǵ����ļ�
//		//	FILE_ATTRIBUTE_NORMAL,	//�ļ�����Ϊ����
//		//	NULL					//ģ��(Ӧ�ÿ���ָ��һ��ģ��)
//		//);
//		//if (XieRuLiuDuiXiang == INVALID_HANDLE_VALUE)
//		//{
//		//	printf("д��������ʱ��������:%x\n", GetLastError());
//		//}
//
//		////ÿ��ѭ������256�ֽ�,���ReadFile()�������صĽ��Ϊ0��ʾ�Ѿ���ȡ���,����0��ʾ��ȡ����
//		//	while (
//		//				ReadFile(		//��ȡ�ļ�����
//		//						DuQuLiuDuiXiang,	//ָ����ȡ���ļ�����(���)
//		//						buffer,	//��������
//		//						SIZE_BUF,		//�����С
//		//						&DuQu_ShiJiDaXiao,	//ʵ�ʶ�ȡ�Ĵ�С����
//		//						NULL
//		//					)  && DuQu_ShiJiDaXiao >0
//		//		)
//		//		{
//		//				WriteFile(
//		//						XieRuLiuDuiXiang,	//ָ��д�����ļ�����
//		//						buffer,	//��������
//		//						DuQu_ShiJiDaXiao,	//�����ǿ����ļ���������Ҫ����ȡ���ֽ�����һ��
//		//						&XieRu_ShiJiDaXiao,	//ʵ��д��ĵĴ�С����
//		//						NULL
//		//					);
//		//					if (XieRu_ShiJiDaXiao != DuQu_ShiJiDaXiao)
//		//					{
//		//						printf("д��Ͷ�ȡ��ʵ�ʴ�С������\n");
//		//						return 4;
//		//					}
//		//		}
//
//		////�ͷ�������
//		//CloseHandle(DuQuLiuDuiXiang);
//		//CloseHandle(XieRuLiuDuiXiang);
//
//
//#pragma endregion
//
//#pragma region WINAPI�����ļ�(�Ƽ�)
//
//		if (!CopyFile(CanShuNeiRong[1], CanShuNeiRong[2],FALSE))	//�����ļ�����,FALSEΪ���Ǹ����ļ�(��ͬ��ʱ)
//		{
//			printf("�����ļ�ʱ��������:%x\n", GetLastError());
//			return 6;
//		}
//
//#pragma endregion
//
//
//	return 0;
//}
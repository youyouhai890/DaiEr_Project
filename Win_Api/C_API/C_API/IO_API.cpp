//#include <stdio.h>
//#include <stdlib.h>
//
//#include <Windows.h>
//
//void tprint( PTCHAR pstr) {
//	int i = 0;
//	while (pstr[i] != '\0')
//	{
//		printf("ϵͳĿ¼��%d-----%c\n", i, pstr[i]);
//		//printf("%c", pstr[i]);
//		i++;
//	}
//	printf("\n");
//
//}
//
//int main(int argc, char* argv[]) {
//
//
//
//
//	WCHAR path[MAX_PATH] = {0};	//MAX_PATH�⺯��������ñ���
//	//��ȡϵͳĿ¼
//	GetSystemDirectory(path, MAX_PATH);
//
//	//printf("ϵͳĿ¼��-----%s\n", path);
//	tprint( path);
//
//	HANDLE JuBing;
//	DWORD ShiJiXieRuChangDu;
//	JuBing = CreateFile(
//						L"ϵͳĿ¼д��.txt",
//						GENERIC_WRITE,			//д��
//						0,						//����ģʽ
//						NULL,					//��ȫ����
//						CREATE_ALWAYS,			//���Ǵ����ļ�
//						FILE_ATTRIBUTE_NORMAL,		//��������
//						NULL						
//					);
//
//	if (JuBing != INVALID_HANDLE_VALUE)	//JuBing��������Ч���ʱ
//	{
//		if (      !WriteFile(
//					JuBing,					//�ļ�����
//					path,					//Ӧ����д�������
//					50,			//���ݵĳ���
//					&ShiJiXieRuChangDu,		//ʵ��д��ĳ���
//					NULL)
//			)
//		{
//			return GetLastError();//���ش�����Ϣ
//		}
//	}
//	CloseHandle(JuBing);	//�رվ��
//
//	printf("-----%d", ShiJiXieRuChangDu);
//	
//	return 0;
//}
//
//
//
//

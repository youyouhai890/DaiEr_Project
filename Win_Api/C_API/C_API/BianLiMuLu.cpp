//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//
//
//DWORD BianLiMuLu(LPTSTR ml) {
//	
//	WIN32_FIND_DATA	CunChuMuLuHuoWenJian;	//�ṹ���������ڴ洢Ŀ¼
//	HANDLE JuBing;	//������(����)
//	TCHAR MuLu[MAX_PATH];
//		
//		lstrcpy(MuLu, ml);	//�����ַ���
//		lstrcat(MuLu, TEXT("\\*"));	//׷���ַ���,�൱��D:\\MyWorkspase\\*
//		printf("����·��-----------%s\n", MuLu);
//
//				//����������Ŀ¼���ļ�,����洢���ṹ��
//		JuBing = FindFirstFile(MuLu, &CunChuMuLuHuoWenJian);
//
//		if (JuBing == INVALID_HANDLE_VALUE) //�����������
//		{
//			printf("����-----------%d\n", GetLastError());
//			return 1;
//		}
//		else
//		{
//			do
//			{
//				if (
//					lstrcmp(CunChuMuLuHuoWenJian.cFileName,TEXT("."))==0	//�Ƚ��ַ���
//					|| lstrcmp(CunChuMuLuHuoWenJian.cFileName, TEXT(".."))==0
//					)
//				{
//					continue;
//				}
//
//				//���Ŀ¼���ļ���
//				printf("%s--------------------", CunChuMuLuHuoWenJian.cFileName);
//
//				if (CunChuMuLuHuoWenJian.dwFileAttributes & FILE_ATTRIBUTE_ENCRYPTED)
//				{
//					printf("<�����ļ�>\t");
//				}
//				if (CunChuMuLuHuoWenJian.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN)
//				{
//					printf("<�����ļ�>\t");
//				}
//				if (CunChuMuLuHuoWenJian.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
//				{
//					printf("<��ǰΪĿ¼>\t");
//				}
//				printf("\n");
//
//			} while (FindNextFile(JuBing, &CunChuMuLuHuoWenJian)); //��������Ŀ¼���ļ�(Ӧ�����ƶ�ָ��)
//		}
//		return 0;
//}
//
//int main() {
//
//	BianLiMuLu(TEXT("D:\\MyWorkspase"));
//	return 0;
//}
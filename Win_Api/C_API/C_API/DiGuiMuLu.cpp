//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//
//DWORD MuLuShuLiang = 0;
//
//DWORD ListAllFileInDirectrory(LPTSTR ShangYiGeLuJing) {
//
//	WIN32_FIND_DATA ZiMuLu_OR_WenJian;	//���ڴ洢Ŀ¼���ļ��Ľṹ������
//	HANDLE DuiXiang;			//Ӧ������Ϊ������Ŀ¼���ļ��Ķ���
//	TCHAR WanZhengLuJing[MAX_PATH];
//	TCHAR HuanCun[MAX_PATH];
//
//	lstrcpy(WanZhengLuJing, ShangYiGeLuJing);		//�����ַ���
//	lstrcat(WanZhengLuJing, TEXT("\\*"));	//�ַ���׷��
//
//	DuiXiang = FindFirstFile(WanZhengLuJing, &ZiMuLu_OR_WenJian);	//������һ��Ŀ¼
//	if (DuiXiang == INVALID_HANDLE_VALUE)
//	{
//		printf("���� : %d\n", GetLastError());
//		return 1;
//	}
//	else
//	{
//		do
//		{
//			//�����õ�Ŀ¼���˵�, (.)Ϊ��ǰĿ¼ , (..)Ϊ��һ��Ŀ¼
//	    	if (
//				lstrcmp(ZiMuLu_OR_WenJian.cFileName, TEXT(".")) == 0 ||
//				lstrcmp(ZiMuLu_OR_WenJian.cFileName,TEXT(".."))==0
//			)
//			{
//				continue;	//������ǰѭ��
//			}
//
//
//			//������ZiMuLu_OR_WenJian.cFileName��ֵ��ʽ��Ϊ�ַ���(%s\\%s)�����������HuanCunָ����ڴ浥Ԫ��
//			wsprintf(HuanCun, "%s\\%s", ShangYiGeLuJing, ZiMuLu_OR_WenJian.cFileName);
//			MuLuShuLiang++;
//			printf("\n%d\t%s", MuLuShuLiang, HuanCun);
//
//			if (ZiMuLu_OR_WenJian.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)	//����Ƿ�ΪĿ¼
//			{
//				printf("<DIR>");	//Ŀ¼��־
//				ListAllFileInDirectrory(HuanCun);	//�����Ŀ¼�͵��õݹ麯��
//			}
//		} while (FindNextFile(DuiXiang,&ZiMuLu_OR_WenJian));	//������һ��Ŀ¼���ļ�
//	}
//
//	return 0;
//}
//
//
//
//
//int main() {
//
//	ListAllFileInDirectrory(TEXT("D:\\DownLoad\\BaiDuDown"));
//
//	return 0;
//}
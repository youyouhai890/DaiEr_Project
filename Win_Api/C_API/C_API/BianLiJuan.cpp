//
//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//
//
//#define size 1024
//int main() {
//
//	////char����
//	//CHAR HuoQuPanFuMing[size];
//	////CHAR��ָ������*CHAR
//	//PCHAR YiDongZhiZhen = NULL;
//	////�ѷ������ڴ��������������
//	//ZeroMemory(HuoQuPanFuMing, size);
//
//	////��ȡ�����̷���,size-1�����Ҫ����'\0'(��)���ַ�
//	//GetLogicalDriveStrings(size - 1, HuoQuPanFuMing);
//	////printf("%s\n", HuoQuPanFuMing);	//���ڻ�ȡ���ַ����м��Կ��ַ�('\0')�ָ�,����printfֻ�ܻ�ȡ��һ���̷�
//
//	////�ƶ�ָ��(�ƶ�ÿ���ַ���),�������Ϊ�ƶ��ַ�������
//	////�����ַ��������п�('\0')�ַ�,���Զ�ȡ����('\0')�ַ�ʱ�᷵�ص�ǰָ��
//	//YiDongZhiZhen = (PCHAR)HuoQuPanFuMing;	//��ȡ��һ���ַ�����ָ���ַ
//	//do
//	//{
//	//	printf("%s  ", YiDongZhiZhen); //���ַ���ָ����洢��ȡ��������,������('\0')�ַ�ʱ�᷵��
//	//	YiDongZhiZhen += (lstrlen(YiDongZhiZhen) + 1); //�ƶ�����һ���ַ����Ŀ�ͷ,������('\0')�ַ�ʱ�᷵��
//	//} while (*YiDongZhiZhen !='\x00');	//����\x00��16����,Ҳ������'\0'
//
//	//printf("\n\n");
//	////////////////////////////////////////////////////////////////////////////
//	//TCHAR HuoQuSheBeiMing[size];
//	//HANDLE hand;	//������
//	//BOOL bol=true;
//
//	//hand = FindFirstVolume(HuoQuSheBeiMing, size);	//��ȡ��һ���̷����豸����,����һ�����(����)
//
//	//if (hand == INVALID_HANDLE_VALUE)
//	//{
//	//	printf(TEXT("û���ҵ����(����)....."));
//	//}
//	//printf("�豸����Ϊ:------%s\n", HuoQuSheBeiMing);
//
//	////�ƶ�����һ���̷�(�ƶ�ָ��)
//	//while (FindNextVolume(hand, HuoQuSheBeiMing, size))	
//	//{
//	//	printf("�豸����Ϊ:------%s\n", HuoQuSheBeiMing);
//	//}
//
//	//bol = FindVolumeClose(hand);	//�رվ��,����1ʱtrue
//	//printf("BOOL��ֵΪ:------%d\n", (int)bol);
//	//return bol;		//����0ʱ����
//
//	//////////////////////////////////////////
//	char aa[] = "aaa\0bbb\0ccc\0";
//
//	char *bb = NULL;
//	//��ȡ��һ���ַ�����ָ���ַ
//	bb = (char*)aa;
//	//bb = &aa;
//	printf("----%p\n", bb);
//	printf("----%s\n", bb);
//
//	bb += lstrlen(aa) + 1;	//�ƶ�ָ�뵽��һ���ַ�����ͷ
//	printf("----%p\n", bb);
//	printf("----%s\n", bb);
//
//	bb += lstrlen(aa) + 1;
//	printf("----%p\n", bb);
//	printf("----%s\n", bb);
//
//	return 0;		//����0ʱ����
//
//}
//

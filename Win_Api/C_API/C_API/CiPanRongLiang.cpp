//
//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//
//
//int main() {
//
//	BOOL BOL;
//
//	//��
//	DWORD CuDeZongShuLiang;		//ÿ��Ӳ�̰����˶���� ,ÿ���ذ����˶������ ,ÿ�����������˶���ֽ�
//	DWORD KongXianDeCu;
//	//����
//	DWORD ShanQu;		//ÿ���������������
//	DWORD ZiJie;		//ÿ�������������ֽ���
//
//	BOL = GetDiskFreeSpace(
//
//		TEXT("C:"),		//�̷�
//		&ShanQu,		//�洢ÿ���ذ���������
//		&ZiJie,			//�洢ÿ�������������ֽ�
//		&KongXianDeCu,	//�洢���õĴ�����
//		&CuDeZongShuLiang	//�洢�ص�������
//	);
//	if (BOL)
//	{
//		printf("\n�ص�������\t-----%d", CuDeZongShuLiang);
//		printf("\n���еĴ�����\t-----%d", KongXianDeCu);
//		printf("\nÿ���ذ���������\t-----%d", ShanQu);
//		printf("\nÿ�������������ֽ�\t-----%d\n", ZiJie);
//		printf("\n����������\t-----%I64d", (DWORD64)CuDeZongShuLiang * (DWORD64)ShanQu * (DWORD64)ZiJie);
//		printf("\n���̿�������\t-----%I64d\n", (DWORD64)KongXianDeCu * (DWORD64)ShanQu * (DWORD64)ZiJie);
//
//		printf("\n�Ѿ��õ�������\t-----%I64d\n", (DWORD64)CuDeZongShuLiang * (DWORD64)ShanQu * (DWORD64)ZiJie
//		);
//    }
//
//	printf("\n===========================\n");
//
//	DWORD64 ZongLongLiang, KongXianRongLiang, KeYongDeKongXianRongLiang;
//
//	BOL	= GetDiskFreeSpaceEx(
//		TEXT("C:"),		//�̷�
//		(PULARGE_INTEGER)&KongXianRongLiang,		//���̿��е�����,��Щ����Ԥ����windows��
//		(PULARGE_INTEGER)&ZongLongLiang,	//����������
//		(PULARGE_INTEGER)&KeYongDeKongXianRongLiang	//���õĴ��̿�������
//	);
//
//	if (BOL)
//	{
//		printf("\n���̿��е�����\t-----%I64d", KongXianRongLiang);
//		printf("\n����������\t-----%I64d", ZongLongLiang);
//		printf("\n���õĴ��̿�������\t-----%I64d\n", KeYongDeKongXianRongLiang);
//	}
//	return 0;
//}
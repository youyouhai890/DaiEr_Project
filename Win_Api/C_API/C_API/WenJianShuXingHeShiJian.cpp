//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//
//
////ʱ��ת������,Դʱ��(����ʱ��) ->����ʱ��(����ʱ��) -> ϵͳʱ��
//DWORD XianShiWenJianShiJian(PFILETIME YuanShiJian) {
//	FILETIME BenDiShiJian;	
//	SYSTEMTIME XiTongShiJian;
//	FileTimeToLocalFileTime(YuanShiJian, &BenDiShiJian);	//��Դʱ��(����ʱ��)ת��Ϊ����ʱ��(����ʱ��)
//	FileTimeToSystemTime(&BenDiShiJian, &XiTongShiJian);	//�ѱ���ʱ��(����ʱ��)ת��Ϊϵͳʱ��
//
//	printf("%d��%#02d��%#2d��, %#2d: %#2d: %#2d:\n"
//		, XiTongShiJian.wYear
//		, XiTongShiJian.wMonth
//		, XiTongShiJian.wDay
//		, XiTongShiJian.wHour
//		, XiTongShiJian.wMinute
//		, XiTongShiJian.wSecond);
//
//	return 0;
//
//}
//
////�ϲ�λ��,��ͨ��DWORD����ֻ�ܱ���4G,����������DWORD���ͽ������
//DWORD XianShiWenJianDaXiao(DWORD GaoWei , DWORD DiWei) {
//	ULONGLONG HeBing;	//����64λ�޷��ű���,U��ʾ�޷���
//
//	HeBing = GaoWei;	//��32λ�ı���(GaoWei)�ŵ�64λ����(HeBing)�ĵ�32λ��
//	HeBing <<= 32;	//��64λ�ı�������32λ,�ŵ���32λ��
//	HeBing += DiWei;	//��32λ�ı���(DiWei)׷�ӵ�64λ����((HeBing))�ĵ�32λ��
//	printf("�ļ���С: \t %I64u �ֽ�\n",HeBing);
//
//	return 0;
//}
//
////��ȡ�ļ�����
//DWORD XianShiWenJianShuXing(DWORD dwAttribute) {
//
//	printf("��ʾ�ļ�����: \t");
//	if (dwAttribute & FILE_ATTRIBUTE_ARCHIVE)		//�鵵����
//	{
//		printf("<�鵵����> ");
//	}
//	if (dwAttribute & FILE_ATTRIBUTE_COMPRESSED)		//ѹ��
//	{
//		printf("<ѹ��> ");
//	}	
//	if (dwAttribute & FILE_ATTRIBUTE_READONLY)		//ֻ��
//	{
//		printf("<ֻ��> ");
//	}	
//	if (dwAttribute & FILE_ATTRIBUTE_DIRECTORY)		//Ŀ¼
//	{
//		printf("<Ŀ¼> ");
//	}
//	if (dwAttribute & FILE_ATTRIBUTE_ENCRYPTED)		//����
//	{
//		printf("<����> ");
//	}	
//	if (dwAttribute & FILE_ATTRIBUTE_HIDDEN)		//����
//	{
//		printf("<����> ");
//	}	
//	if (dwAttribute & FILE_ATTRIBUTE_NORMAL)		//NORMAL
//	{
//		printf("<NORMAL> ");
//	}	
//	if (dwAttribute & FILE_ATTRIBUTE_OFFLINE)		//OFFLINE
//	{
//		printf("<OFFLINE> ");
//	}	
//	if (dwAttribute & FILE_ATTRIBUTE_SYSTEM)		//ϵͳ
//	{
//		printf("<ϵͳ> ");
//	}
//
//	return 0;
//}
//
//DWORD XianShiShuXing(LPTSTR LuJing) {
//
//	WIN32_FILE_ATTRIBUTE_DATA	ShuXing;	//���ڻ�ȡ�ļ����ԵĽṹ��
//	printf("�ļ�: %s\n", LuJing);
//
//	//���ļ������Դ洢��WIN32_FILE_ATTRIBUTE_DATA�ṹ�������
//	if (!GetFileAttributesEx(LuJing,GetFileExInfoStandard, &ShuXing))
//	{
//		printf("��ȡ�ļ�����ʧ��: %s\n", GetLastError());
//		return 1;
//	}
//	printf("����ʱ��: \t");
//	XianShiWenJianShiJian(&(ShuXing.ftCreationTime));
//	printf("����ʱ��: \t");
//	XianShiWenJianShiJian(&(ShuXing.ftLastAccessTime));	
//	printf("�޸�ʱ��: \t");
//	XianShiWenJianShiJian(&(ShuXing.ftLastWriteTime));
//
//	//����Ϊ�ߵ�λ,��ͨ��DWORD����ֻ�ܱ���4G,����������DWORD���ͽ������
//	XianShiWenJianDaXiao(ShuXing.nFileSizeHigh, ShuXing.nFileSizeLow);	
//	//��ʾ�ļ�����
//	XianShiWenJianShuXing(ShuXing.dwFileAttributes);	
//
//	return 2;
//}
//
//
//DWORD SheZhiWenJianShuXing(LPTSTR WenJianLuJing) {
//
//	//��ȡ�ļ���������
//	DWORD ShuXing = GetFileAttributes(WenJianLuJing);
//	//��λ��(|)�����������ļ�����
//	ShuXing |= FILE_ATTRIBUTE_READONLY;
//	ShuXing |= FILE_ATTRIBUTE_HIDDEN;
//	if (SetFileAttributes(WenJianLuJing, ShuXing))	//�����ļ�����
//	{
//		printf("�ļ� %s �������Ժ�ֻ���������óɹ�\n", WenJianLuJing);
//	}
//	else
//	{
//		printf("��������ʧ�� %d\n",GetLastError());
//	}
//	return 0;
//}
//
//int main() {
//
//	//XianShiShuXing(TEXT("D:\\YouXi\\Warcraft 3.zip"));
//
//
//	SheZhiWenJianShuXing(TEXT("D:\\YouXi\\Warcraft 3.zip"));
//	return 0;
//}

//
//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//
//BOOL bol = TRUE;
//
//BOOL HuoQuPanFuShuXing(LPSTR PanFu) {
//
//
//
//	UINT LeiXingBiaoShi;
//	LeiXingBiaoShi = GetDriveType(PanFu);
//
//	//switch (LeiXingBiaoShi)
//	//{
//	//	 
//	//		case	DRIVE_UNKNOWN:										//δ֪��(����ʶ���)			 0	
//	//				printf("δ֪��(����ʶ���)-----��ʾ��Ϊ%d\n", LeiXingBiaoShi);
//	//				break;
//	//		case	DRIVE_NO_ROOT_DIR:							//�Ǹ�Ŀ¼(����ʱ��)			 1	
//	//				printf("�Ǹ�Ŀ¼(����ʱ��)-----��ʾ��Ϊ%d\n", LeiXingBiaoShi);
//	//				break;
//	//		case	DRIVE_REMOVABLE:								//���ƶ����豸				     2	
//	//				printf("���ƶ����豸-----��ʾ��Ϊ%d\n", LeiXingBiaoShi);
//	//				break;
//	//		case	DRIVE_FIXED:									//�̶�������(Ӳ�̵�..)			 3	
//	//				printf("�̶�������(Ӳ�̵�..)-----��ʾ��Ϊ%d\n", LeiXingBiaoShi);
//	//				break;
//	//		case	DRIVE_REMOTE:								//Զ��������(�繲��Ӳ�̵�)		 4	
//	//				printf("Զ��������(�繲��Ӳ�̵�)-----��ʾ��Ϊ%d\n", LeiXingBiaoShi);
//	//				break;
//	//		case	DRIVE_CDROM:								//����						     5	
//	//				printf("����	-----��ʾ��Ϊ%d\n", LeiXingBiaoShi);
//	//				break;
//	//		case	DRIVE_RAMDISK:								//U�̵�...					     6
//	//				printf("U�̵�...-----��ʾ��Ϊ%d\n", LeiXingBiaoShi);
//	//				break;
//
//	//		default:
//	//				printf("�]���ҵ����ϵı�ʾ���\n");
//	//				break;
//	//}
//
//
//	CHAR HuoQuPanFuMing[MAX_PATH];
//	DWORD YingPanXuLieHao;
//	DWORD ZuiDaWenJianMingChangDu;
//	DWORD HuoQuShuXing;
//	CHAR PanFuGeShi[MAX_PATH];
//
//
//	if (!GetVolumeInformation(
//		PanFu,				//��Ҫ��ȡ���Ե�������
//		HuoQuPanFuMing,		//�洢�����������ַ�������
//		MAX_PATH,			//�洢�Ĵ�С
//		&YingPanXuLieHao,	//�洢Ӳ�����к�(Ӳ��Ψһ��ʶ)
//		&ZuiDaWenJianMingChangDu,	//���Դ洢������ļ�������
//		&HuoQuShuXing,				//��ȡ����(��ȡ������������)
//		PanFuGeShi,				//��ȡ�̷���ʽ(NTFS��)
//		MAX_PATH				//�洢�Ĵ�С
//	))
//	{
//		return FALSE;
//
//	}
//
//	if (0 !=lstrlen(HuoQuPanFuMing))
//	{
//		printf("\n------��ȡ�����̷�����Ϊ-----%s\n", HuoQuPanFuMing);
//	}
//
//	printf("������������к�-----%u\n", YingPanXuLieHao);	//%uΪ10���Ƹ�ʽ���
//	printf("�������ļ�������-----%u\n", ZuiDaWenJianMingChangDu);
//	printf("����̷���ʽ-----%s\n", PanFuGeShi);
//
//	if (HuoQuShuXing & FILE_VOLUME_QUOTAS)		//λ���� , �ж��Ƿ�֧�����
//	{
//		printf("�ж��Ƿ�֧�����...\n");
//
//	}
//	if (HuoQuShuXing & FILE_SUPPORTS_ENCRYPTION)		//λ���� , �ж��Ƿ�֧�ּ���
//	{
//		printf("�ж��Ƿ�֧�ּ���.....\n");
//	}
//
//	return bol;
//}
//
//
//
//int main() {
//
//	//if (!HuoQuPanFuShuXing(TEXT("c:\\")))
//	//{
//	//	printf("��ȡ��������Ϣ����...\n");
//
//	//}	
//	HuoQuPanFuShuXing(TEXT("d:\\"));
//	return 0;
//}
//

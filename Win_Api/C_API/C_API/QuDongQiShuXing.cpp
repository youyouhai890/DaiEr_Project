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
//	//		case	DRIVE_UNKNOWN:										//未知的(不能识别的)			 0	
//	//				printf("未知的(不能识别的)-----表示符为%d\n", LeiXingBiaoShi);
//	//				break;
//	//		case	DRIVE_NO_ROOT_DIR:							//非根目录(出错时用)			 1	
//	//				printf("非根目录(出错时用)-----表示符为%d\n", LeiXingBiaoShi);
//	//				break;
//	//		case	DRIVE_REMOVABLE:								//可移动的设备				     2	
//	//				printf("可移动的设备-----表示符为%d\n", LeiXingBiaoShi);
//	//				break;
//	//		case	DRIVE_FIXED:									//固定驱动器(硬盘等..)			 3	
//	//				printf("固定驱动器(硬盘等..)-----表示符为%d\n", LeiXingBiaoShi);
//	//				break;
//	//		case	DRIVE_REMOTE:								//远程驱动器(如共享硬盘等)		 4	
//	//				printf("远程驱动器(如共享硬盘等)-----表示符为%d\n", LeiXingBiaoShi);
//	//				break;
//	//		case	DRIVE_CDROM:								//光驱						     5	
//	//				printf("光驱	-----表示符为%d\n", LeiXingBiaoShi);
//	//				break;
//	//		case	DRIVE_RAMDISK:								//U盘等...					     6
//	//				printf("U盘等...-----表示符为%d\n", LeiXingBiaoShi);
//	//				break;
//
//	//		default:
//	//				printf("沒有找到符合的表示類型\n");
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
//		PanFu,				//需要获取属性的驱动器
//		HuoQuPanFuMing,		//存储驱动器名的字符串变量
//		MAX_PATH,			//存储的大小
//		&YingPanXuLieHao,	//存储硬盘序列号(硬盘唯一标识)
//		&ZuiDaWenJianMingChangDu,	//可以存储的最大文件名长度
//		&HuoQuShuXing,				//获取属性(获取驱动器的类型)
//		PanFuGeShi,				//获取盘符格式(NTFS等)
//		MAX_PATH				//存储的大小
//	))
//	{
//		return FALSE;
//
//	}
//
//	if (0 !=lstrlen(HuoQuPanFuMing))
//	{
//		printf("\n------获取到的盘符名称为-----%s\n", HuoQuPanFuMing);
//	}
//
//	printf("输出驱动器序列号-----%u\n", YingPanXuLieHao);	//%u为10进制格式输出
//	printf("输出最大文件名长度-----%u\n", ZuiDaWenJianMingChangDu);
//	printf("输出盘符格式-----%s\n", PanFuGeShi);
//
//	if (HuoQuShuXing & FILE_VOLUME_QUOTAS)		//位运算 , 判断是否支持配额
//	{
//		printf("判断是否支持配额...\n");
//
//	}
//	if (HuoQuShuXing & FILE_SUPPORTS_ENCRYPTION)		//位运算 , 判断是否支持加密
//	{
//		printf("判断是否支持加密.....\n");
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
//	//	printf("获取驱动器信息出错...\n");
//
//	//}	
//	HuoQuPanFuShuXing(TEXT("d:\\"));
//	return 0;
//}
//

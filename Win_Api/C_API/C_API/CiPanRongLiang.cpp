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
//	//簇
//	DWORD CuDeZongShuLiang;		//每个硬盘包含了多个簇 ,每个簇包含了多个扇区 ,每个扇区包含了多个字节
//	DWORD KongXianDeCu;
//	//扇区
//	DWORD ShanQu;		//每个簇里包含的扇区
//	DWORD ZiJie;		//每个扇区包含的字节数
//
//	BOL = GetDiskFreeSpace(
//
//		TEXT("C:"),		//盘符
//		&ShanQu,		//存储每个簇包含的扇区
//		&ZiJie,			//存储每个扇区包含的字节
//		&KongXianDeCu,	//存储可用的簇数量
//		&CuDeZongShuLiang	//存储簇的总数量
//	);
//	if (BOL)
//	{
//		printf("\n簇的总数量\t-----%d", CuDeZongShuLiang);
//		printf("\n空闲的簇数量\t-----%d", KongXianDeCu);
//		printf("\n每个簇包含的扇区\t-----%d", ShanQu);
//		printf("\n每个扇区包含的字节\t-----%d\n", ZiJie);
//		printf("\n磁盘总容量\t-----%I64d", (DWORD64)CuDeZongShuLiang * (DWORD64)ShanQu * (DWORD64)ZiJie);
//		printf("\n磁盘空闲容量\t-----%I64d\n", (DWORD64)KongXianDeCu * (DWORD64)ShanQu * (DWORD64)ZiJie);
//
//		printf("\n已经用掉的容量\t-----%I64d\n", (DWORD64)CuDeZongShuLiang * (DWORD64)ShanQu * (DWORD64)ZiJie
//		);
//    }
//
//	printf("\n===========================\n");
//
//	DWORD64 ZongLongLiang, KongXianRongLiang, KeYongDeKongXianRongLiang;
//
//	BOL	= GetDiskFreeSpaceEx(
//		TEXT("C:"),		//盘符
//		(PULARGE_INTEGER)&KongXianRongLiang,		//磁盘空闲的容量,有些容量预留给windows用
//		(PULARGE_INTEGER)&ZongLongLiang,	//磁盘总容量
//		(PULARGE_INTEGER)&KeYongDeKongXianRongLiang	//可用的磁盘空闲容量
//	);
//
//	if (BOL)
//	{
//		printf("\n磁盘空闲的容量\t-----%I64d", KongXianRongLiang);
//		printf("\n磁盘总容量\t-----%I64d", ZongLongLiang);
//		printf("\n可用的磁盘空闲容量\t-----%I64d\n", KeYongDeKongXianRongLiang);
//	}
//	return 0;
//}
#include <stdio.h>
#include <Windows.h>

//#pragma warning(disable: 4996)

void ShowVersionInfo() {

	OSVERSIONINFO ovex;	//���ڻ�ȡϵ��Ϣ�Ľṹ������
	TCHAR XiTongBanBen[1024];
	*XiTongBanBen = NULL;
	ovex.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

	if (!GetVersionEx(&ovex))
	{
		printf("������Ϣ %d\n", GetLastError());
		return;
	}

	if (ovex.dwMajorVersion==5)
	{
		if (ovex.dwMinorVersion==0)
		{
			lstrcat(XiTongBanBen, TEXT("Win2000"));	//׷���ַ���
		}
		else if (ovex.dwMinorVersion==1)
		{
			lstrcat(XiTongBanBen, TEXT("WinXP"));
		}
		else if (ovex.dwMinorVersion == 2)
		{
			lstrcat(XiTongBanBen, TEXT("Win Server 2003"));
		}
	}
	else if (ovex.dwMinorVersion == 6)
	{
		lstrcat(XiTongBanBen, TEXT("Win Vista"));
	}
	else
	{
		lstrcat(XiTongBanBen, TEXT("Win NT"));
	}

	printf("%s\n", XiTongBanBen);

	printf("Windows %d.%d Build %d ", ovex.dwMajorVersion,ovex.dwMinorVersion,ovex.dwBuildNumber);

	printf("%s\n", ovex.szCSDVersion);

}


void ShowSystemInfo() {

	SYSTEM_INFO si;
	GetSystemInfo(&si);
	printf("�ڴ��ҳ��С: 0x%.8X, �����ڴ���ʼ: 0x%.8X ,�����ڴ����: 0x%. 8X\n ",
		si.dwPageSize, si.lpMinimumApplicationAddress, si.lpMaximumApplicationAddress
	);
	printf("����������: %d\n", si.dwNumberOfProcessors);

	printf("����������");
	switch (si.dwProcessorType)
	{
	case	PROCESSOR_INTEL_386:
		printf("386\n");
		break;
	case PROCESSOR_INTEL_PENTIUM:
		printf("����\n");

	default:
		printf(si.dwProcessorType+"\n");
		break;
	}


	printf("�������ܹ�");
	switch (si.wProcessorArchitecture)
	{
	case	PROCESSOR_ARCHITECTURE_INTEL:
		printf("intel\n");
		break;
	default:
		printf(si.wProcessorArchitecture + "\n");
		break;
	}


}



int main() {
	ShowVersionInfo();
	printf("\n\n");
	ShowSystemInfo();
	printf("\n\n");
	return 0;
}

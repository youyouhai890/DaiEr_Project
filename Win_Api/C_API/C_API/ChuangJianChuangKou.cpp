//
//#include <stdio.h>
//#include <Windows.h>
//
//
//HINSTANCE hinst;//ʵ�����̫��Ҫ�ˣ�Ҫ��һ��ȫ�ֱ������䱣������
//HWND hwnd;
//
//LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); //��������
//
////HINSTANCE DangQian_Obj;	//����ȫ�־��(����)
//
//int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
//
//	WNDCLASSEX wcx;
//	MSG msg;	//�洢Ҫ�������Ϣ
//	BOOL bol;
//	hinst = hinstance;
//	//���崰����
//	//HWND hwnd;	//���崰�ھ��
//
//	wcx.lpszClassName = "����������";
//	wcx.cbSize = sizeof(wcx);	//���㴰����Ĵ�С
//	wcx.style = CS_HREDRAW | CS_VREDRAW;	//��ʽ: ���ڿ�߷����仯ʱ�ػ�
//	wcx.lpfnWndProc = MainWndProc;	//ָ�����ڹ���,ר�����ڴ�����Ϣ
//	wcx.cbClsExtra = 0;	     	//��ʹ�����ڴ�
//	wcx.cbWndExtra = 0;		    //��ʹ�ô����ڴ�(��������ʱʹ��)
//	wcx.hInstance = hinstance;	//ָ��������ľ��(����)Ϊ��ǰ���(����this)
//	wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);	//����ͼ������ΪĬ�ϼ���,�������ͼ����غ���LoadIcon()
//	wcx.hCursor = LoadCursor(NULL, IDC_ARROW);		//����ͷ����ΪĬ�ϵļ�ͷ,������ù����غ���LoadCursor()
//	wcx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//���ڱ�������Ϊ��ɫ(�û�ˢ��������),����API����GetStockObject()
//	wcx.lpszMenuName = NULL;		//û�в˵�
//	
//	//�趨�������Сͼ��
//	wcx.hIconSm = (HICON)LoadImage(		//����API����,LoadImage
//		hinstance,			//�������Ϊ��ǰ���(����,����this)
//		MAKEINTRESOURCE(5),	//5����Դ
//		IMAGE_ICON,			//5����Դ���ͼƬ
//		GetSystemMetrics(SM_CXSMICON),   //ͼ���
//		GetSystemMetrics(SM_CYSMICON),	//ͼ���
//		LR_DEFAULTCOLOR				//��ɫ����ΪĬ����ɫ
//	);
//
//	if (!RegisterClassEx(&wcx))	//ע�ᴰ����
//	{
//		//���ע��ʧ�ܷ���1
//		return 1;
//	}
//
//	//ʹ�ô����ഴ������,���ж��󴴽���֮�󶼻�õ�һ�����.
//	hwnd = CreateWindow(
//		"����������",
//		"����",
//		WS_OVERLAPPEDWINDOW,  //��ʽ����Ϊ������ʽ
//		CW_USEDEFAULT,	 //x����(Ĭ��)
//		CW_USEDEFAULT,	 //y����(Ĭ��)
//		CW_USEDEFAULT,	 //���(Ĭ��)
//		CW_USEDEFAULT,	 //�߶�(Ĭ��)
//		(HWND)NULL,		 //û���Ӵ���
//		(HMENU)NULL,	 //û�в˵�
//		hinstance,		 //��ǰ���(����,����this)
//		(LPVOID)NULL	 //��������ʱû������
//	);
//
//	if (!hwnd)
//	{
//		return 1;	//������ڴ���ʧ�ܷ���1
//	}
//	
//	ShowWindow(hwnd, nCmdShow);	//��ʾ����(�����п��ܲ���ʾ,��ô����Ҫ���������)
//	UpdateWindow(hwnd);	//������ʾ����
//
//	while ((bol = GetMessage(&msg,(HWND)NULL,0,0)) != 0) //GetMessage����Ϊ����Ϣ�����ﲻͣ�Ļ�ȡ��Ϣ�洢��msg
//	{
//	//	printf("bol--------&d\n", bol);
//		TranslateMessage(&msg);		//������Ϣ
//		DispatchMessage(&msg);	//ת����Ϣ�����ڹ��̺���(������Ϣ)
//	}
//
//	return msg.wParam;
//
//}
//
//
////���ڹ��̺���,���ڴ�����Ϣ(�ص�����)
//LRESULT  CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//
//	//uMsgΪ���ڹ��̺���Ҫ�������Ϣ
//	switch (uMsg)
//	{
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	case WM_LBUTTONDOWN:
//		MessageBox(hwnd, "Hello ���ڣ�", "���", MB_OK);
//		return 0;
//	default:
//		return DefWindowProc(hwnd, uMsg, wParam, lParam);
//	}
//
//
//}
//

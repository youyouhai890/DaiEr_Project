//
//#include <stdio.h>
//#include <Windows.h>
//
//
//HINSTANCE hinst;//实例句柄太重要了，要用一个全局变量将其保存起来
//HWND hwnd;
//
//LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); //声明函数
//
////HINSTANCE DangQian_Obj;	//定义全局句柄(对象)
//
//int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
//
//	WNDCLASSEX wcx;
//	MSG msg;	//存储要处理的消息
//	BOOL bol;
//	hinst = hinstance;
//	//定义窗口类
//	//HWND hwnd;	//定义窗口句柄
//
//	wcx.lpszClassName = "窗口类名字";
//	wcx.cbSize = sizeof(wcx);	//计算窗口类的大小
//	wcx.style = CS_HREDRAW | CS_VREDRAW;	//样式: 窗口宽高发生变化时重画
//	wcx.lpfnWndProc = MainWndProc;	//指定窗口过程,专门用于处理消息
//	wcx.cbClsExtra = 0;	     	//不使用类内存
//	wcx.cbWndExtra = 0;		    //不使用窗口内存(附加数据时使用)
//	wcx.hInstance = hinstance;	//指定窗口类的句柄(对象)为当前句柄(类似this)
//	wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);	//窗口图标设置为默认加载,这里调用图标加载函数LoadIcon()
//	wcx.hCursor = LoadCursor(NULL, IDC_ARROW);		//鼠标箭头设置为默认的箭头,这里调用光标加载函数LoadCursor()
//	wcx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//窗口背景设置为白色(用画刷来画背景),调用API函数GetStockObject()
//	wcx.lpszMenuName = NULL;		//没有菜单
//	
//	//设定窗口类的小图标
//	wcx.hIconSm = (HICON)LoadImage(		//调用API函数,LoadImage
//		hinstance,			//句柄设置为当前句柄(对象,类似this)
//		MAKEINTRESOURCE(5),	//5号资源
//		IMAGE_ICON,			//5号资源里的图片
//		GetSystemMetrics(SM_CXSMICON),   //图标宽
//		GetSystemMetrics(SM_CYSMICON),	//图标高
//		LR_DEFAULTCOLOR				//颜色设置为默认颜色
//	);
//
//	if (!RegisterClassEx(&wcx))	//注册窗口类
//	{
//		//如果注册失败返回1
//		return 1;
//	}
//
//	//使用窗口类创建窗口,所有对象创建了之后都会得到一个句柄.
//	hwnd = CreateWindow(
//		"窗口类名字",
//		"标题",
//		WS_OVERLAPPEDWINDOW,  //样式设置为经典样式
//		CW_USEDEFAULT,	 //x坐标(默认)
//		CW_USEDEFAULT,	 //y坐标(默认)
//		CW_USEDEFAULT,	 //宽度(默认)
//		CW_USEDEFAULT,	 //高度(默认)
//		(HWND)NULL,		 //没有子窗口
//		(HMENU)NULL,	 //没有菜单
//		hinstance,		 //当前句柄(对象,类似this)
//		(LPVOID)NULL	 //创建窗口时没有数据
//	);
//
//	if (!hwnd)
//	{
//		return 1;	//如果窗口创建失败返回1
//	}
//	
//	ShowWindow(hwnd, nCmdShow);	//显示窗口(窗口有可能不显示,那么就需要下面的命令)
//	UpdateWindow(hwnd);	//立即显示窗口
//
//	while ((bol = GetMessage(&msg,(HWND)NULL,0,0)) != 0) //GetMessage函数为从消息队列里不停的获取消息存储到msg
//	{
//	//	printf("bol--------&d\n", bol);
//		TranslateMessage(&msg);		//翻译消息
//		DispatchMessage(&msg);	//转发消息给窗口过程函数(处理消息)
//	}
//
//	return msg.wParam;
//
//}
//
//
////窗口过程函数,用于处理消息(回调函数)
//LRESULT  CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//
//	//uMsg为窗口过程函数要处理的消息
//	switch (uMsg)
//	{
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	case WM_LBUTTONDOWN:
//		MessageBox(hwnd, "Hello 窗口！", "你好", MB_OK);
//		return 0;
//	default:
//		return DefWindowProc(hwnd, uMsg, wParam, lParam);
//	}
//
//
//}
//

#include "keyboard.h"


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
	WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);

	case WM_KEYDOWN:
		if (wParam == 'T')
			MessageBox(hwnd, L"T Pressed", L"T", MB_OK);
		else if (wParam == VK_ESCAPE)
			SendMessage(hwnd, WM_CLOSE, 0, 0);
		break;

	case WM_KEYUP:
		if (wParam == 'R')
			MessageBox(hwnd, L"R Pressed", L"R", MB_OK);
		break;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}



int test(HINSTANCE hInstance, int nCmdShow)
{
	LPCTSTR className = L"ClassName";
	WNDCLASSEX wc;

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = className;
	wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO);

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, L"Error registering class",
			L"Error", MB_OK | MB_ICONERROR);
		return 1;
	}

	HWND hwnd = CreateWindowEx(
		0,
		className,
		L"07 - Keyboard Input",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		300, 300,
		NULL,
		NULL,
		hInstance,
		NULL
		);

	if (!hwnd)
	{
		MessageBox(NULL, L"Error creating window",
			L"Error", MB_OK | MB_ICONERROR);
		return 1;
	}

	ShowWindow(hwnd, nCmdShow);

	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}
















































/*
bool vKey;
MSG msg;

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);

	case WM_KEYDOWN:
		if (wParam == 'T')
			std::cout << "hello";
		else if (wParam == VK_ESCAPE)
			SendMessage(hWnd, WM_CLOSE, 0, 0);
		break;

	case WM_KEYUP:
		if (wParam == 'R')
			MessageBox(hWnd, L"R Pressed", L"R", MB_OK);
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}


void watchKeyboard()
{

	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	};
	
	*/
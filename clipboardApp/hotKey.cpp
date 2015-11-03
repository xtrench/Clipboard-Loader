#include "hotKey.h"



void StartHotKey(HWND hwnd, std::vector<std::string> data)
{
	static size_t i = 0;



	if (RegisterHotKey(
		NULL,
		1,
		MOD_CONTROL | MOD_NOREPEAT,
		0x58))  /// 0x58 = x  0x56 = v
	{
		std::cout << "Hot Key CTRL+X: Inject next line into clipboard" << std::endl;
	}

	if (RegisterHotKey(
		NULL,
		2,
		MOD_CONTROL | MOD_NOREPEAT,
		0x5a))  /// 0x5a = z  0x56 = v
	{
		std::cout << "Hot Key CTRL+Z: Inject previous line into clipboard" << std::endl;
	}

	std::cout << "Current data in clipboard: " << std::endl << data[0] << " | [First Item]" << std::endl;


	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0) != 0)
	{
		if (msg.message == WM_HOTKEY)
		{
			if (msg.wParam == 1)
			{
				if (i < data.size() - 1)
					++i;
				else
					i = data.size() - 1;

				if (i > 0 && i < data.size()-1)
				{
					InjectToClipboard(hwnd, data[i]);
					std::cout << data[i] << std::endl;
				}
				else if (i == 0)
				{
					InjectToClipboard(hwnd, data[i]);
					std::cout << data[i] << " | [First Item]" << std::endl;
				}
				else if (i == data.size() - 1)
				{
					InjectToClipboard(hwnd, data[i]);
					std::cout << data[i] << " | [Last Item]" << std::endl;
				}
				else if (i >= data.size())
				{
					InjectToClipboard(hwnd, data[data.size() - 1]);
					std::cout << data[data.size() - 1] << " | [Last Item]" << std::endl;
				}
			}
			if (msg.wParam == 2)
			{
				if (i > 0)
					--i;

				if (i > 0 && i < data.size())
				{
					InjectToClipboard(hwnd, data[i]);
					std::cout << data[i] << std::endl;
				}
				else if (i == 0)
				{
					InjectToClipboard(hwnd, data[i]);
					std::cout << data[i] << " | [First Item]" << std::endl;
				}
				else if (i == data.size() - 1)
				{
					InjectToClipboard(hwnd, data[i]);
					std::cout << data[i] << " | [Last Item]" << std::endl;
				}
			
			}
		}
		
	}
}
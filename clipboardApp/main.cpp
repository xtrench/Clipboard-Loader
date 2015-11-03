#include <iostream>
#include "readFile.h"
#include <vector>
#include <string>
#include "hotKey.h"




int main(){





	std::vector<std::string> data = GetDataFromFile("data.txt");
	if (data.size() == 0)
	{
		std::cout << "\nEmpty Data.txt file\n";
	}
	else{
		HWND hwnd = GetDesktopWindow();
		InjectToClipboard(hwnd, data[0]);
		Sleep(100);
		StartHotKey(hwnd, data);

	}
	std::cout << "\nCreate a file named \"data,txt\" and fill it with text for pasting. Seperate items with a new line[enter]\n";


	system("pause");
	return 0;
}


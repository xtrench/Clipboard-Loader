#ifndef INJECTTOCLIPBOARD_H
#define INJECTTOCLIPBOARD_H

#include <iostream>
#include <string>
#include "windows.h"
void InjectToClipboard(HWND, std::string);
void toClipboard(HWND, const std::string &);


#endif
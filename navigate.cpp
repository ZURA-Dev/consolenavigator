#include <iostream>
#include <string>
#include <limits> 
#include <Windows.h>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <cctype>
#ifndef CONCOL
#define CONCOL
using namespace std;
	enum concol
	{
		black=0,
		dark_blue=1,
		dark_green=2,
		dark_aqua,dark_cyan=3,
		dark_red=4,
		dark_purple=5,dark_pink=5,dark_magenta=5,
		dark_yellow=6,
		dark_white=7,
		gray=8,
		blue=9,
		green=10,
		aqua=11,cyan=11,
		red=12,
		purple=13,pink=13,magenta=13,
		yellow=14,
		white=15
	};
#endif //CONCOL 

// <--- Prototype.
void SetColor(int foreground, int background)
{
	WORD consoleColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		//consoleColor = (csbi.wAttributes & 0xF0) + (ColorPicker & 0x0F);
		consoleColor =  (foreground + (background * 16));
		SetConsoleTextAttribute(hStdOut, consoleColor);
	}
}  //  End SetColor() 
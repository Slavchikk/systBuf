#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <strsafe.h>

LPWSTR ClipboardOutputText();


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{

	//HWND hwnd = GetConsoleWindow();
	while (TRUE)
	{
				LPSTR Data = ClipboardOutputText();
				TCHAR Alert[] = L"Вы нарушили автора, скопировав следующий текст:  ";
				TCHAR third[512];

				swprintf(third, sizeof third, L"%s%s", Alert, Data);

				if (Data != 0)
				{
					MessageBoxW(NULL, &third, L"внимание!!! Нарушение!!!", MB_OK | MB_ICONWARNING);
					ClipboardOutputText("0");
					//*Data = 0;
					//EmptyClipboard("0");
				}
			//	Sleep(6000);
				//CloseClipboard();
				

		//Sleep(1000);
	}


	return 0;
}


int ClipboardInputText(LPWSTR buffer)
{
	DWORD len;
	HANDLE hMen;
	len = wcslen(buffer) + 1;

	hMen = GlobalAlloc(GMEM_MOVEABLE, len * sizeof(LPWSTR));
	memcpy(GlobalLock(hMen), buffer, len * sizeof(LPWSTR));
	GlobalUnlock(hMen);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_UNICODETEXT, hMen);
	CloseClipboard();
	return 0;

}

TCHAR* ClipboardOutputText()
{
	TCHAR* Mess = NULL;
	OpenClipboard(NULL);
	HANDLE hClipBoard = GetClipboardData(CF_UNICODETEXT);
	Mess = (TCHAR*)GlobalLock(hClipBoard);
	GlobalUnlock(hClipBoard);

	EmptyClipboard();
	CloseClipboard();
	//MessageBox(NULL, Mess, L"Содержимое буфера обмена", MB_OK);
	return Mess;
}
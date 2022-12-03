#include <stdio.h>
#include <Windows.h>
#include <strsafe.h>


LPWSTR ClipboardOutputText();

TCHAR* ClipboardInputText(LPWSTR buffer)
{
	TCHAR* Mess = NULL;
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
	return Mess;

}


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{

	//HWND hwnd = GetConsoleWindow();
	while (1)
	{
		LPSTR Data = ClipboardOutputText();
		/*TCHAR Alert[] = L"Вы нарушили автора, скопировав следующий текст:  ";
		TCHAR third[512];*/
		ClipboardInputText(Data);
		/*swprintf(third, sizeof third, L"%s%s", Alert, Data);

		if (*Data != 0)
		{
			MessageBoxW(NULL, &third, L"внимание!!! Нарушение!!!", MB_OK | MB_ICONWARNING);
			ClipboardOutputText("");
		}*/
		Sleep(6000);
		//CloseClipboard(0);


		//Sleep(1000);
	}


	return 0;
}



TCHAR* ClipboardOutputText()
{
	TCHAR* Mess = NULL;
	OpenClipboard(NULL);
	HANDLE hClipBoard = GetClipboardData(CF_UNICODETEXT);
	Mess = (TCHAR*)GlobalLock(hClipBoard);
	GlobalUnlock(hClipBoard);
	CloseClipboard();
	EmptyClipboard();
	//MessageBox(NULL, Mess, L"Содержимое буфера обмена", MB_OK);
	return Mess;
}









/*int sqrtNum = 0;

	sqrtNum= atof(Mess);
	switch (sqrtNum)
	{
	case 1:
		Mess =L"один";
		break;
	case 2:
		Mess = L"два";
		break;
	case 3:
		Mess = L"два";
		break;
	case 4:
		Mess = L"два";
		break;
	case 5:
		Mess = L"два";
		break;
	case 6:
		Mess = L"два";
		break;
	case 7:
		Mess = L"два";
		break;
	case 8:
		Mess = L"два";
		break;
	case 9:
		Mess = L"два";
		break;

	default:
		Mess = L"не число";
		break;
	}*/
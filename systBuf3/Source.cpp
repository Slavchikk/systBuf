#include <stdio.h>
#include <Windows.h>





int ClipboardInputText(LPWSTR Mess)
{
	int sqrtNum = 0;

	sqrtNum = atof(Mess);
	switch (sqrtNum)
	{
	case 1:
		Mess = L"один";
		break;
	case 2:
		Mess = L"два";
		break;
	case 3:
		Mess = L"три";
		break;
	case 4:
		Mess = L"четыре";
		break;
	case 5:
		Mess = L"пять";
		break;
	case 6:
		Mess = L"шесть";
		break;
	case 7:
		Mess = L"семь";
		break;
	case 8:
		Mess = L"восемь";
		break;
	case 9:
		Mess = L"девять";
		break;

	default:
		Mess = L"не число";
		break;
	}

	DWORD len;
	HANDLE hMen;
	len = wcslen(Mess) + 1;

	hMen = GlobalAlloc(GMEM_MOVEABLE, len * sizeof(LPWSTR));
	memcpy(GlobalLock(hMen), Mess, len * sizeof(LPWSTR));
	GlobalUnlock(hMen);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_UNICODETEXT, hMen);
	CloseClipboard();
	return 0;

}

LPWSTR ClipboardOutputText()
{
	LPWSTR Mess = NULL;
	LPWSTR MessSave = NULL;
	OpenClipboard(NULL);
	HANDLE hClipBoard = GetClipboardData(CF_UNICODETEXT);
	Mess = (LPWSTR)GlobalLock(hClipBoard);
	MessSave = (LPWSTR)GlobalLock(hClipBoard);
	GlobalUnlock(hClipBoard);
	CloseClipboard();
	int sqrtNum = 0;

	sqrtNum = atof(Mess);
	switch (sqrtNum)
	{
	case 1:
		Mess = L"один";
		break;
	case 2:
		Mess = L"два";
		break;
	case 3:
		Mess = L"три";
		break;
	case 4:
		Mess = L"четыре";
		break;
	case 5:
		Mess = L"пять";
		break;
	case 6:
		Mess = L"шесть";
		break;
	case 7:
		Mess = L"семь";
		break;
	case 8:
		Mess = L"восемь";
		break;
	case 9:
		Mess = L"девять";
		break;

	default:
		Mess = L"не число";
		break;
	}
	
	MessageBox(NULL, Mess, L"Содержимое буфера обмена", MB_OK);
	
	return MessSave;
}
int main()
{
	LPWSTR  Message = ClipboardOutputText();
	

	ClipboardInputText(Message);
}



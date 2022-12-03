#include <stdio.h>
#include <Windows.h>

int main()
{
	LPWSTR  Message = L"�����-���� �����";
	//ClipboardInputText(Message);
	ClipboardOutputText();
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

int ClipboardOutputText()
{
	LPWSTR Mess = NULL;
	OpenClipboard(NULL);
	HANDLE hClipBoard = GetClipboardData(CF_UNICODETEXT);
	Mess = (LPWSTR)GlobalLock(hClipBoard);
	GlobalUnlock(hClipBoard);
	CloseClipboard();
	MessageBox(NULL, Mess, L"���������� ������ ������", MB_OK);
	return 0;
}
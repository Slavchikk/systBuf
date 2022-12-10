#include <stdio.h>
#include <Windows.h>





int ClipboardInputText(LPWSTR Mess)
{
	int sqrtNum = 0;

	sqrtNum = atof(Mess);
	switch (sqrtNum)
	{
	case 1:
		Mess = L"����";
		break;
	case 2:
		Mess = L"���";
		break;
	case 3:
		Mess = L"���";
		break;
	case 4:
		Mess = L"������";
		break;
	case 5:
		Mess = L"����";
		break;
	case 6:
		Mess = L"�����";
		break;
	case 7:
		Mess = L"����";
		break;
	case 8:
		Mess = L"������";
		break;
	case 9:
		Mess = L"������";
		break;

	default:
		Mess = L"�� �����";
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
		Mess = L"����";
		break;
	case 2:
		Mess = L"���";
		break;
	case 3:
		Mess = L"���";
		break;
	case 4:
		Mess = L"������";
		break;
	case 5:
		Mess = L"����";
		break;
	case 6:
		Mess = L"�����";
		break;
	case 7:
		Mess = L"����";
		break;
	case 8:
		Mess = L"������";
		break;
	case 9:
		Mess = L"������";
		break;

	default:
		Mess = L"�� �����";
		break;
	}
	
	MessageBox(NULL, Mess, L"���������� ������ ������", MB_OK);
	
	return MessSave;
}
int main()
{
	LPWSTR  Message = ClipboardOutputText();
	

	ClipboardInputText(Message);
}



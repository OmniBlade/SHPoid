#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <tchar.h>
#include "resource.h"

class NewDialog
{
public:
    static INT_PTR CALLBACK NewDialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        NewDialog *pThis = reinterpret_cast<NewDialog*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

        if (!pThis)
        {
            if (uMsg == WM_INITDIALOG)
            {
                pThis = reinterpret_cast<NewDialog*>(lParam);
                pThis->m_hwnd = hwnd;
                SetWindowLongPtr(hwnd, GWLP_USERDATA, lParam);
            }
            else
            {
                return 0; //let system deal with message
            }
        }
        //forward message to member function handler
        return pThis->HandleDialogProc(uMsg, wParam, lParam);
    }

    INT_PTR Create(const int id, const HWND hParent = 0)
    {
        return DialogBoxParam(GetModuleHandle(0),
                              MAKEINTRESOURCE(id),
                              hParent,
                              NewDialogProc,
                              reinterpret_cast<LPARAM>(this));
    }

    INT_PTR HandleDialogProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        //handle messages normally
        if (uMsg == WM_COMMAND)
        {
            if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
            {
                EndDialog(m_hwnd, LOWORD(wParam));
                return 1;
            }
        }
        return 0;
    }

protected:
    HWND m_hwnd;
};

#endif // NEWDIALOG_H

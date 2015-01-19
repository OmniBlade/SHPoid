#ifndef ROTATEARBDIALOG_H
#define ROTATEARBDIALOG_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <tchar.h>
#include "resource.h"

class RotateArbDialog
{
public:
    static INT_PTR CALLBACK RotateArbDialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        RotateArbDialog *pThis = reinterpret_cast<RotateArbDialog*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

        if (!pThis)
        {
            if (uMsg == WM_INITDIALOG)
            {
                pThis = reinterpret_cast<RotateArbDialog*>(lParam);
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
                              RotateArbDialogProc,
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

#endif // ROTATEARBDIALOG_H

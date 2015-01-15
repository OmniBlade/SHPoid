#ifndef SHPOIDBASEWINDOW_H
#define SHPOIDBASEWINDOW_H

#include <windows.h>
#include <windowsx.h>

#include <Resource.h>

template <class DERIVED_TYPE>
class SHPoidBaseWindow
{
public:
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        DERIVED_TYPE *pThis = NULL;

        if (uMsg == WM_NCCREATE)
        {
            CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam;
            pThis = (DERIVED_TYPE*)pCreate->lpCreateParams;
            SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pThis);

            pThis->m_hwnd = hwnd;
        }
        else
        {
            pThis = (DERIVED_TYPE*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
        }
        if (pThis)
        {
            return pThis->HandleMessage(uMsg, wParam, lParam);
        }
        else
        {
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }
    }

    SHPoidBaseWindow() : m_hwnd(NULL) { }

    BOOL Create(LPSTR lpWindowName,
                DWORD dwStyle,
                DWORD dwExStyle = 0,
                int x = CW_USEDEFAULT,
                int y = CW_USEDEFAULT,
                int nWidth = CW_USEDEFAULT,
                int nHeight = CW_USEDEFAULT,
                HWND hWndParent = HWND_DESKTOP,
                HMENU hMenu = 0)
    {
        WNDCLASS wc = {0};

        wc.lpfnWndProc   = DERIVED_TYPE::WindowProc;
        wc.hInstance     = GetModuleHandle(NULL);
        wc.lpszClassName = ClassName();

        RegisterClass(&wc);

        m_hwnd = CreateWindowEx(dwExStyle,
                                ClassName(),
                                lpWindowName,
                                dwStyle,
                                x, y,
                                nWidth,
                                nHeight,
                                hWndParent,
                                hMenu,
                                GetModuleHandle(NULL),
                                this);

        return (m_hwnd ? TRUE : FALSE);
    }

    HWND Window() const { return m_hwnd; }

protected:
    virtual LPSTR  ClassName() const = 0;
    virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;

    HWND m_hwnd;
};

#endif // SHPOIDBASEWINDOW_H

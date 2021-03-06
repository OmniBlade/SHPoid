#ifndef MAINTOOLBAR_H
#define MAINTOOLBAR_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

class MainToolbar
{
    public:
        void Create(HWND hwnd, HINSTANCE hInstance);
        HWND GetHandle();

    protected:
        HWND m_hToolbar;
        HIMAGELIST m_hImageList;
};

#endif // MAINTOOLBAR_H

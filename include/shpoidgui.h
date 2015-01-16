#ifndef SHPOIDGUI_H
#define SHPOIDGUI_H

#include <commctrl.h>

class SHPoidGUI
{
    public:
        SHPoidGUI();
        virtual ~SHPoidGUI();
        void Create(HWND hwnd, HINSTANCE hInstance);
        HWND GetMainToolbarHandle()
        {
            return m_hMainToolbar;
        }

    protected:
    private:
        HWND m_hMainToolbar;

        void AddButtons(HWND hWndToolbar, HINSTANCE hInstance);
        void CreateToolbar(HWND hwnd, HINSTANCE hInstance);
};

#endif // SHPOIDGUI_H
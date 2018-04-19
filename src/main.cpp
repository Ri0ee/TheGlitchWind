#include <iostream>
#include "windows.h"
#include "time.h"
#include <vector>

std::vector<HWND> window_handles;

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
    if(IsWindowVisible(hwnd))
        window_handles.push_back(hwnd);
    return TRUE;
}

int main()
{
    int display_width = GetSystemMetrics(SM_CXSCREEN);
    int display_height = GetSystemMetrics(SM_CYSCREEN);

    int repeat_count = 0;

    while(true)
    {
        repeat_count++;
        window_handles.clear();
        EnumWindows(EnumWindowsProc, NULL);

        for(int i = 0; i < window_handles.size(); i++)
        {
            srand((int)clock());
            MoveWindow(window_handles[i], rand() % display_width, rand() % display_height, 500, 500, true);
        }

        Sleep(1500);
        if(repeat_count == 10)
            return 0;
    }

    return 0;
}

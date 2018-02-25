#include <stdio.h>
#include <stdlib.h>

#define _WIN32_WINNT 0x0500
#include <windows.h>

void clic_ici(int x, int y)
{
    INPUT i[2];
    memset(i, 0, sizeof(i));
    i[0].type = i[1].type = INPUT_MOUSE;
    i[0].mi.dx = (65535. / (double)GetSystemMetrics(SM_CXSCREEN)) * x;
    i[0].mi.dy = (65535. / (double)GetSystemMetrics(SM_CYSCREEN)) * y;
    i[0].mi.dwFlags = MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_LEFTDOWN;
    i[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(2, i, sizeof(INPUT));
}

void clic_charge()
{
    clic_ici( 100, 550);
}

int main(void)
{
    int delai_en_secondes =  5;
    int position_x = 300, position_y = 600;
    while(1){
        clic_charge();
        Sleep(delai_en_secondes * 1000);
    }
    return 0;
}

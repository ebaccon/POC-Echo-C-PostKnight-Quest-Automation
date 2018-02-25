#include <stdio.h>
#include <stdlib.h>

#define _WIN32_WINNT 0x0500
#include <windows.h>

void click_here(int x, int y)
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

void click_charge()
{
    click_here( 100, 560);
}

void click_shield()
{
    click_here( 175, 560);
}

void click_potion()
{
    click_here( 250, 560);
}

void click_close_purpose_heal()
{
    click_here( 175, 450);
}

void click_go()
{
    click_here( 250, 400);
}

// Fight while loop time and delay
void fight(int time, int delay)
{
    int time_to_fight = 0;
    while(time_to_fight < time){
        time_to_fight++;
        click_charge();
        click_shield();
        click_potion();
        Sleep(delay);
    }
}

void lauch_fight(int loop, int delay)
{
    // Start of fight while 10 loop of 6 seconds for exemple
        fight(loop, delay);
        Sleep(delay);
        // Close the pop-up and dialog
        click_close_purpose_heal();
        click_close_purpose_heal();
        click_close_purpose_heal();
        click_close_purpose_heal();
        Sleep(delay);
        // Click on GO button
        click_go();
        Sleep(delay);
        // Start of fight while 10 loop of 6 seconds for exemple
        fight(loop, delay);
        Sleep(delay);
        // Close win pop-up
        click_close_purpose_heal();
        Sleep(delay);
        Sleep(delay);
        Sleep(delay);
}

int main(void)
{
    int const delay_in_ms =  6 * 1000; // The delay must be in ms
    int const loop =  10; // The number of loop
    while(1){
        // TODO Switch to screen in the left

        // TODO launch the selection of quest

        // TODO Click on the quest you want

        // Launch fight
        lauch_fight(loop, delay_in_ms);
    }
    return 0;
}

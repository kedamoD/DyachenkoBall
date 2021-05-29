
#include "TXLib.h"

void MoveBall_1();

int main()
    {
    txCreateWindow (800, 600);

    MoveBall_1();

    return(0);
    }

void MoveBall_1()
    {
    int x  = 100, y  = 100,
        vx = 5,   vy = 3;

    int dt = 1;

    txSetColor (RGB (x, y, 128), 2);
    txSetFillColor (RGB (x/2, y/2, 128));

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txCircle (x, y, 20);
        txSetColor (RGB (x, 128, y), 2);
        txSetFillColor (RGB (x/3, 50, y/3));

        x += vx * dt;
        y += vy * dt;

        if (x > 780)
            {
            vx = -vx;
            x  = 780;
            }

        if (y > 580)
            {
            vy = -vy;
            y  = 580;
            }

        if (x < 20)
            {
            vx = -vx;
            x  = 20;
            }

        if (y < 20)
            {
            vy = -vy;
            y  = 20;
            }

        if (txGetAsyncKeyState (VK_RIGHT)) vx++; //увеличение скорости по x
        if (txGetAsyncKeyState (VK_LEFT))  vx--; //уменьшаем скорость по x
        if (txGetAsyncKeyState (VK_UP))    vy--; //уменьшаем скорость по y
        if (txGetAsyncKeyState (VK_DOWN))  vy++; //увеличиваем скорость по y

        if (txGetAsyncKeyState (VK_SPACE))  vx = vy = 0; //нажатие пробела и остановка шарика

        txSleep (10);
        }
    }

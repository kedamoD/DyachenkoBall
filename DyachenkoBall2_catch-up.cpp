
#include "TXLib.h"

void MoveBall_1();
void PaintBall_1 (int x1, int y1, int ColorBall, int ColorBallFill);
void PaintBall_2 (int x2, int y2);

int main()
    {
    txCreateWindow (800, 600);

    MoveBall_1();

    return(0);
    }

void PaintBall_1 (int x1, int y1, int ColorBall, int ColorBallFill)
    {
    txSetColor (ColorBall, 2);
    txSetFillColor (ColorBallFill);
    txCircle (x1, y1, 20);
    }

void PaintBall_2 (int x2, int y2)
    {
    txSetColor (TX_LIGHTGREEN, 2);
    txSetFillColor (TX_GREEN);
    txCircle (x2, y2, 20);
    }

void MoveBall_1()
    {
    int x1  = 100, y1  = 100,
        vx1 = 5,   vy1 = 3;

    int x2  = 300, y2  = 100,
        vx2 = 3,   vy2 = 8;

    int ColorBall = TX_LIGHTMAGENTA, ColorBallFill = TX_MAGENTA;

    int dt = 1;

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        PaintBall_1 (x1, y1, ColorBall, ColorBallFill);
        PaintBall_2 (x2, y2);

        x1 += vx1 * dt;
        y1 += vy1 * dt;

        if (x1 > 780)
            {
            vx1 = -vx1;
            x1  = 780;
            }

        if (y1 > 580)
            {
            vy1 = -vy1;
            y1  = 580;
            }

        if (x1 < 20)
            {
            vx1 = -vx1;
            x1  = 20;
            }

        if (y1 < 20)
            {
            vy1 = -vy1;
            y1  = 20;
            }

        x2 += vx2 * dt;
        y2 += vy2 * dt;

        if (x2 > 780)
            {
            vx2 = -vx2;
            x2  = 780;
            }

        if (y2 > 580)
            {
            vy2 = -vy2;
            y2  = 580;
            }

        if (x2 < 20)
            {
            vx2 = -vx2;
            x2  = 20;
            }

        if (y2 < 20)
            {
            vy2 = -vy2;
            y2  = 20;
            }

        if (txGetAsyncKeyState (VK_RIGHT)) vx1++; //увеличение скорости по x
        if (txGetAsyncKeyState (VK_LEFT))  vx1--; //уменьшаем скорость по x
        if (txGetAsyncKeyState (VK_UP))    vy1--; //уменьшаем скорость по y
        if (txGetAsyncKeyState (VK_DOWN))  vy1++; //увеличиваем скорость по y

        if (txGetAsyncKeyState (VK_SPACE))  vx1 = vy1 = 0; //нажатие пробела и остановка шарика

        if (txGetAsyncKeyState (VK_F1))
                {
                ColorBall = TX_LIGHTBLUE;
                ColorBallFill = TX_BLUE;
                }

        if (txGetAsyncKeyState (VK_F2))
                {
                ColorBall = TX_PINK;
                ColorBallFill = TX_ORANGE;
                }

        if (txGetAsyncKeyState (VK_F3))
                {
                ColorBall = TX_LIGHTMAGENTA;
                ColorBallFill = TX_MAGENTA;
                }


        txSleep (10);
        }
    }

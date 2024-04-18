#include <graphics.h>

// Function to draw a circle using Mid-Point Circle Drawing Algorithm
void drawCircle(int xc, int yc, int radius) {
    int gd = DETECT, gm;
    int x = 0, y = radius;
    int p = 1 - radius;
    
//    initgraph(&gd, &gm, "");
//    int width=GetSystemMetrics(SM_CXSCREEN);
//	int height=GetSystemMetrics(SM_CYSCREEN);
	initwindow(800,600,"MidPoint Circle Algorithm",WHITE);

    // Plot the initial point
    putpixel(xc + x, yc - y, WHITE);

    // Plot other points
    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
    }
    getch();
    closegraph();
}

int main() {
    drawCircle(200,220,90);
    return 0;
}


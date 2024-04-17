#include <graphics.h>

// Function to draw a circle using Mid-Point Circle Drawing Algorithm
void drawCircle(int xc, int yc, int radius) {
    int gd = DETECT, gm;
    int x = 0, y = radius;
    int p = 1 - radius;
    
    initgraph(&gd, &gm, "");

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
    int xc=300, yc=300, radius=50;
    drawCircle(xc, yc, radius);
    return 0;
}


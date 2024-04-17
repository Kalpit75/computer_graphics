#include <stdio.h>
#include <graphics.h>
#include <math.h>

void drawCircle(int xc, int yc, int radius) {
    int gd = DETECT, gm;
    int x, y;
    float theta, dTheta = 1.0 / radius;

    initgraph(&gd, &gm, "");

    for (theta = 0; theta <= 360; theta += dTheta) {
        x = xc + radius * cos(theta * M_PI / 180);
        y = yc + radius * sin(theta * M_PI / 180);
        putpixel(x, y, WHITE);
    }

    getch();
    closegraph();
}

int main() {
    int xc = 300, yc = 200, radius = 100;
    drawCircle(xc, yc, radius);
    return 0;
}


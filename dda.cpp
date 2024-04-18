#include <stdio.h>
#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    int x1=100,y1=300,x2=500,y2=400;
    
    int dx = x2 - x1, dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = (float)dx / steps, yIncrement = (float)dy / steps;
    float x = x1, y = y1;

//    initgraph(&gd, &gm, "");
	initwindow(800,600,"DDA",WHITE);

    putpixel(x, y, WHITE);
    
    for (int k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        putpixel((int)(x + 0.5), (int)(y + 0.5), WHITE);
    }

    getch();
    closegraph();
    return 0;
}

